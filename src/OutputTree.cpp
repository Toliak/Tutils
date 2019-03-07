#include "OutputTree.h"

namespace BeautifulStream
{

OutputTree::OutputTree(const std::vector<std::string> &rows)
    : OutputTree(std::vector<std::string>(rows))
{

}

OutputTree::OutputTree(std::vector<std::string> &&rows)
    : rows(std::forward<std::vector<std::string>>(rows))
{

}

std::vector<std::string> OutputTree::getStringVector() const
{
    std::vector<std::string> result(rows.size());
    for (size_t i = 0; i < rows.size(); i++) {
        result[i] = tabSequence * tabSize + rows[i];
    }

    return result;
}

void OutputTree::addRow(const OutputTree &tree)
{
    for (const std::string &str : tree.getStringVector()) {
        OutputTree::addRow(str);
    }
}

std::ostream &operator<<(std::ostream &stream, const OutputTree &tree)
{
    for (const std::string &str : tree.getStringVector()) {
        stream << str << std::endl;
    }
    return stream;
}

}