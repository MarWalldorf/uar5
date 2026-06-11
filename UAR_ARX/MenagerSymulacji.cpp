#include "MenagerSymulacji.h"

MenagerSymulacji::MenagerSymulacji(FeedbackLoop loop_, QObject *parent)
    : QObject(parent), loop(loop_) {
    timer = new QTimer(this);
    timer->setTimerType(Qt::PreciseTimer);
    timer->setInterval(timerInteval);
    connect(timer, &QTimer::timeout, this, &MenagerSymulacji::TriggerSim);
}

MenagerSymulacji::~MenagerSymulacji() {}

void MenagerSymulacji::TriggerSim(){
    if (!timer->isActive())
        return;

    if (currentRole == SimRole::Stationary) {

        double wz = currentWz;
        if (useGenState) wz = loop.getGenerator().Generate();

        double e = wz - last_y;
        double u = loop.getRegulator().Calc_PID(e);
        double y = loop.getARXModel().GrindingFunction(u);


        current_u = u;
        current_e = e;
        current_wz = wz;
        last_y = y;

        loop.SetTracking(y, u, e);
        loop.setWZadane(wz);


        std::array<double, 7> out = {wz, y, u,
                                     loop.getRegulator().getLastKpValue(),
                                     loop.getRegulator().getLastTiValue(),
                                     loop.getRegulator().getLastTdValue(),
                                     e};
        emit UpdateSim(out);
    }
    else if (currentRole == SimRole::Regulator) {
        current_wz = currentWz;
        if (useGenState) current_wz = loop.getGenerator().Generate();
        current_e = current_wz - last_y;
        current_u = loop.getRegulator().Calc_PID(current_e);


        emit SendNetworkU(current_u, current_wz);
    }
}

void MenagerSymulacji::ReceiveNetworkY(double y) {
    last_y = y;

    if (currentRole == SimRole::Stationary) {
        loop.getARXModel().TrackNetwork(current_u, y);
    }


    loop.SetTracking(y, current_u, current_e);

    std::array<double, 7> out = {current_wz, y, current_u,
                                 loop.getRegulator().getLastKpValue(),
                                 loop.getRegulator().getLastTiValue(),
                                 loop.getRegulator().getLastTdValue(),
                                 current_e};
    emit UpdateSim(out);
}
double MenagerSymulacji::CalculateARX_Network(double u, double wz) {
    currentWz = wz;
    current_wz = wz;
    current_u = u;

    double y = loop.getARXModel().GrindingFunction(u);
    last_y = y;
    current_e = wz - y;

    loop.SetTracking(y, u, current_e);

    return y;
}

// Gettery (Poprawione u¿ycie std::get dla tuple)
double MenagerSymulacji::getAmplitude() { return std::get<1>(loop.getGenerator().GetGeneratorParams()); }
double MenagerSymulacji::getShift() { return std::get<2>(loop.getGenerator().GetGeneratorParams()); }
double MenagerSymulacji::getPulseWidth() { return std::get<3>(loop.getGenerator().GetGeneratorParams()); }
int MenagerSymulacji::getPeriod() { return std::get<0>(loop.getGenerator().GetGeneratorParams()); }
double MenagerSymulacji::getKp() { return loop.getRegulator().getKp(); }
double MenagerSymulacji::getTi() { return loop.getRegulator().getTi(); }
double MenagerSymulacji::getTd() { return loop.getRegulator().getTd(); }
bool MenagerSymulacji::getIType() { return std::get<3>(loop.getRegulator().GetRegParams()); }
double MenagerSymulacji::getWz() { return loop.GetWz(); }
bool MenagerSymulacji::getUseGen() { return useGenState; }
bool MenagerSymulacji::getGenType() { return loop.getGenerator().GetGeneratorType(); }
void MenagerSymulacji::setGraphTime(double time) { graphTime = time; }
double MenagerSymulacji::getGraphTime() { return graphTime; }

QJsonDocument MenagerSymulacji::Serialize(){
    QJsonObject ModelArx;
    auto [Umin, Umax, Ustate] = loop.getARXModel().getULimits();
    auto [Ymin, Ymax, YState] = loop.getARXModel().getYLimits();
    ModelArx["z"] = loop.getARXModel().getZ();
    ModelArx["k"] = loop.getARXModel().getK();
    ModelArx["Umin"] = Umin; ModelArx["Umax"] = Umax; ModelArx["Ustate"] = Ustate;
    ModelArx["Ymin"] = Ymin; ModelArx["Ymax"] = Ymax; ModelArx["Ystate"] = YState;
    QJsonArray A, B;
    for(auto &i : loop.getARXModel().GetAParams()) A.append(i);
    for(auto &i : loop.getARXModel().GetBParams()) B.append(i);
    ModelArx["AParams"] = A; ModelArx["BParams"] = B;

    QJsonObject Regulator;
    auto [Kp, Td, Ti, i_type] = loop.getRegulator().GetRegParams();
    Regulator["Kp"] = Kp; Regulator["Td"] = Td; Regulator["Ti"] = Ti; Regulator["integral_Type"] = i_type;

    QJsonObject Generator;
    auto params = loop.getGenerator().GetGeneratorParams();
    Generator["T"] = std::get<0>(params);
    Generator["A"] = std::get<1>(params);
    Generator["S"] = std::get<2>(params);
    Generator["p"] = std::get<3>(params);
    Generator["gen_type"] = loop.getGenerator().GetGeneratorType();

    QJsonObject Root;
    Root["ModelArx"] = ModelArx; Root["Regulator"] = Regulator; Root["Generator"] = Generator;
    Root["WartoscZadana"] = loop.GetWz(); Root["TimerInterval"] = timerInteval;
    Root["GraphTime"] = graphTime;
    Root["UseGen"] = useGenState;
    Root["TimerRunning"] = timer->isActive();
    return QJsonDocument(Root);
}

void MenagerSymulacji::deserialize(QJsonDocument doc){
    QJsonObject root = doc.object();


    if(root.contains("TimerInterval")) setInterval(root["TimerInterval"].toInt());
    if(root.contains("GraphTime")) graphTime = root["GraphTime"].toDouble();
    if(root.contains("WartoscZadana")) setWZadane(root["WartoscZadana"].toDouble());
    if(root.contains("UseGen")) setUseGen(root["UseGen"].toBool());


    if(root.contains("ModelArx")) {
        QJsonObject model = root["ModelArx"].toObject();
        QJsonArray AParams = model["AParams"].toArray();
        QJsonArray BParams = model["BParams"].toArray();

        std::vector<double> va, vb;
        for(auto i : AParams) va.push_back(i.toDouble());
        for(auto i : BParams) vb.push_back(i.toDouble());

        loop.getARXModel().SetAParams(va);
        loop.getARXModel().SetBParams(vb);
        loop.getARXModel().SetU_Limits(model["Ustate"].toBool(), model["Umin"].toDouble(), model["Umax"].toDouble());
        loop.getARXModel().SetY_Limits(model["Ystate"].toBool(), model["Ymin"].toDouble(), model["Ymax"].toDouble());
        loop.getARXModel().SetK(model["k"].toInt());
        loop.getARXModel().SetZ(model["z"].toDouble());
    }


    if(root.contains("Regulator")) {
        QJsonObject reg = root["Regulator"].toObject();
        loop.getRegulator().set_IType(reg["integral_Type"].toBool());
        loop.getRegulator().set_Kp(reg["Kp"].toDouble());
        loop.getRegulator().set_Td(reg["Td"].toDouble());
        loop.getRegulator().set_Ti(reg["Ti"].toDouble());
    }
    if(root.contains("Generator")) {
        QJsonObject gen = root["Generator"].toObject();
        loop.getGenerator().SetGeneratorType(gen["gen_type"].toBool());
        loop.getGenerator().setParameters(gen["T"].toInt());
        loop.getGenerator().setAmplitude(gen["A"].toDouble());
        loop.getGenerator().setShift(gen["S"].toDouble());
        loop.getGenerator().setPulseWidth(gen["p"].toDouble());
    }


    if(root.contains("TimerRunning")) {
        setTimerState(root["TimerRunning"].toBool());
    }
}

void MenagerSymulacji::ResetNetworkState()
{
    setTimerState(false);

    current_u = 0;
    current_e = 0;
    current_wz = 0;
    currentWz = 0;
    last_y = 0;

    loop.getRegulator().Clear_Integral();
    loop.getRegulator().Clear_Derivative();

    loop.getARXModel().ResetQueue();
}

void MenagerSymulacji::SetAParams(std::vector<double> a) { loop.getARXModel().SetAParams(a); }
void MenagerSymulacji::SetBParams(std::vector<double> b) { loop.getARXModel().SetBParams(b); }
void MenagerSymulacji::SetK(int k) { loop.getARXModel().SetK(k); }
void MenagerSymulacji::SetZ(double z) { loop.getARXModel().SetZ(z); }
void MenagerSymulacji::SetULimits(bool s, double min, double max) { loop.getARXModel().SetU_Limits(s, min, max); }
void MenagerSymulacji::SetYLimits(bool s, double min, double max) { loop.getARXModel().SetY_Limits(s, min, max); }
void MenagerSymulacji::ARX_Clear() { loop.getARXModel().ResetQueue(); }
void MenagerSymulacji::Reset_Regulator() { loop.getRegulator().set_Kp(0); loop.getRegulator().set_Ti(0); loop.getRegulator().set_Td(0); }
void MenagerSymulacji::SetKp(double K) { loop.getRegulator().set_Kp(K); }
void MenagerSymulacji::SetTi(double T) { loop.getRegulator().set_Ti(T); }
void MenagerSymulacji::SetTd(double T) { loop.getRegulator().set_Td(T); }
void MenagerSymulacji::SetIType(bool t) { loop.getRegulator().set_IType(t); }
void MenagerSymulacji::ClearIntegral() { loop.getRegulator().Clear_Integral(); }
void MenagerSymulacji::Clear_Derivative() { loop.getRegulator().Clear_Derivative(); }
void MenagerSymulacji::SetGeneratorType(bool t) { loop.getGenerator().SetGeneratorType(t); }
void MenagerSymulacji::SetGeneratorParameters(int T) { loop.getGenerator().setParameters(T); }
void MenagerSymulacji::SetGeneratorAmplitude(double A) { loop.getGenerator().setAmplitude(A); }
void MenagerSymulacji::SetGeneratorShift(double S) { loop.getGenerator().setShift(S); }
void MenagerSymulacji::SetGeneratorPulseWidth(double p) { loop.getGenerator().setPulseWidth(p); }
void MenagerSymulacji::setUseGen(bool s) { useGenState = s; loop.setUseGen(s); }
void MenagerSymulacji::setWZadane(double w) { currentWz = w; loop.setWZadane(w); }
void MenagerSymulacji::setInterval(int ms) { timerInteval = ms; timer->setInterval(ms); }

void MenagerSymulacji::setTimerState(bool s)
{
    if (s) {
        if (!timer->isActive())
            timer->start();
    } else {
        if (timer->isActive())
            timer->stop();
    }

    emit TimerStateChanged(timer->isActive());
}

void MenagerSymulacji::RestoreTimerState(bool running)
{
    if (running) {
        if (!timer->isActive())
            timer->start();
    } else {
        if (timer->isActive())
            timer->stop();
    }
}

int MenagerSymulacji::getInterval() { return timerInteval; }
void MenagerSymulacji::Reset() { loop.Reset(); }



void MenagerSymulacji::setRole(SimRole role)
{

    if (currentRole != SimRole::Stationary && role == SimRole::Stationary) {
        if (timer->isActive()) {
            timer->stop();
        }
    }


    currentRole = role;
}


ARX_Model& MenagerSymulacji::GetARX()
{
    return loop.getARXModel();
}

bool MenagerSymulacji::GetRunningState()
{
    return timer->isActive();
}

SimRole MenagerSymulacji::getRole()
{
    return currentRole;
}

std::array<double,7> MenagerSymulacji::Symuluj()
{
    return loop.Symuluj();
}

