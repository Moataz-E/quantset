#include <gtest/gtest.h>

#include "quantset/tools/test_timespan.h"
#include "quantset/instrument/test_option.h"
#include "quantset/pricing/options/test_blackscholes.h"

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
