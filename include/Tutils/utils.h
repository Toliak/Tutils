#pragma once

#include <string>
#include <type_traits>
#include <ostream>
#include <sstream>
#include <vector>
#include <iostream>

namespace Tutils
{

template<
    typename T,
    typename std::enable_if<
        std::is_arithmetic<
            typename std::remove_cv<typename std::remove_reference<T>::type>::type
        >::value,
        int
    >::type = 0
>
std::string toString(T value)
{
    return std::to_string(value);
}

template<
    typename T,
    typename std::enable_if<
        std::is_same<
            decltype(std::declval<std::ostream &>() << std::declval<T>()),
            std::ostream &
        >::value
            && !std::is_arithmetic<
                typename std::remove_cv<typename std::remove_reference<T>::type>::type
            >::value,
        int
    >::type = 0
>
std::string toString(const T &value)
{
    std::cout << "Stream!" << std::endl;
    std::ostringstream stream;
    stream << value;
    return stream.str();
}

inline std::string toString(const std::string &value)
{
    return value;
}

inline std::string toString(const char *value)
{
    return std::string(value);
}

template<class T>
inline T fromString(const std::string &string)
{
    T variable;
    std::istringstream ss(string);
    ss >> variable;
    return variable;
}

template<class T>
inline std::vector<std::basic_string<T>> splitString(std::basic_string<T> string, const std::basic_string<T> &separator)
{
    std::vector<std::string> result;

    while (true) {
        size_t index = string.find(separator);
        if (index != -1) {
            result.push_back(string.substr(0, index));
            string = string.substr(index + 1);
        } else {
            result.emplace_back(std::move(string));
            break;
        }
    }

    return result;
}

}

template<class T>
std::basic_string<T> operator*(const std::basic_string<T> &string, size_t times)
{
    std::string result;
    for (size_t i = 0; i < times; i++) {
        result += string;
    }
    return result;
}