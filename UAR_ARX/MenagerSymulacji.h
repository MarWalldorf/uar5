#pragma once
#include "FeedbackLoop.h"
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QObject>
#include <vector>
#include <QTimer>
#include <array>

enum class SimRole { Stationary, Regulator, Object };

class MenagerSymulacji : public QObject
{
    Q_OBJECT
    FeedbackLoop loop;
    QTimer* timer;
    int timerInteval = 200;

    SimRole currentRole = SimRole::Stationary;
    bool useGenState = false;
    double currentWz = 0.0;

    double last_y = 0.0;
    double current_wz = 0.0;
    double current_u = 0.0;
    double current_e = 0.0;


public:
    MenagerSymulacji(FeedbackLoop loop, QObject* parent = nullptr);
    ~MenagerSymulacji();

    // Parametry ARX
    void SetAParams(std::vector<double> a_);
    void SetBParams(std::vector<double> b_);
    void SetK(int k_);
    void SetZ(double z_);
    void SetULimits(bool state, double min_, double max_);
    void SetYLimits(bool state, double min_, double max_);
    void ARX_Clear();
    void Reset_Regulator();
    ARX_Model& GetARX();
    void RestoreNetworkState();
    double GetLastY() const { return last_y; }
    void SetLastY(double y) { last_y = y; }
    void RestoreTimerState(bool running);

    // Parametry PID
    void SetKp(double Kp_);
    void SetTi(double Ti_);
    void SetTd(double Td_);
    void SetIType(bool I_type_);
    void ClearIntegral();
    void Clear_Derivative();
    double getKp();
    double getTi();
    double getTd();
    bool getIType();

    // Parametry Generatora
    void SetGeneratorType(bool type_);
    void SetGeneratorParameters(int T_);
    void SetGeneratorAmplitude(double A_);
    void SetGeneratorShift(double S_);
    void SetGeneratorPulseWidth(double p_);
    void ResetGeneratorCounter();
    void setUseGen(bool);
    void setWZadane(double wz);
    void setGraphTime(double time);

    // Gettery do synchronizacji UI
    double getAmplitude();
    double getShift();
    double getPulseWidth();
    int getPeriod();
    double getWz();
    bool getUseGen();
    bool getGenType();
    double getGraphTime();

    // NOWE METODY DO PRZYWRACANIA STANU
    double GetLastU() const { return current_u; }
    void SetLastU(double u) {
        current_u = u;

    }

    double GetCurrentWz() const { return current_wz; }
    void SetCurrentWz(double wz) { current_wz = wz; }

    double GetCurrentE() const { return current_e; }
    void SetCurrentE(double e) { current_e = e; }

    void RestoreARXState(double u, double y) {
        loop.getARXModel().RestoreSimulationState(u, y);
    }

    // Symulacja
    std::array<double,7> Symuluj();
    void ChangeRunningState();
    bool GetRunningState();
    void setInterval(int);
    void setTimerState(bool);
    int getInterval();

    QJsonDocument Serialize();
    void deserialize(QJsonDocument doc);
    void Reset();
    void ResetNetworkState();

    // Sieć
    void setRole(SimRole role);
    SimRole getRole();
    void ReceiveNetworkY(double y);
    double CalculateARX_Network(double u, double wz);
    // W MenagerSymulacji.h:

    double GetIntegral() { return loop.getRegulator().GetIntegral(); }
    void SetIntegral(double integral) { loop.getRegulator().SetIntegral(integral); }
    void SetLastError(double e) { loop.getRegulator().SetLastError(e); }
    void ForceUpdateLastY(double y) { last_y = y; }
    void UpdateFeedbackLoopState(double y, double u, double e, double wz)
    {
        loop.SetTracking(y, u, e);
        loop.setWZadane(wz);
    }
private slots:
    void TriggerSim();

private:
    double graphTime = 10.0;

signals:
    void UpdateSim(std::array<double,7>);
    void SendNetworkU(double u, double wz);
    void TimerStateChanged(bool running);
};
