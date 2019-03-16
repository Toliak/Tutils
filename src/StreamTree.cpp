#include "BeautifulStream/IOStream.h"
#include "BeautifulStream/StreamTree.h"

namespace BeautifulStream
{

BeautifulStream::StreamTree::StreamTree(BeautifulStream::IOStream &ioStream)
    : ioStream(&ioStream)
{

}

}
