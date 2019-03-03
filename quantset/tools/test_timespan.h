#pragma once

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include "timespan.h"

using namespace testing;

TEST(TimeSpanTests, TestConversions) {
    Timespan ts1 {3,0,0,0,0};
    ASSERT_THAT(1814400, Eq(ts1.SecondsSpan()));
    Timespan ts2 {0,8,0,0};
    ASSERT_THAT(691200, Eq(ts2.SecondsSpan()));
    Timespan ts3 {0,0,51,0,0};
    ASSERT_THAT(183600, Eq(ts3.SecondsSpan()));
    Timespan ts4 {0,0,0,231,0};
    ASSERT_THAT(13860, Eq(ts4.SecondsSpan()));
    Timespan ts5 {0,0,0,0,939};
    ASSERT_THAT(939, Eq(ts5.SecondsSpan()));
    Timespan ts6 {2,6,18,41,6};
    ASSERT_THAT(1795266, Eq(ts6.SecondsSpan()));
    Timespan ts7 {0,365,6,0,0};
    ASSERT_THAT(1.0, DoubleEq(ts7.ApproximateYears()));
}
