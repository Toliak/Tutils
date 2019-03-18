#include "BeautifulStream/IOStream.h"

namespace BeautifulStream
{

IOStream::IOStream(std::istream &istream)
    : istream(&istream)
{}

IOStream::IOStream(std::istream &istream, std::ostream &ostream)
    : istream(&istream), ostream(&ostream)
{}

}