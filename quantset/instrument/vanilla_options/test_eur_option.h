#pragma once

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include "../../tools/timespan.h"
#include "../../../quantset/asset/fx.h"
#include "../../../quantset/instrument/vanilla_options/eur_option.h"

using namespace testing;

TEST(OptionTests, CreateEuropeanFXOption) {

    // underlying
    CurrencyPair ccy_pair = CurrencyPair::EURUSD;
    double spot = 1.1362;
    double spot_vol = 0.1;
    double ccy1_r = 0.03;
    double ccy2_r = 0.055;

    // option
    EuropeanType opt_type = EuropeanType::Call;
    double strike = 1.1500;

    Timespan time_span {};
    FX fx {ccy_pair, spot, spot_vol, ccy1_r, ccy2_r};
    EuropeanOption opt = EuropeanOption{opt_type, strike, time_span, fx};

    ASSERT_THAT(1.1500, DoubleEq(opt.Strike()));
    ASSERT_THAT(EuropeanType::Call, Eq(opt.Type()));
    ASSERT_THAT(1.1362, DoubleEq(opt.Underlying().Spot()));
    ASSERT_THAT(0.1, DoubleEq(opt.Underlying().SpotVol()));
    ASSERT_THAT(0.03, DoubleEq(opt.Underlying().Ccy1Rate()));
    ASSERT_THAT(0.055, DoubleEq(opt.Underlying().Ccy2Rate()));
    ASSERT_THAT(CurrencyPair::EURUSD, Eq(opt.Underlying().CcyPair()));
}
