#pragma once

#include <ostream>
#include <vector>
#include <string>

#include "Tree.h"
#include "utilities.h"

namespace BeautifulStream
{

class CachedTree: public Tree
{
    std::vector<std::string> rows = {};

public:
    CachedTree() = default;
    CachedTree(const CachedTree &) = default;
    CachedTree(CachedTree &&) = default;

    explicit CachedTree(const std::vector<std::string> &);
    explicit CachedTree(std::vector<std::string> &&);

    void addRow(const std::string &string)
    {
        addRow(std::string(string));
    }

    void addRow(std::string &&string)
    {
        rows.emplace_back(std::forward<std::string>(string));
    }

    void addRow(const CachedTree &);

    const std::vector<std::string> &getRows() const noexcept
    {
        return rows;
    }

    std::vector<std::string> getStringVector() const;

    friend std::ostream &operator<<(std::ostream &, const CachedTree &);
};

}