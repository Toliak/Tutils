#pragma once

#include <ostream>
#include <type_traits>

namespace Tutils
{

template<class T>
struct isArithmeticWithoutCvRef
{
    static constexpr bool value = std::is_arithmetic<
        typename std::remove_cv<typename std::remove_reference<T>::type>::type
    >::value;
};

template<class T>
struct isOstreamOverloaded
{
    static constexpr bool value = std::is_same<
        decltype(std::declval<std::ostream &>() << std::declval<T>()),
        std::ostream &
    >::value;
};

}