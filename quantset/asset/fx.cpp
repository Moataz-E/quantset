#include "fx.h"

FX::FX() {

}

FX::FX(CurrencyPair ccy_pair, double spot, double spot_vol, double ccy1_r,
       double ccy2_r)
{
    ccy_pair_ = ccy_pair;
    spot_ = spot;
    spot_vol_ = spot_vol;
    ccy1_r_ = ccy1_r;
    ccy2_r_ = ccy2_r;
}
