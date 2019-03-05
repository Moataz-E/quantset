#include "forward.h"

Forward::Forward(double strike,Timespan time_to_expiry,
                 FX underlying)
{
    strike_ = strike;
    time_to_expiry_ = time_to_expiry;
    underlying_ = underlying;
}
