#pragma once

#include <cassert>
#include "Tree.h"
#include "IOStream.h"
#include "utilities.h"

namespace BeautifulStream
{

class StreamTree: virtual public Tree
{
protected:
    BeautifulStream::IOStream* ioStream = nullptr;

public:
    StreamTree() = delete;
    StreamTree(const StreamTree&) = default;
    StreamTree(StreamTree&&) = default;

    ~StreamTree() override = default;

    explicit StreamTree(BeautifulStream::IOStream &ioStream);

    template<class ...N>
    void output(N... args)
    {
        ioStream->output(Tree::tabSequence * Tree::tabSize, args..., "\n");
    }

    template<class T, class ...N>
    T input(N... outputArgs)
    {
        return ioStream->input<T>(Tree::tabSequence * Tree::tabSize, outputArgs...);
    }

};

}
