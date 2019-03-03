#pragma once

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include "../tools/timespan.h"
#include "../../quantset/instrument/fx.h"
#include "../../quantset/instrument/option.h"

using namespace testing;

TEST(OptionTests, CreateEuropeanFXOption) {
    FX fx {CurrencyPair::EURUSD, 1.1362, 1000000};
    Timespan time_span {};
    EuropeanOption opt = EuropeanOption{
        EuropeanType::Call, 1.1500, time_span, fx
    };

    ASSERT_THAT(1.1500, DoubleEq(opt.Strike()));
    ASSERT_THAT(EuropeanType::Call, Eq(opt.Type()));
    ASSERT_THAT(1.1362, DoubleEq(opt.Underlying().Spot()));
    ASSERT_THAT(1000000, Eq(opt.Underlying().Notional()));
    ASSERT_THAT(CurrencyPair::EURUSD, Eq(opt.Underlying().CcyPair()));
}
