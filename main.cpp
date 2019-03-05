#include <gtest/gtest.h>

#include "quantset/tools/test_timespan.h"
#include "quantset/pricing/options/test_blackscholes.h"
#include "quantset/instrument/vanilla_options/test_eur_option.h"

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
