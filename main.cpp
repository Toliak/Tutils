#include <iostream>
#include <fstream>
#include <memory>

#include "src/IOStream.h"
//#include "src/Table.h"
#include "src/utilities.h"

struct MyStruct
{
    int a;
    std::string b;

    friend std::ostream &operator<<(std::ostream &os, const MyStruct &aStruct)
    {
        os << "a: " << aStruct.a << " b: " << aStruct.b;
        return os;
    }
};

int main(int argc, char *argv[])
{
    BeautifulStream::IOStream console(std::cin, std::cout);

    MyStruct ms{1, "beta"};
    std::string s0 = BeautifulStream::toString(ms);
    std::string s1 = BeautifulStream::toString(14);
    std::string s2 = BeautifulStream::toString(7.0);
    std::string s3 = BeautifulStream::toString("sampletext");

    console.output(std::string("asdasd") * 10);

    console.output(s0, "\n ", s1, '\n');
    console.output(s2, "\n ", s3, '\n');

    auto variable = console.input<int>("Enter int: ");
    console.output("Got int: ", variable);

    return 0;
}