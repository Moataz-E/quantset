#ifndef BLACKSCHOLES_H
#define BLACKSCHOLES_H

#include <math.h>
#include "../../quantset/tools/statistics.h"
#include "../../quantset/instrument/option.h"

class BlackScholes {
    public:
        BlackScholes();

        /*
         * Price FX option using Garman-Kohlhagen extension to the
         * Black-Scholes formula.
         * Returns price per unit of ccy2.
        */
        double Price(EuropeanOption opt, double ccy1_ir, double ccy2_ir,
                    double spot_vol);
};

#endif
