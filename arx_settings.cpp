#include "arx_settings.h"
#include "ui_arx_settings.h"

int ARX_Settings::counter = 0;

ARX_Settings::ARX_Settings(ARX_Model &model, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ARX_Settings)
{
    ui->setupUi(this);
    counter++;
    _model = &model;
    QWidget *containerA = new QWidget();
    QWidget *containerB = new QWidget();
    listLayoutA = new QVBoxLayout(containerA);
    listLayoutB = new QVBoxLayout(containerB);
    listLayoutA->setAlignment(Qt::AlignTop);
    listLayoutB->setAlignment(Qt::AlignTop);
    ui->scrollArea_wsp_A->setWidget(containerA);
    ui->scrollArea_wsp_B->setWidget(containerB);
    LoadFromModel();
}

ARX_Settings::~ARX_Settings()
{
    counter--;
    delete ui;
}

void ARX_Settings::on_button_wsp_A_add_clicked()
{
    QDoubleSpinBox *sb = new QDoubleSpinBox();
    sb->setMinimum(-9999);
    sb->setMaximum(9999);
    listLayoutA->addWidget(sb);
}

void ARX_Settings::on_button_wsp_A_del_clicked()
{
    if (listLayoutA->count() > 0) {
        QLayoutItem *item = listLayoutA->takeAt(listLayoutA->count() - 1);
        if (item->widget()) {
            delete item->widget();
        }
        delete item;
    }
}

void ARX_Settings::on_button_wsp_A_clear_clicked()
{
    for (int i = listLayoutA->count() - 1; i >= 0; i--) {
        QLayoutItem *item = listLayoutA->takeAt(listLayoutA->count() - 1);
        if (item->widget()) {
            delete item->widget();
        }
        delete item;
    }
}

void ARX_Settings::on_button_wsp_B_add_clicked()
{
    QDoubleSpinBox *sb = new QDoubleSpinBox();
    sb->setMinimum(-9999);
    sb->setMaximum(9999);
    listLayoutB->addWidget(sb);
}

void ARX_Settings::on_button_wsp_B_del_clicked()
{
    if (listLayoutB->count() > 0) {
        QLayoutItem *item = listLayoutB->takeAt(listLayoutB->count() - 1);
        if (item->widget()) {
            delete item->widget();
        }
        delete item;
    }
}

void ARX_Settings::on_button_wsp_B_clear_clicked()
{
    for (int i = listLayoutB->count() - 1; i >= 0; i--) {
        QLayoutItem *item = listLayoutB->takeAt(listLayoutB->count() - 1);
        if (item->widget()) {
            delete item->widget();
        }
        delete item;
    }
}

void ARX_Settings::LoadFromModel()
{
    for (int i = 0; _model->GetAParams().size() > i; i++) {
        QDoubleSpinBox *sbA = new QDoubleSpinBox();
        sbA->setMinimum(-9999);
        sbA->setMaximum(9999);
        sbA->setValue(_model->GetAParams()[i]);
        listLayoutA->addWidget(sbA);
    }
    for (int i = 0; _model->GetBParams().size() > i; i++) {
        QDoubleSpinBox *sbB = new QDoubleSpinBox();
        sbB->setMinimum(-9999);
        sbB->setMaximum(9999);
        sbB->setValue(_model->GetBParams()[i]);
        listLayoutB->addWidget(sbB);
    }
    ui->spin_transport_delay->setValue(_model->getK());
    ui->double_spin_standard_dev->setValue(_model->getZ());
    ui->checkBox_limit_reg->setChecked(get<2>(_model->getYLimits()));
    ui->doubleSpinBox_limit_min_reg->setValue(get<0>(_model->getYLimits()));
    ui->doubleSpinBox_limit_max_reg->setValue(get<1>(_model->getYLimits()));
    ui->checkBox_limit_ster->setChecked(get<2>(_model->getULimits()));
    ui->doubleSpinBox_limit_min_ster->setValue(get<0>(_model->getULimits()));
    ui->doubleSpinBox_limit_max_ster->setValue(get<1>(_model->getULimits()));
}

void ARX_Settings::on_Button_save_clicked()
{
    std::vector<double> _A_Params, _B_Params;
    while (listLayoutA->count()) {
        QLayoutItem *item = listLayoutA->takeAt(0);
        QWidget *widget = item->widget();
        if (widget) {
            QDoubleSpinBox *sb = qobject_cast<QDoubleSpinBox *>(widget);
            if (sb) {
                _A_Params.push_back(sb->value());
            }
        }
    }
    while (listLayoutB->count()) {
        QLayoutItem *item = listLayoutB->takeAt(0);
        QWidget *widget = item->widget();
        if (widget) {
            QDoubleSpinBox *sb = qobject_cast<QDoubleSpinBox *>(widget);
            if (sb) {
                _B_Params.push_back(sb->value());
            }
        }
    }

    // if(_A_Params.size()<3 || _B_Params.size()<3){
    //     QMessageBox::warning(nullptr,"Blad","Podano mniej niz 3 parametery. Dodawnie nieudane!");
    //     return;
    // }
    _model->SetAParams(_A_Params);
    _model->SetBParams(_B_Params);
    _model->SetK(ui->spin_transport_delay->value());
    _model->SetZ(ui->double_spin_standard_dev->value());
    _model->SetU_Limits(ui->checkBox_limit_ster->isChecked(),
                        ui->doubleSpinBox_limit_min_ster->value(),
                        ui->doubleSpinBox_limit_max_ster->value());
    _model->SetY_Limits(ui->checkBox_limit_reg->isChecked(),
                        ui->doubleSpinBox_limit_min_reg->value(),
                        ui->doubleSpinBox_limit_max_reg->value());

    this->accept();
}

void ARX_Settings::on_Button_cancel_clicked()
{
    this->reject();
}

void ARX_Settings::on_ARX_Settings_rejected() {}

void ARX_Settings::on_ARX_Settings_accepted() {}
