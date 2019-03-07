#pragma once

#include <cassert>
#include "Tree.h"
#include "IOStream.h"
#include "utilities.h"

namespace BeautifulStream
{

class OutputTree: public Tree
{
protected:
    BeautifulStream::IOStream* ioStream = nullptr;

public:
    OutputTree() = default;
    OutputTree(const OutputTree&) = default;
    OutputTree(OutputTree&&) = default;

    ~OutputTree() override = default;

    explicit OutputTree(BeautifulStream::IOStream &ioStream);

    template<class T, class ...N>
    void output(T var, N... args)
    {
        assert(ioStream != nullptr);
        ioStream->output(Tree::tabSequence * Tree::tabSize, args...);
    }

};

}
