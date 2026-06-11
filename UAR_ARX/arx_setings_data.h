#ifndef ARX_SETINGS_DATA_H
#define ARX_SETINGS_DATA_H

#include <vector>

class ARX_setings_data
{
public:
    ARX_setings_data();
    std::vector<double> _A_params;
    std::vector<double> _B_params;
    std::tuple<float,float,bool> _U_MINMAX, _Y_MINMAX;
    int _transport_delay;
};

#endif // ARX_SETINGS_DATA_H
