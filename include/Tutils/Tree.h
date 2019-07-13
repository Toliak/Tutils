#pragma once

#include <cstdlib>
#include <string>

namespace Tutils
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

    size_t getTabSize() const noexcept;

    void setTabSize(size_t tabSize) noexcept;

    const std::string &getTabSequence() const noexcept;

    void setTabSequence(const std::string &tabSequence);

};



inline size_t Tree::getTabSize() const noexcept
{
    return tabSize;
}

inline void Tree::setTabSize(size_t tabSize) noexcept
{
    Tree::tabSize = tabSize;
}

inline const std::string &Tree::getTabSequence() const noexcept
{
    return tabSequence;
}

inline void Tree::setTabSequence(const std::string &tabSequence)
{
    Tree::tabSequence = tabSequence;
}

}