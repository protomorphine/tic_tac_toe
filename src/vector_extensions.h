#pragma once
#include <string>
#include <vector>
#include <stdexcept>

/**
 * \brief some extension methods to work with vectors.
 */
class VectorExtensions
{
public:

    /**
     * \brief separate vector by Chunks.
     * \param vec vector.
     * \param chunk_length chunk length.
     * \return vector, separated by chunks.
     */
    template<typename T>
    static std::vector<std::vector<T>> Chunks(const std::vector<T>& vec, unsigned short chunk_length){

        if (vec.size() % chunk_length > 0)
            throw std::invalid_argument("the length of the vector must be divisible by chunk_length without a remainder");

        std::vector<std::vector<T>> chunks;

        for (size_t i = 0; i < vec.size(); i += chunk_length) {

            std::vector<T> chunk;

            for (size_t j = i; j < i + chunk_length; ++j)
                chunk.push_back(vec.at(j));

            chunks.push_back(chunk);

        }

        return chunks;
    }


    /**
 * \brief joins all vector chars into single string with delimiter.
 * \param vec vector of chars.
 * \param delimiter delimiter char.
 * \param with_whitespace should insert whitespace before element and after.
 * \return string.
 */
    static std::string Join(const std::vector<char>& vec, char delimiter, bool with_whitespace = true);
};
