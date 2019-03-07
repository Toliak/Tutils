#pragma once

#include <cassert>
#include "Tree.h"
#include "IOStream.h"
#include "utilities.h"

namespace BeautifulStream
{

class InputTree: public Tree
{
    BeautifulStream::IOStream* ioStream = nullptr;

public:
    InputTree() = default;
    InputTree(const InputTree&) = default;
    InputTree(InputTree&&) = default;

    ~InputTree() override = default;

    explicit InputTree(BeautifulStream::IOStream &ioStream);

    template<class T, class ...N>
    T input(N... outputArgs)
    {
        assert(ioStream != nullptr);
        return ioStream->input<T>(Tree::tabSequence * Tree::tabSize, outputArgs...);
    }

};

}