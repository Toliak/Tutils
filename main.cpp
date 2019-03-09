#include <iostream>
#include <fstream>
#include <string>
#include <memory>

#include "src/IOStream.h"
#include "src/CachedStreamTree.h"
#include "src/utilities.h"
#include "src/StreamTree.h"

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
    BeautifulStream::CachedStreamTree tree0(console);
    BeautifulStream::CachedStreamTree tree1(console);

    tree1.addRow("Sample text");
    tree1.addRow("What can I say: ", 2, ' ', '\n');
    tree1.addRow(std::string("What ") * 10);

    tree0.addRow("False");
    tree0.addRow("True");
    tree0.addRow("Sub tree: ");
    tree0.addRow(tree1);
    tree0.addRow("End");

    console.output("CachedStreamTree:\n");
    auto v = tree0.exec();


    BeautifulStream::StreamTree otree(console);
    otree.setTabSequence("-");
    otree.setTabSize(4);
    otree.output("Foo ", "var");

    otree.setTabSize(8);
    otree.output("Var 1: ", v[0]);
    otree.output("Var 2: ", v[1]);

    otree.setTabSize(4);
    otree.output("Foo ", "war");
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

    console.output(s0, "\n ", 50, '\n');
    console.output(s2, "\n ", s3, '\n');

    printTree(console);

    return 0;
}