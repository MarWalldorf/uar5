#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QList>
#include <QMainWindow>
#include "NetworkManager.h"
#include "UAR_ARX/MenagerSymulacji.h"
#include "arx_settings.h"
#include "graph.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // Sieć i blokowanie
    void on_button_network_setup_clicked();
    void onNetworkDataReceived(QByteArray data);
    void onConnectionEstablished(QString info);
    void onConnectionLost();

    // Standardowe UI
    void on_button_ARX_settings_clicked();
    void on_button_clear_memory_clicked();
    void on_button_Simulation_StartStop_clicked();
    void on_button_generator_type_clicked();
    void on_button_integral_type_clicked();
    void on_button_summit_settings_clicked();
    void on_button_reset_clicked();
    void on_button_save_clicked();
    void on_button_load_clicked();
    void on_calka_reset_clicked();
    void Symuluj(std::array<double, 7> out);

private:
    Ui::MainWindow *ui;
    MenagerSymulacji *_Menager;
    ARX_Settings *_ARX_Settings_Dialog;
    graph *graph1, *graph2, *graph3, *graph4;
    NetworkManager *networkManager;
    bool networkSimulationActive = false; // Flaga, czy ostatnio otrzymaliśmy sygnał w sieci
    qint64 lastNetworkPacketTime = 0;
    double currentTime = 0.0;
    double TimeStep = 0.2;

    QList<QWidget *> regulatorControls;
    QList<QWidget *> arxControls;

    void initControlLists();
    void updateUIMode();
    void UpdateInputs();
};
#endif
