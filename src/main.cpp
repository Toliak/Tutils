
#include <iostream>
#include <fstream>
#include <memory>

#include "IOStream.h"

int main(int argc, char *argv[])
{
    BeautifulStream::IOStream console(std::cin, std::cout);

    auto variable = console.input<int>("Enter int: ");
    console.output("Got int: ", variable);

    return 0;
}