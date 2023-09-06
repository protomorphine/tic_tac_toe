#include "VectorExtensions.h"

#include <string>

std::string VectorExtensions::join(const std::vector<char>& vec, const char delimiter, const bool with_whitespace){
    std::string joined;

    for (size_t i = 0; i < vec.size(); ++i)
    {
        if (with_whitespace)
            joined += ' ';

        joined += vec[i];

        if (with_whitespace)
            joined += ' ';

        if (i != vec.size() - 1)
            joined += delimiter;
    }

    return joined;
}