#ifndef FORWARD_H
#define FORWARD_H

#include "../../../quantset/asset/fx.h"
#include "../../../quantset/tools/timespan.h"


/*
 * Class used to represent a Forward, it is very similar to a vanilla european
 * option in terms of initialization but we chose to separate them for clarity.
 */
class Forward {
    public:
        // constructor
        Forward(double opt_strike,Timespan opt_time_to_expiry,
                FX opt_underlying);

        // getters
        double Strike() const {return strike_;}
        Timespan TimeToExpiry() const {return time_to_expiry_;}
        FX Underlying() const {return underlying_;}

        // setters
        void SetStrike(double strike) {strike_ = strike;}
        void SetTimeToExpiry(Timespan time_to_expiry) {
            time_to_expiry_ = time_to_expiry;}
        void SetUnderlying(FX underlying) {underlying_ = underlying;}

    private:
        double strike_;
        Timespan time_to_expiry_;
        FX underlying_;
};

#endif // FORWARD_H
