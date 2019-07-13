#include "Tutils/CachedStreamTree.h"

namespace Tutils
{

Tutils::CachedStreamTree::CachedStreamTree(Tutils::IOStream &ioStream)
    : StreamTree(ioStream)
{

}

CachedStreamTree::CachedStreamTree(Tutils::IOStream &ioStream,
                                   const std::vector<CachedStreamTree::StringCache> &rows)
    : CachedStreamTree(ioStream, std::vector<StringCache>(rows))
{

}

CachedStreamTree::CachedStreamTree(Tutils::IOStream &ioStream, std::vector<CachedStreamTree::StringCache> &&)
    : StreamTree(ioStream), rows(std::forward<std::vector<StringCache>>(rows))
{

}

void CachedStreamTree::addRow(const CachedStreamTree &tree)
{
    for (const StringCache &str : tree.getStringVector()) {
        rows.push_back(str);
    }
}

std::vector<std::string> CachedStreamTree::exec()
{
    std::vector<std::string> input;
    for (const StringCache &row: CachedStreamTree::getStringVector()) {
        ioStream->output(row.string);
        for (size_t i = 0; i < row.inputSize; i++) {
            input.push_back(
                (i == row.inputSize - 1)
                ? ioStream->input<std::string>(row.finalDelimiter)
                : ioStream->input<std::string>(row.delimiter)
            );
        }
        if (row.inputSize == 0) {
            ioStream->output("\n");
        }
    }
    return input;
}

std::vector<CachedStreamTree::StringCache> CachedStreamTree::getStringVector() const
{
    std::vector<StringCache> result(rows.size());
    for (size_t i = 0; i < rows.size(); i++) {
        result[i] = StringCache{
            Tree::tabSequence * Tree::tabSize + rows[i].string,
            rows[i].inputSize,
            rows[i].delimiter,
            rows[i].finalDelimiter,
        };
    }

    return result;
}


}