#pragma once

#include "meta.h"
#include <algorithm>
#include <sstream>
#include <vector>

namespace Tutils
{

template<
    typename T,
    typename std::enable_if<
        isArithmeticWithoutCvRef<T>::value,
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
        isOstreamOverloaded<T>::value && !isArithmeticWithoutCvRef<T>::value,
        int
    >::type = 0
>
std::string toString(const T &value)
{
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
T fromString(const std::string &string)
{
    T variable;
    std::istringstream ss(string);
    ss >> variable;
    return variable;
}

template<>
std::string fromString(const std::string &string)
{
    return string;
}

template<class T>
std::vector<std::string> splitString(std::string string, const std::string &separator, bool removeEmpty = true)
{
    if (separator.empty()) {
        return {std::move(string)};
    }
    if (string.find(separator) == std::string::npos) {
        return {std::move(string)};
    }

    std::vector<std::string> result;

    while (true) {
        size_t index = string.find(separator);

        if (index != std::string::npos) {
            result.push_back(string.substr(0, index));          // Save current part
            string = string.substr(index + 1);                  // Cut
        } else {
            result.emplace_back(std::move(string));
            break;
        }

        if (removeEmpty) {      // Remove empty strings
            result.erase(
                std::remove(result.begin(), result.end(), ""),
                result.end()
            );
        }
    }

    return result;
}

}

template<class T>
std::basic_string<T> operator*(const std::basic_string<T> &string, int times)
{
    if (times == 0) {
        return "";
    }
    if (times == 1) {
        return string;
    }

    if (times < 0) {
        std::string reversed(string);
        std::reverse(reversed.begin(), reversed.end());

        std::string result;
        for (int i = times; i < 0; i++) {
            result += reversed;
        }

        return result;
    }

    std::string result;
    for (size_t i = 0; i < times; i++) {
        result += string;
    }

    return result;
}