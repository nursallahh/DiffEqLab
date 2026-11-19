#include <gtest/gtest.h>
#include "mathcore/expr/smoke.hpp"

TEST(SmokeTest, AddWorks) {
    EXPECT_EQ(diffeqlab::add(2, 3), 5);
}