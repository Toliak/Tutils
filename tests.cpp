#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"

#include "gtest/gtest.h"

#include "src/utilities.h"

class toString: public ::testing::Test
{
protected:
    void SetUp() override
    {
        numbers = new long[5] {
            999999999999999,
            150150150150,
            68574635,
            1415,
            1,
        };

        strings = new std::string[5] {
            "999999999999999",
            "150150150150",
            "68574635",
            "1415",
            "1",
        };

    }
    void TearDown() override
    {
        delete[] numbers;
        delete[] strings;
    }

public:
    long *numbers{};
    std::string *strings{};
};


TEST_F(toString, TestName)
{
    EXPECT_EQ(BeautifulStream::toString(14), "14");
}

TEST_F(toString, VeryLagreNumberViaStringstream)
{
    for (size_t i = 0; i < 99999; i++) {
        EXPECT_EQ((BeautifulStream::__ToString<std::string, long>(numbers[i % 5]).value), strings[i % 5]);
    }
}

TEST_F(toString, VeryLagreNumberViaStd)
{
    for (size_t i = 0; i < 99999; i++) {
        EXPECT_EQ((BeautifulStream::__ToString<int, long>(numbers[i % 5]).value), strings[i % 5]);
    }
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

#pragma clang diagnostic pop