#pragma once

#include <istream>
#include <ostream>

namespace Tutils
{

class StreamWrapper
{
    std::ostream *output = nullptr;
    std::istream *input = nullptr;

public:
    explicit StreamWrapper(std::ostream &output)
        : output(&output)
    {}

    explicit StreamWrapper(std::istream &input)
        : input(&input)
    {}

    StreamWrapper(std::ostream &output, std::istream &input)
        : output(&output), input(&input)
    {}

    StreamWrapper(const StreamWrapper &wrapper) = default;

    StreamWrapper(StreamWrapper &&) = delete;

    StreamWrapper &operator=(const StreamWrapper &wrapper) = default;

    StreamWrapper &operator=(StreamWrapper &&) = delete;

    void ignoreChar(char ignore = '\n');

    void write(const std::string &outputText);

    /**
     * @brief Read value from input stream
     * @tparam T Value type
     * @param outputText Hint before read
     * @return value
     */
    template<
        typename T,
        typename std::enable_if<
            !std::is_same<T, std::string>::value,
            int
        >::type = 0
    >
    T read(const std::string &outputText = "")
    {
        this->write(outputText);

        if (!this->input) {
            return {};
        }

        T value;
        *this->input >> value;
        return value;
    }

    /**
     * @brief String specialization
     * @param outputText Hint before read
     * @return std::string
     */
    template<
        typename T,
        typename std::enable_if<
            std::is_same<T, std::string>::value,
            int
        >::type = 0
    >
    T read(const std::string &outputText = "")
    {
        this->write(outputText);

        if (!this->input) {
            return {};
        }

        this->ignoreChar('\n');

        std::string result;
        std::getline(*this->input, result);
        return result;
    }
};

}