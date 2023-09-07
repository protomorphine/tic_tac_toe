#include <string>
#include "vector_extensions.h"

std::string VectorExtensions::Join(const std::vector<char>& vec, char delimiter, bool with_whitespace){

    std::string joined;

    for (size_t i = 0; i < vec.size(); ++i) {

        if (with_whitespace) {
            joined += ' ';
            joined += vec[i];
            joined += ' ';
        } else {
            joined += vec[i];
        }

        if (i != vec.size() - 1)
            joined += delimiter;
    }

    return joined;
}