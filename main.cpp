#include <iostream>
#include <fstream>
#include <memory>

#include "src/IOStream.h"
#include "src/OutputTree.h"
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

void printTree(BeautifulStream::IOStream &console)
{
    BeautifulStream::OutputTree tree0;
    BeautifulStream::OutputTree tree1;

    tree1.addRow("Sample text");
    tree1.addRow(std::string("What ") * 10);

    tree0.addRow("False");
    tree0.addRow("True");
    tree0.addRow("Sub tree: ");
    tree0.addRow(tree1);
    tree0.addRow("End");

    console.output("OutputTree:\n");
    console.output(tree0);
}

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

    printTree(console);

    auto variable = console.input<int>("Enter int: ");
    console.output("Got int: ", variable);

    return 0;
}