#include "Tutils/IOStream.h"
#include "Tutils/StreamTree.h"

namespace Tutils
{

Tutils::StreamTree::StreamTree(Tutils::IOStream &ioStream)
    : ioStream(&ioStream)
{

}

}
