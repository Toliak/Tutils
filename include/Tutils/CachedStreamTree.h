#pragma once

#include <ostream>
#include <vector>
#include <string>

#include "Tree.h"
#include "utilities.h"
#include "StreamTree.h"

namespace Tutils
{

class CachedStreamTree: public StreamTree
{
private:
    using StreamTree::input;
    using StreamTree::output;

    struct StringCache
    {
        std::string string;
        size_t inputSize = 0;
        char delimiter = '\n';
        char finalDelimiter = '\n';
    };


protected:
    std::vector<StringCache> rows = {};

public:
    CachedStreamTree(const CachedStreamTree &) = default;
    CachedStreamTree(CachedStreamTree &&) noexcept = default;

    ~CachedStreamTree() override = default;

    explicit CachedStreamTree(Tutils::IOStream &ioStream);

    explicit CachedStreamTree(Tutils::IOStream &ioStream, const std::vector<StringCache> &rows);

    explicit CachedStreamTree(Tutils::IOStream &ioStream, std::vector<StringCache> &&);

    void addRow(const std::string &string, size_t inputSize = 0, char delimiter = '\n', char finalDelimiter = '\n');

    void addRow(std::string &&string, size_t inputSize = 0, char delimiter = '\n', char finalDelimiter = '\n');

    void addRow(const CachedStreamTree &tree);

    const std::vector<StringCache> &getRows() const noexcept;

    std::vector<StringCache> getStringVector() const;

    std::vector<std::string> exec();
};



inline void CachedStreamTree::addRow(const std::string &string, size_t inputSize, char delimiter, char finalDelimiter)
{
    addRow(std::string(string), inputSize, delimiter, finalDelimiter);
}

inline void CachedStreamTree::addRow(std::string &&string, size_t inputSize, char delimiter, char finalDelimiter)
{
    rows.emplace_back(
        StringCache{
            std::forward<std::string>(string),
            inputSize,
            delimiter,
            finalDelimiter
        }
    );
}

inline const std::vector<CachedStreamTree::StringCache> &CachedStreamTree::getRows() const noexcept
{
    return rows;
}

}