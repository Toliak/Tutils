#pragma once

#include <istream>
#include <ostream>
#include <memory>

#include "Stream.h"

namespace BeautifulStream
{

class IOStream: public Stream
{
    std::istream* istream;
    std::ostream* ostream = nullptr;

public:
    explicit IOStream(std::istream &istream);
    IOStream(std::istream &istream, std::ostream &ostream);

    ~IOStream() override = default;

    template<class T, class ...N>
    T input(N... outputArgs)
    {
        IOStream::output(outputArgs...);

        T variable;
        *istream >> variable;
        return variable;
    }


    template<class T, class ...N>
    void output(T var, N... args)
    {
        if (ostream == nullptr) {
            return;
        }

        *ostream << var;
        return IOStream::output(args...);
    }


    void output()
    {
        // Just nothing
    }

};

}