#include "eur_option.h"

EuropeanOption::EuropeanOption(EuropeanType opt_type, double opt_strike,
                               Timespan opt_time_to_expiry, FX opt_underlying)
{
    type_ = opt_type;
    strike_ = opt_strike;
    underlying_ = opt_underlying;
    time_to_expiry_ = opt_time_to_expiry;
}
