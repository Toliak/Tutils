#include "Tutils/Stream.h"
#include "gtest/gtest.h"

class StreamWrapperFixture: public ::testing::Test
{
public:
    std::istringstream iStreamString;
    std::ostringstream oStreamString;
    std::stringstream ioStreamString;

    Tutils::StreamWrapper iStream{iStreamString};
    Tutils::StreamWrapper oStream{oStreamString};
    Tutils::StreamWrapper ioStream{ioStreamString, ioStreamString};
    Tutils::StreamWrapper iopStream{oStreamString, iStreamString};
};

TEST_F(StreamWrapperFixture, WriteOnly)
{
    oStream.write("Some string");
    EXPECT_EQ(oStreamString.str(), "Some string");

    ioStream.write("Some string");
    EXPECT_EQ(ioStreamString.str(), "Some string");
}

TEST_F(StreamWrapperFixture, ReadOnly)
{
    iStreamString = std::move(std::istringstream{"423"});
    EXPECT_EQ(iStream.read<int>(), 423);

    ioStreamString << "423";
    EXPECT_EQ(ioStream.read<int>(), 423);
}

TEST_F(StreamWrapperFixture, WriteToNothing)
{
    iStream.write("Some string");
    EXPECT_EQ(iStreamString.str(), "");
}

TEST_F(StreamWrapperFixture, ReadFromNothing)
{
    EXPECT_EQ(oStream.read<int>(), 0);
}

TEST_F(StreamWrapperFixture, ReadOnlyString)
{
    iStreamString = std::move(std::istringstream{"Some string with spaces"});
    EXPECT_EQ(iStream.read<std::string>(), "Some string with spaces");

    ioStream.write("Some string with spaces");
    EXPECT_EQ(ioStream.read<std::string>(), "Some string with spaces");
}

TEST_F(StreamWrapperFixture, WriteAndReadSimple)
{
    ioStream.write("12345");
    EXPECT_EQ(ioStreamString.str(), "12345");

    EXPECT_EQ(ioStream.read<int>(), 12345);
}

TEST_F(StreamWrapperFixture, WriteAndReadMultiple)
{
    ioStream.write("435 7.5\n1");
    EXPECT_EQ(ioStreamString.str(), "435 7.5\n1");

    EXPECT_EQ(ioStream.read<int>(), 435);
    EXPECT_EQ(ioStream.read<double>(), 7.5);
    EXPECT_EQ(ioStream.read<bool>(), true);
}

TEST_F(StreamWrapperFixture, WriteAndReadMultipleWithString)
{
    ioStream.write("435 7.5\n1\ni am string 1\ni am string 2");
    EXPECT_EQ(ioStreamString.str(), "435 7.5\n1\ni am string 1\ni am string 2");

    EXPECT_EQ(ioStream.read<int>(), 435);
    EXPECT_EQ(ioStream.read<double>(), 7.5);
    EXPECT_EQ(ioStream.read<bool>(), true);
    EXPECT_EQ(ioStream.read<std::string>(), "i am string 1");
    EXPECT_EQ(ioStream.read<std::string>(), "i am string 2");
}

TEST_F(StreamWrapperFixture, ReadWithHint)
{
    iStreamString = std::move(std::istringstream{"445533"});
    int number = iopStream.read<int>("Enter a number: ");

    EXPECT_EQ(oStreamString.str(), "Enter a number: ");
    EXPECT_EQ(number, 445533);
}