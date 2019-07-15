#include "Tutils/utils.h"
#include "gtest/gtest.h"
#include <ostream>

TEST(ToString, NumberIntegral)
{
    EXPECT_EQ(Tutils::toString(5), "5");
    EXPECT_EQ(Tutils::toString(6L), "6");
    EXPECT_EQ(Tutils::toString(7LL), "7");

    EXPECT_EQ(Tutils::toString(8U), "8");
    EXPECT_EQ(Tutils::toString(9LU), "9");
    EXPECT_EQ(Tutils::toString(10LLU), "10");

    EXPECT_EQ(Tutils::toString(static_cast<short>(11)), "11");
    EXPECT_EQ(Tutils::toString(static_cast<unsigned short>(12)), "12");
}

TEST(ToString, NumberFloating)
{
    auto string = Tutils::toString(5.);
    EXPECT_EQ(string.substr(0, 1), "5");

    string = Tutils::toString(6.F);
    EXPECT_EQ(string.substr(0, 1), "6");

    string = Tutils::toString(7.L);
    EXPECT_EQ(string.substr(0, 1), "7");
}

TEST(ToString, String)
{
    EXPECT_EQ(Tutils::toString(std::string("I am string")), "I am string");
}

TEST(ToString, CString)
{
    EXPECT_EQ(Tutils::toString("I am string"), "I am string");
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
    EXPECT_EQ(Tutils::toString(stringable), "35");
}

TEST(FromString, NumberIntegral)
{
    EXPECT_EQ(Tutils::fromString<short>("4"), 4);
    EXPECT_EQ(Tutils::fromString<int>("5"), 5);
    EXPECT_EQ(Tutils::fromString<long>("6"), 6L);
    EXPECT_EQ(Tutils::fromString<long long>("7"), 7LL);

    EXPECT_EQ(Tutils::fromString<unsigned short>("11"), 11);
    EXPECT_EQ(Tutils::fromString<unsigned int>("8"), 8U);
    EXPECT_EQ(Tutils::fromString<unsigned long>("9"), 9LU);
    EXPECT_EQ(Tutils::fromString<unsigned long long>("10"), 10LLU);
}

TEST(FromString, NumberFloating)
{
    EXPECT_EQ(Tutils::fromString<float>("10.7"), 10.7F);
    EXPECT_EQ(Tutils::fromString<double>("8.9"), 8.9);
    EXPECT_EQ(Tutils::fromString<long double>("9.8"), 9.8L);
}

TEST(FromString, String)
{
    EXPECT_EQ(Tutils::fromString<std::string>("I am string"), "I am string");
}

TEST(SplitString, Empty)
{
    EXPECT_EQ(
        Tutils::splitString<char>("no_separator_here", ""),
        std::vector<std::string>{"no_separator_here"}
    );
}

TEST(SplitString, Good)
{
    EXPECT_EQ(
        Tutils::splitString<char>("first,second", ","),
        (std::vector<std::string>{"first", "second"})
    );
}

TEST(SplitString, NoSeparator)
{
    EXPECT_EQ(
        Tutils::splitString<char>("first,second", " "),
        (std::vector<std::string>{"first,second"})
    );
}

TEST(SplitString, DoubleSeparator)
{
    EXPECT_EQ(
        Tutils::splitString<char>("double  sep", " "),
        (std::vector<std::string>{"double", "sep"})
    );
}

TEST(SplitString, EmptySeparator)
{
    EXPECT_EQ(
        Tutils::splitString<char>("first,second", ""),
        (std::vector<std::string>{"first,second"})
    );
}

TEST(JoinIntoString, OneString)
{
    EXPECT_EQ(Tutils::joinIntoString(" ", "string"), "string");
}

TEST(JoinIntoString, ThreeStrings)
{
    EXPECT_EQ(Tutils::joinIntoString(" ", "string", "and", "another"), "string and another");
}

TEST(JoinIntoString, Variadic)
{
    EXPECT_EQ(
        Tutils::joinIntoString(
            "-",
            55UL,
            "string",
            -11LL,
            "another",
            0
        ),
        "55-string--11-another-0"
    );
}

TEST(JoinIntoString, VariadicWithCustom)
{
    CustomStringable stringable{11, 25};
    EXPECT_EQ(
        Tutils::joinIntoString(
            ",",
            "string",
            stringable,
            "another"
        ),
        "string,36,another"
    );
}

TEST(StringMultiply, Simple)
{
    EXPECT_EQ(std::string("-") * 1, "-");
    EXPECT_EQ(std::string("-") * 5, "-----");
    EXPECT_EQ(std::string("-") * 7, "-------");
}

TEST(StringMultiply, Zero)
{
    EXPECT_EQ(std::string("-") * 0, "");
}

TEST(StringMultiply, Negative)
{
    EXPECT_EQ(std::string("test") * -1, "tset");
    EXPECT_EQ(std::string("-") * -5, "-----");
    EXPECT_EQ(std::string("qw") * -3, "wqwqwq");
}