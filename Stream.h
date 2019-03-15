#pragma once

namespace BeautifulStream
{

class Stream
{
public:

    Stream() = default;
    Stream(const Stream &) = default;
    Stream(Stream &&) = default;

    virtual ~Stream() = default;
};

}