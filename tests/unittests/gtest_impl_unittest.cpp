#include <gtest/gtest.h>

namespace CoreGTest
{
    // Check that gtest works
    TEST(CoreTest, CheckSuccess)
    {
        EXPECT_TRUE(true);
    }

    TEST(CoreTest, CheckFailure)
    {
        EXPECT_FALSE(false);
    }
}
