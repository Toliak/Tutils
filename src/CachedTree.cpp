#include "CachedTree.h"

namespace BeautifulStream
{

CachedTree::CachedTree(const std::vector<std::string> &rows)
    : CachedTree(std::vector<std::string>(rows))
{

}

CachedTree::CachedTree(std::vector<std::string> &&rows)
    : rows(std::forward<std::vector<std::string>>(rows))
{

}

std::vector<std::string> CachedTree::getStringVector() const
{
    std::vector<std::string> result(rows.size());
    for (size_t i = 0; i < rows.size(); i++) {
        result[i] = Tree::tabSequence * Tree::tabSize + rows[i];
    }

    return result;
}

void CachedTree::addRow(const CachedTree &tree)
{
    for (const std::string &str : tree.getStringVector()) {
        CachedTree::addRow(str);
    }
}

std::ostream &operator<<(std::ostream &stream, const CachedTree &tree)
{
    for (const std::string &str : tree.getStringVector()) {
        stream << str << std::endl;
    }
    return stream;
}

}