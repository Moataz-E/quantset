#ifndef BLACKSCHOLES_H
#define BLACKSCHOLES_H

#include <math.h>
#include "../../quantset/tools/statistics.h"
#include "../../quantset/instrument/vanilla_options/eur_option.h"

class BlackScholes {
    public:
        BlackScholes();

        /*
         * Price FX option using Garman-Kohlhagen extension to the
         * Black-Scholes formula.
         * Returns price per unit of ccy2.
        */
        double Price(EuropeanOption opt, double notional);

        /*
         * Calculate delta of an FX options
         */
        double Delta(EuropeanOption opt);
};

#endif
