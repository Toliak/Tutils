#pragma once

#include <cstdlib>
#include <string>

namespace BeautifulStream
{

class Tree
{
protected:
    size_t tabSize = 4;
    std::string tabSequence = " ";

public:
    Tree() = default;
    Tree(const Tree &) = default;
    Tree(Tree &&) = default;

    virtual ~Tree() = default;

    size_t getTabSize() const noexcept
    {
        return tabSize;
    }

    void setTabSize(size_t tabSize) noexcept
    {
        Tree::tabSize = tabSize;
    }

    const std::string &getTabSequence() const noexcept
    {
        return tabSequence;
    }

    void setTabSequence(const std::string &tabSequence)
    {
        Tree::tabSequence = tabSequence;
    }

};

}