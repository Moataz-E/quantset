#pragma once

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include "../../quantset/instrument/fx.h"
#include "../../quantset/instrument/option.h"
#include "../../quantset/pricing/options/blackscholes.h"

using namespace testing;
using std::cout;
using std::endl;

/*
 * Test that an option with a strike equal to the underlying, a 0% interest
 * rate for both currencies, and a time to expiry of 1 year is approximately
 * valued at less than 4 units in ccy1.
 */
TEST(BlackScholesFXTests, ZeroValueStrikeEqualForward) {

    double ccy1_r = 0.0;
    double ccy2_r = 0.0;
    double spot_vol = 0.1;

    Timespan ts1 {0,365,6,0,0}; // 365 days and 6 hours (1 year apprx) to expiry
    FX eurusd {CurrencyPair::EURUSD, 100, 10000000};

    BlackScholes bs;
    EuropeanOption eur_opt1 {EuropeanType::Call, 100, ts1, eurusd};
    double eur_opt1_price = bs.Price(eur_opt1, ccy1_r, ccy2_r, spot_vol);

    ASSERT_THAT(eur_opt1_price, DoubleNear(4.0, 0.1));
}

/*
 * Test that an option with a certain strike and underlying will have a higher
 * price than another option with the same strike and underlying but a shorter
 * time to expiry.
 */
TEST(BlackScholesFXTests, LongerMaturityHigherPrice) {

    double ccy1_r = 0.03;
    double ccy2_r = 0.055;
    double spot_vol = 0.08;
    FX eurusd {CurrencyPair::EURUSD, 1.24, 10000000};

    Timespan ts1 {0,90,0,0,0}; // 90 days to expiry
    EuropeanOption eur_opt1 {EuropeanType::Call, 1.3, ts1, eurusd};

    Timespan ts2 {0,30,0,0,0}; // 30 days to expiry
    EuropeanOption eur_opt2 {EuropeanType::Call, 1.3, ts2, eurusd};

    BlackScholes bs;
    double eur_opt1_price = bs.Price(eur_opt1, ccy1_r, ccy2_r, spot_vol);
    double eur_opt2_price = bs.Price(eur_opt2, ccy1_r, ccy2_r, spot_vol);

    ASSERT_THAT(eur_opt1_price, Ge(eur_opt2_price));
}

/*
 * Test that an option with a certain strike, underlying, and expiry will have
 * a higher price than another option with the same strike, underlying, and
 * expiry if the rate for ccy2 for the former is higher than the rate for ccy2
 * in the latter.
 */
TEST(BlackScholesFXTests, HigherCCY2HigherPrice) {

    double o1_ccy1_r = 0.03;
    double o1_ccy2_r = 0.12;
    double o2_ccy1_r = 0.03;
    double o2_ccy2_r = 0.055;

    double spot_vol = 0.08;
    FX eurusd {CurrencyPair::EURUSD, 1.24, 10000000};

    Timespan ts1 {0,600,0,0,0}; // 600 days to expiry
    EuropeanOption eur_opt1 {EuropeanType::Call, 1.4, ts1, eurusd};

    Timespan ts2 {0,600,0,0,0}; // 600 days to expiry
    EuropeanOption eur_opt2 {EuropeanType::Call, 1.4, ts2, eurusd};

    BlackScholes bs;
    double eur_opt1_price = bs.Price(eur_opt1, o1_ccy1_r, o1_ccy2_r, spot_vol);
    double eur_opt2_price = bs.Price(eur_opt2, o2_ccy1_r, o2_ccy2_r, spot_vol);

    ASSERT_THAT(eur_opt1_price, Ge(eur_opt2_price));
}
