#pragma once
#include <string>
#include <vector>

class VectorExtensions
{
public:

    /**
     * \brief joins all vector chars into single string with delimiter.
     * \param vec vector of chars.
     * \param delimiter delimiter char.
     * \param with_whitespace should insert whitespace before element and after.
     * \return string.
     */
    static std::string join(const std::vector<char>& vec, char delimiter, bool with_whitespace = true);
};
