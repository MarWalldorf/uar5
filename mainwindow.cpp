#include "mainwindow.h"
#include <QDataStream>
#include <QInputDialog>
#include <QMessageBox>
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    _Menager = new MenagerSymulacji(FeedbackLoop((ARX_Model(std::vector<double>(),
                                                            std::vector<double>())),
                                                 Regulator_PID(0, 0, 0, 0),
                                                 Generator()),
                                    this);

    ui->setupUi(this);


    graph1 = new graph(2);
    graph1->getSeries(0)->setName("wartosc zadana");
    graph1->getSeries(1)->setName("wartosc regulowana");
    graph1->setAxisTitles("Czas [s]", "Wartość");
    graph1->PutInFrame(ui->Frame_1);

    graph2 = new graph();
    graph2->getSeries()->setName("sygnał sterujący");
    graph2->setAxisTitles("Czas [s]", "Wartość");
    graph2->PutInFrame(ui->Frame_2);

    graph3 = new graph(3);
    graph3->getSeries(0)->setName("Kp");
    graph3->getSeries(1)->setName("Ti");
    graph3->getSeries(2)->setName("Td");
    graph3->setAxisTitles("Czas [s]", "Wartość");
    graph3->PutInFrame(ui->Frame_3);

    graph4 = new graph();
    graph4->getSeries()->setName("Uchyb");
    graph4->setAxisTitles("Czas [s]", "Wartość");
    graph4->PutInFrame(ui->Frame_4);

    connect(_Menager, &MenagerSymulacji::UpdateSim, this, &MainWindow::Symuluj);
    connect(_Menager, &MenagerSymulacji::TimerStateChanged,
            this,
            [this](bool running)
            {
                ui->button_Simulation_StartStop->setText(running ? "STOP" : "START");
            });

    networkManager = new NetworkManager(this);
    connect(networkManager, &NetworkManager::dataReceived, this, &MainWindow::onNetworkDataReceived);
    connect(networkManager,
            &NetworkManager::connectionEstablished,
            this,
            &MainWindow::onConnectionEstablished);
    connect(networkManager, &NetworkManager::connectionLost, this, &MainWindow::onConnectionLost);


    connect(_Menager,
            &MenagerSymulacji::SendNetworkU,
            this,
            [this](double u, double wz)
            {
                if (networkManager->getCurrentRole() != NetworkRole::Controller)
                    return;

                QByteArray packet;
                QDataStream out(&packet, QIODevice::WriteOnly);

                out << (quint8)2 << u << wz;

                networkManager->sendData(packet);
            });

    initControlLists();
    updateUIMode();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_button_ARX_settings_clicked()
{
    if (ARX_Settings::counter == 0) {
        _ARX_Settings_Dialog = new ARX_Settings(_Menager->GetARX(), this);
        _ARX_Settings_Dialog->setAttribute(Qt::WA_DeleteOnClose);

        connect(_ARX_Settings_Dialog, &QDialog::finished, this, [this]() {
            QTimer::singleShot(100, this, [this]() {
                if (networkManager->getCurrentRole() != NetworkRole::Stationary) {


                    _Menager->setUseGen(ui->checkBox_enable_generator->isChecked());

                    QByteArray data;
                    QDataStream out(&data, QIODevice::WriteOnly);
                    out << (quint8) 1 << _Menager->Serialize().toJson(QJsonDocument::Compact);
                    networkManager->sendData(data);
                }
            });
        });

        _ARX_Settings_Dialog->show();
    }
}

void MainWindow::on_button_summit_settings_clicked()
{
    int interval_ms = ui->spinBox->value();
    TimeStep = static_cast<double>(interval_ms) / 1000.0;
    _Menager->setInterval(interval_ms);

    _Menager->SetKp(ui->doubleSpinBox_2->value());
    _Menager->SetTi(ui->doubleSpinBox_3->value());
    _Menager->SetTd(ui->doubleSpinBox_4->value());
    _Menager->SetGeneratorAmplitude(ui->doublespin_amp->value());

    double okres_s = ui->spin_period->value();
    int dyskretne_T = qMax(1, static_cast<int>(std::round(okres_s / TimeStep)));
    _Menager->SetGeneratorParameters(dyskretne_T);

    _Menager->SetGeneratorShift(ui->doublespin_const->value());
    _Menager->SetGeneratorPulseWidth(ui->doubleSpin_Fill->value());
    _Menager->setUseGen(ui->checkBox_enable_generator->isChecked());
    _Menager->setWZadane(ui->doubleSpinBox->value());
    _Menager->setGraphTime(ui->spinBox_graph_time->value());
    graph::setSeriesMaxLen(qMax(10, (int) (ui->spinBox_graph_time->value() / TimeStep)));


    if (networkManager->getCurrentRole() != NetworkRole::Stationary) {
        QByteArray data;
        QDataStream out(&data, QIODevice::WriteOnly);


        out << (quint8) 1 << _Menager->Serialize().toJson(QJsonDocument::Compact);
        networkManager->sendData(data);


        if (networkManager->getCurrentRole() == NetworkRole::Controller) {
            ui->label_network_status->setText("Tryb: Sieciowy (REGULATOR) (wysłano PID/GEN)");
        } else if (networkManager->getCurrentRole() == NetworkRole::Object) {
            ui->label_network_status->setText("Tryb: Sieciowy (OBIEKT) (wysłano wymuszone ARX)");
        }
    }
}

void MainWindow::onNetworkDataReceived(QByteArray data)
{
    if (_Menager->getRole() == SimRole::Stationary)
        return;
    if (networkManager->getCurrentRole() == NetworkRole::Stationary)
        return;
    QDataStream in(&data, QIODevice::ReadOnly);
    quint8 type;
    in >> type;

    if (type == 1) {
        QByteArray json;
        in >> json;
        _Menager->deserialize(QJsonDocument::fromJson(json));
        UpdateInputs();
    } else if (type == 2 && networkManager->getCurrentRole() == NetworkRole::Object) {
        double u, wz;
        in >> u >> wz;
        networkSimulationActive = true;
        double y = _Menager->CalculateARX_Network(u, wz);
        QByteArray resp;
        QDataStream out(&resp, QIODevice::WriteOnly);
        out << (quint8) 3 << y;
        networkManager->sendData(resp);
        Symuluj({wz, y, u, 0, 0, 0, 0});
    } else if (type == 3 && networkManager->getCurrentRole() == NetworkRole::Controller) {
        double y;
        in >> y;
        _Menager->ReceiveNetworkY(y);
    }
    else if (type == 4)
    {
        bool running;
        in >> running;

        _Menager->setTimerState(running);
    }
}

void MainWindow::on_button_network_setup_clicked()
{
    if (networkManager->getCurrentRole() != NetworkRole::Stationary) {
        if (QMessageBox::question(this, "Rozłącz", "Wrócić do trybu stacjonarnego?")
            == QMessageBox::Yes) {


            bool wasRunning = _Menager->GetRunningState();
            double saved_u = _Menager->GetLastU();
            double saved_y = _Menager->GetLastY();
            double saved_e = _Menager->GetCurrentE();
            double saved_wz = _Menager->GetCurrentWz();
            double saved_integral = _Menager->GetIntegral();

            _Menager->setTimerState(false);
            networkManager->disconnectNetwork();


            updateUIMode();
            UpdateInputs();


            _Menager->SetLastU(saved_u);
            _Menager->SetLastY(saved_y);
            _Menager->SetCurrentE(saved_e);
            _Menager->SetCurrentWz(saved_wz);

            _Menager->SetIntegral(saved_integral);
            _Menager->SetLastError(saved_e);
            _Menager->ForceUpdateLastY(saved_y);

            _Menager->UpdateFeedbackLoopState(saved_y, saved_u, saved_e, saved_wz);
            _Menager->RestoreARXState(saved_u, saved_y);

            if (wasRunning) {
                QTimer::singleShot(50, this, [this]() {
                    _Menager->setTimerState(true);
                    ui->button_Simulation_StartStop->setText("STOP");
                });
            } else {
                ui->button_Simulation_StartStop->setText("START");
            }
        }
        return;
    }

    QStringList items{"Regulator (Serwer)", "Obiekt (Klient)"};
    bool ok;
    QString item = QInputDialog::getItem(this, "Sieć", "Rola:", items, 0, false, &ok);
    if (ok) {

        _Menager->setTimerState(false);


        if (item.contains("Regulator"))
            networkManager->startAsServer(12345);
        else {
            QString ip = QInputDialog::getText(this, "IP", "Adres:", QLineEdit::Normal, "127.0.0.1", &ok);
            if (ok)
                networkManager->connectToServer(ip, 12345);
        }
    }
}

void MainWindow::onConnectionEstablished(QString info)
{


    updateUIMode();


    QByteArray data;
    QDataStream out(&data, QIODevice::WriteOnly);
    out << (quint8) 1 << _Menager->Serialize().toJson(QJsonDocument::Compact);
    networkManager->sendData(data);


    QTimer::singleShot(100, this, [this]() {

        ui->label_network_status->setText("Tryb: Sieciowy - gotowy");
    });
}

void MainWindow::UpdateInputs()
{
    this->blockSignals(true);
    ui->doubleSpinBox_2->setValue(_Menager->getKp());
    ui->doubleSpinBox_3->setValue(_Menager->getTi());
    ui->doubleSpinBox_4->setValue(_Menager->getTd());
    ui->spinBox->setValue(_Menager->getInterval());
    ui->doubleSpinBox->setValue(_Menager->getWz());
    ui->doublespin_amp->setValue(_Menager->getAmplitude());
    ui->doublespin_const->setValue(_Menager->getShift());
    ui->doubleSpin_Fill->setValue(_Menager->getPulseWidth());
    ui->checkBox_enable_generator->setChecked(_Menager->getUseGen());
    ui->spinBox_graph_time->setValue(_Menager->getGraphTime());
    ui->button_generator_type->setText(_Menager->getGenType() ? "Square" : "Sin");
    ui->button_integral_type->setText(_Menager->getIType() ? "Pod" : "Przed");
    this->blockSignals(false);

    TimeStep = (double) _Menager->getInterval() / 1000.0;
    ui->spin_period->setValue((int) (_Menager->getPeriod() * TimeStep));
    graph::setSeriesMaxLen(qMax(10, (int) (_Menager->getGraphTime() / TimeStep)));

    if (networkManager->getCurrentRole() == NetworkRole::Controller) {
        ui->label_network_status->setText("Tryb: Sieciowy (REGULATOR) (odebrano ARX)");
    } else if (networkManager->getCurrentRole() == NetworkRole::Object) {
        ui->label_network_status->setText("Tryb: Sieciowy (OBIEKT) (odebrano PID/GEN)");
    }
}


void MainWindow::initControlLists()
{
    regulatorControls = {ui->doubleSpinBox_2,
                         ui->doubleSpinBox_3,
                         ui->doubleSpinBox_4,
                         ui->doubleSpinBox,
                         ui->doublespin_amp,
                         ui->doublespin_const,
                         ui->doubleSpin_Fill,
                         ui->spin_period,
                         ui->spinBox,
                         ui->spinBox_graph_time,
                         ui->button_Simulation_StartStop,
                         ui->button_generator_type,
                         ui->button_integral_type,
                         ui->checkBox_enable_generator,
                         ui->button_summit_settings,
                         ui->button_clear_memory,
                         ui->calka_reset};
    arxControls = {ui->button_ARX_settings};
}

void MainWindow::updateUIMode()
{
    bool wasRunning = _Menager->GetRunningState();

    NetworkRole role = networkManager->getCurrentRole();
    if (role == NetworkRole::Controller) {
        _Menager->setRole(SimRole::Regulator);
    } else if (role == NetworkRole::Object) {
        _Menager->setRole(SimRole::Object);
    } else {
        _Menager->setRole(SimRole::Stationary);
    }

    bool isReg = (role == NetworkRole::Controller || role == NetworkRole::Stationary);
    bool isObj = (role == NetworkRole::Object || role == NetworkRole::Stationary);
    for (QWidget *w : regulatorControls)
        if (w)
            w->setEnabled(isReg);
    for (QWidget *w : arxControls)
        if (w)
            w->setEnabled(isObj);

    QString status = "Tryb: ";
    if (role == NetworkRole::Stationary) {
        status += "Stacjonarny";
        ui->label_network_status->setStyleSheet("color: black;");
    } else if (role == NetworkRole::Controller) {
        status += "Sieciowy (REGULATOR)";
        ui->label_network_status->setStyleSheet("color: green; font-weight: bold;");
    } else {
        status += "Sieciowy (OBIEKT)";
        ui->label_network_status->setStyleSheet("color: #00BFFF; font-weight: bold;");
    }
    ui->label_network_status->setText(status);
}

void MainWindow::Symuluj(std::array<double, 7> out)
{
    currentTime += TimeStep;
    graph1->AppendSeries(0, currentTime, out[0]);
    graph1->AppendSeries(1, currentTime, out[1]);
    graph2->AppendSeries(currentTime, out[2]);
    graph3->AppendSeries(0, currentTime, out[3]);
    graph3->AppendSeries(1, currentTime, out[4]);
    graph3->AppendSeries(2, currentTime, out[5]);
    graph4->AppendSeries(currentTime, out[6]);
}

void MainWindow::on_button_Simulation_StartStop_clicked()
{
    bool s = (ui->button_Simulation_StartStop->text() == "START");


    _Menager->setTimerState(s);


    if (networkManager->getCurrentRole() != NetworkRole::Stationary)
    {
        QByteArray data;
        QDataStream out(&data, QIODevice::WriteOnly);

        out << (quint8)4 << s;

        networkManager->sendData(data);
    }
}
void MainWindow::on_button_generator_type_clicked()
{
    bool currentlySin = (ui->button_generator_type->text() == "Sin");
    if (currentlySin) {
        _Menager->SetGeneratorType(true);
        ui->button_generator_type->setText("Square");
    } else {
        _Menager->SetGeneratorType(false);
        ui->button_generator_type->setText("Sin");
    }
}

void MainWindow::on_button_integral_type_clicked()
{
    bool currentlyPod = (ui->button_integral_type->text() == "Pod");
    if (currentlyPod) {
        _Menager->SetIType(false);
        ui->button_integral_type->setText("Przed");
    } else {
        _Menager->SetIType(true);
        ui->button_integral_type->setText("Pod");
    }
}

void MainWindow::on_button_reset_clicked()
{
    _Menager->setTimerState(false);
    ui->button_Simulation_StartStop->setText("START");
    _Menager->Reset();
    currentTime = 0;
    graph1->ClearSeries();
    graph2->ClearSeries();
    graph3->ClearSeries();
    graph4->ClearSeries();
}

void MainWindow::on_button_save_clicked()
{
    QString f = QFileDialog::getSaveFileName(this, "Zapis", "", "JSON (*.json)");
    if (!f.isEmpty()) {
        QFile file(f);
        if (file.open(QIODevice::WriteOnly))
            file.write(_Menager->Serialize().toJson());
    }
}

void MainWindow::on_button_load_clicked()
{
    QString f = QFileDialog::getOpenFileName(this, "Wczytaj", "", "JSON (*.json)");
    if (!f.isEmpty()) {
        QFile file(f);
        if (file.open(QIODevice::ReadOnly)) {

            _Menager->deserialize(QJsonDocument::fromJson(file.readAll()));
            UpdateInputs();


            if (networkManager->getCurrentRole() != NetworkRole::Stationary) {
                QByteArray data;
                QDataStream out(&data, QIODevice::WriteOnly);
                out << (quint8) 1 << _Menager->Serialize().toJson(QJsonDocument::Compact);
                networkManager->sendData(data);

                QString roleName = (networkManager->getCurrentRole() == NetworkRole::Controller)
                                       ? "REGULATOR"
                                       : "OBIEKT";
                ui->label_network_status->setText("Tryb: Sieciowy (" + roleName
                                                  + ") (wysłano JSON)");
            }
        }
    }
}

void MainWindow::onConnectionLost()
{
    bool wasRunning = _Menager->GetRunningState();


    double saved_u = _Menager->GetLastU();
    double saved_y = _Menager->GetLastY();
    double saved_e = _Menager->GetCurrentE();
    double saved_wz = _Menager->GetCurrentWz();
    double saved_integral = _Menager->GetIntegral();


    networkManager->disconnectNetwork();



    updateUIMode();
    UpdateInputs();


    _Menager->SetLastU(saved_u);
    _Menager->SetLastY(saved_y);
    _Menager->SetCurrentE(saved_e);
    _Menager->SetCurrentWz(saved_wz);

    _Menager->SetIntegral(saved_integral);
    _Menager->SetLastError(saved_e);
    _Menager->ForceUpdateLastY(saved_y);

    _Menager->UpdateFeedbackLoopState(saved_y, saved_u, saved_e, saved_wz);
    _Menager->RestoreARXState(saved_u, saved_y);


    if (wasRunning) {
        _Menager->setTimerState(true);
    }

    QMessageBox::information(this, "Sieć", "Rozłączono. Powrót do trybu stacjonarnego.");
}
void MainWindow::on_button_clear_memory_clicked()
{
    _Menager->ClearIntegral();
    _Menager->Clear_Derivative();
}
void MainWindow::on_calka_reset_clicked()
{
    _Menager->ClearIntegral();
}
