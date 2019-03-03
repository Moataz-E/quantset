#include "fx.h"

FX::FX() {

}

FX::FX(CurrencyPair ccy_pair, double spot, double notional) {
    ccy_pair_ = ccy_pair;
    spot_ = spot;
    notional_ = notional;
}
