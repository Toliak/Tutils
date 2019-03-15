#pragma once

#include <ostream>
#include <vector>
#include <string>

#include "Tree.h"
#include "utilities.h"
#include "StreamTree.h"

namespace BeautifulStream
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

    explicit CachedStreamTree(BeautifulStream::IOStream &ioStream)
        : StreamTree(ioStream)
    {

    }

    explicit CachedStreamTree(BeautifulStream::IOStream &ioStream, const std::vector<StringCache> &rows)
        : CachedStreamTree(ioStream, std::vector<StringCache>(rows))
    {

    }

    explicit CachedStreamTree(BeautifulStream::IOStream &ioStream, std::vector<StringCache> &&)
        : StreamTree(ioStream), rows(std::forward<std::vector<StringCache>>(rows))
    {

    }

    void addRow(const std::string &string, size_t inputSize = 0, char delimiter = '\n', char finalDelimiter = '\n')
    {
        addRow(std::string(string), inputSize, delimiter, finalDelimiter);
    }

    void addRow(std::string &&string, size_t inputSize = 0, char delimiter = '\n', char finalDelimiter = '\n')
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

    void addRow(const CachedStreamTree &tree)
    {
        for (const StringCache &str : tree.getStringVector()) {
            rows.push_back(str);
        }
    }

    const std::vector<StringCache> &getRows() const noexcept
    {
        return rows;
    }

    std::vector<StringCache> getStringVector() const
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

    std::vector<std::string> exec()
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
};

}