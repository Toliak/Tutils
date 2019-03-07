#pragma once

#include <string>
#include <sstream>
#include <iostream>

namespace BeautifulStream
{

// Переопределение типов, доступных для std::to_string в int
template <class T>
struct __ToStringRemap
{
    using type = T;
};

template <>
struct __ToStringRemap<unsigned long>
{
    using type = int;
};

template <>
struct __ToStringRemap<long>
{
    using type = int;
};

template <>
struct __ToStringRemap<unsigned int>
{
    using type = int;
};

template <>
struct __ToStringRemap<int>
{
    using type = int;
};

template <>
struct __ToStringRemap<unsigned long long>
{
    using type = int;
};

template <>
struct __ToStringRemap<long long>
{
    using type = int;
};

template <>
struct __ToStringRemap<double>
{
    using type = int;
};

template <>
struct __ToStringRemap<float>
{
    using type = int;
};

// Выполнение через поток
template <class N, class T>
struct __ToString
{
    std::string value;
    explicit __ToString(const T &value)
    {
        std::ostringstream ss;
        ss << value;
        __ToString::value = ss.str();
    }
};

// Выполнение через std::to_string
template <class T>
struct __ToString<int, T>
{
    std::string value;
    explicit __ToString(const T &value)
    {
        __ToString::value = std::to_string(value);
    }
};

// Преобразует тип в строку через std::to_string или через вывод в поток
template <class T>
std::string toString(const T &value)
{
    return __ToString<typename __ToStringRemap<T>::type, T>(value).value;
}

}

template <class T>
std::basic_string<T> operator*(const std::basic_string<T> &string, size_t times)
{
    std::string result;
    for (size_t i = 0; i < times; i++) {
        result += string;
    }
    return result;
}