#include "BeautifulStream/utilities.h"
#include "gtest/gtest.h"
#include <ostream>

TEST(ToString, NumberIntegral)
{
    EXPECT_EQ(BeautifulStream::toString(5), "5");
    EXPECT_EQ(BeautifulStream::toString(6L), "6");
    EXPECT_EQ(BeautifulStream::toString(7LL), "7");

    EXPECT_EQ(BeautifulStream::toString(8U), "8");
    EXPECT_EQ(BeautifulStream::toString(9LU), "9");
    EXPECT_EQ(BeautifulStream::toString(10LLU), "10");

    EXPECT_EQ(BeautifulStream::toString(static_cast<short>(11)), "11");
    EXPECT_EQ(BeautifulStream::toString(static_cast<unsigned short>(12)), "12");
}

TEST(ToString, NumberFloating)
{
    auto string = BeautifulStream::toString(5.);
    EXPECT_EQ(string.substr(0, 1), "5");

    string = BeautifulStream::toString(6.F);
    EXPECT_EQ(string.substr(0, 1), "6");

    string = BeautifulStream::toString(7.L);
    EXPECT_EQ(string.substr(0, 1), "7");
}

TEST(ToString, String)
{
    EXPECT_EQ(BeautifulStream::toString(std::string("I am string")), "I am string");
}

TEST(ToString, CString)
{
    EXPECT_EQ(BeautifulStream::toString("I am string"), "I am string");
}

class CustomStringable
{
    int first;
    int second;

public:
    CustomStringable(int first, int second)
        : first(first), second(second)
    {}

    friend std::ostream &operator<<(std::ostream &os, const CustomStringable &stringable)
    {
        os << stringable.first + stringable.second;
        return os;
    }
};

TEST(ToString, Custom)
{
    CustomStringable stringable{10, 25};
    EXPECT_EQ(BeautifulStream::toString(stringable), "35");
}

TEST(FromString, NumberIntegral)
{
    EXPECT_EQ(BeautifulStream::fromString<short>("4"), 4);
    EXPECT_EQ(BeautifulStream::fromString<int>("5"), 5);
    EXPECT_EQ(BeautifulStream::fromString<long>("6"), 6L);
    EXPECT_EQ(BeautifulStream::fromString<long long>("7"), 7LL);

    EXPECT_EQ(BeautifulStream::fromString<unsigned short>("11"), 11);
    EXPECT_EQ(BeautifulStream::fromString<unsigned int>("8"), 8U);
    EXPECT_EQ(BeautifulStream::fromString<unsigned long>("9"), 9LU);
    EXPECT_EQ(BeautifulStream::fromString<unsigned long long>("10"), 10LLU);
}

TEST(FromString, NumberFloating)
{
    EXPECT_EQ(BeautifulStream::fromString<float>("10.7"), 10.7F);
    EXPECT_EQ(BeautifulStream::fromString<double>("8.9"), 8.9);
    EXPECT_EQ(BeautifulStream::fromString<long double>("9.8"), 9.8L);
}

// TODO: string from string test