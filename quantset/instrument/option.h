#ifndef EUOPTION_H
#define EUOPTION_H

#include "../../quantset/asset/fx.h"
#include "../../quantset/tools/timespan.h"

// char uses less space than default int
enum class EuropeanType : char {Call, Put};


class EuropeanOption {
    public:
        // constructor
        explicit EuropeanOption(
                EuropeanType opt_type, double opt_strike,
                Timespan opt_time_to_expiry, FX opt_underlying);
        // getters
        double Strike() const {return strike_;}
        EuropeanType Type() const {return type_;}
        Timespan TimeToExpiry() const {return time_to_expiry_;}
        FX Underlying() const {return underlying_;}

    private:
        double strike_;
        EuropeanType type_;
        Timespan time_to_expiry_;
        FX underlying_;
};

#endif
