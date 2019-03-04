#include "blackscholes.h"

BlackScholes::BlackScholes() {

}

/*
 * Price FX option using Garman-Kohlhagen extension to the
 * Black-Scholes formula.
 * Returns price per unit of ccy2.
*/
double BlackScholes::Price(
        EuropeanOption opt, double ccy1_ir, double ccy2_ir, double spot_vol)
{
    double spot = opt.Underlying().Spot();
    double yrs_to_expiry = opt.TimeToExpiry().ApproximateYears();

    // Calculate d1 and d2 terms
    double rdiff = ccy2_ir - ccy1_ir;
    double exp_return = (rdiff + (0.5 * pow(spot_vol, 2))) * yrs_to_expiry;
    double sd_return = spot_vol * sqrt(yrs_to_expiry);
    double d1 = (log(spot / opt.Strike()) + exp_return) / sd_return;
    double d2 = d1 - (spot_vol * sqrt(yrs_to_expiry));

    // Calculate price depending on call or put
    Statistics stats {};
    double price = 0.0;
    double ds_spot = spot * exp(-ccy1_ir * yrs_to_expiry);
    double ds_strike = opt.Strike() * exp(-ccy2_ir * yrs_to_expiry);
    switch (opt.Type()) {
        case (EuropeanType::Call):
            price = ds_spot * stats.Norm(d1) - ds_strike * stats.Norm(d2);
            break;
        case (EuropeanType::Put):
            price = ds_strike * stats.Norm(-d2) - ds_spot * stats.Norm(-d1);
            break;
    }

    return price;
}
