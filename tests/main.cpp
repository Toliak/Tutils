#include "gtest/gtest.h"

int main(int argc, char **argv) {
    auto test = std::is_arithmetic<
        std::remove_cv<std::remove_reference<const char*>::type >::type
    >::value;


    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}