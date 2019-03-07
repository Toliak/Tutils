#pragma once

#include <ostream>
#include <vector>
#include <string>

#include "utilities.h"

namespace BeautifulStream
{

class OutputTree
{
protected:
    std::vector<std::string> rows = {};
    size_t tabSize = 4;
    std::string tabSequence = " ";

public:
    OutputTree() = default;
    OutputTree(const OutputTree &) = default;
    OutputTree(OutputTree &&) = default;
    explicit OutputTree(const std::vector<std::string> &);
    explicit OutputTree(std::vector<std::string> &&);

    void addRow(const std::string &string)
    {
        addRow(std::string(string));
    }

    void addRow(std::string &&string)
    {
        rows.emplace_back(std::forward<std::string>(string));
    }

    void addRow(const OutputTree &);

    const std::vector<std::string> &getRows() const noexcept
    {
        return rows;
    }

    size_t getTabSize() const noexcept
    {
        return tabSize;
    }

    void setTabSize(size_t tabSize)
    {
        OutputTree::tabSize = tabSize;
    }

    const std::string &getTabSequence() const noexcept
    {
        return tabSequence;
    }

    void setTabSequence(const std::string &tabSequence)
    {
        OutputTree::tabSequence = tabSequence;
    }

    std::vector<std::string> getStringVector() const;

    friend std::ostream &operator<<(std::ostream &, const OutputTree &);
};

}