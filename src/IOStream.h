#pragma once

#include <istream>
#include <ostream>
#include <memory>
#include <iostream>

#include "Stream.h"

namespace BeautifulStream
{

class IOStream: public Stream
{
private:
    std::istream *istream;
    std::ostream *ostream = nullptr;

    template<class T, class ...N>
    struct __Input
    {
        T variable;
        explicit __Input(IOStream *stream, N... outputArgs)
        {
            stream->output(outputArgs...);
            *(stream->istream) >> variable;
        }
    };

    template<class ...N>
    struct __Input<std::string, char, N...>
    {
        std::string variable;
        explicit __Input(IOStream *stream, char delimiter, N... outputArgs)
        {
            stream->output(outputArgs...);
            std::getline(*(stream->istream), variable, delimiter);
        }
    };

    template<class ...N>
    struct __Input<std::string, N...>
    {
        std::string variable;
        explicit __Input(IOStream *stream, N... outputArgs)
        {
            stream->output(outputArgs...);
            std::getline(*(stream->istream), variable);
        }
    };

public:
    explicit IOStream(std::istream &istream);
    IOStream(std::istream &istream, std::ostream &ostream);

    ~IOStream() override = default;

    // Inputs T from istream
    // For std::string:
    //   If first argument is char, it will be used as delimiter
    template<class T, class ...N>
    T input(N... outputArgs)
    {
        return __Input<T, N...>(this, outputArgs...).variable;
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