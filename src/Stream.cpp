#include "Tutils/Stream.h"

namespace Tutils
{

void StreamWrapper::ignoreChar(char ignore)
{
    if (input->peek() == ignore) {
        input->ignore();
    }
}

void StreamWrapper::write(const std::string &outputText)
{
    if (!this->output) {
        return;
    }
    if (outputText.empty()) {
        return;
    }

    *this->output << outputText;
}

}
