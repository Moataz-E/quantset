#ifndef EUOPTION_H
#define EUOPTION_H

#include "../../../quantset/asset/fx.h"
#include "../../../quantset/tools/timespan.h"

// char uses less space than default int
enum class EuropeanType : char {Call, Put, Forward};


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

        // setters
        void SetStrike(double strike) {strike_ = strike;}
        void SetType(EuropeanType type) {type_ = type;}
        void SetTimeToExpiry(Timespan time_to_expiry) {
            time_to_expiry_ = time_to_expiry;}
        void SetUnderlying(FX underlying) {underlying_ = underlying;}

    private:
        double strike_;
        EuropeanType type_;
        Timespan time_to_expiry_;
        FX underlying_;
};

#endif
