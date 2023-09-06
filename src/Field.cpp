#include "Field.h"

#include <algorithm>

#include "VectorExtensions.h"

Field::Field(const int width){
    size_ = width;
    field_ = std::vector<std::vector<char>>(width, std::vector<char>(width, ' '));
}

std::string Field::to_string() const{
    std::string table;
    
    for (int chunk_index = 0; chunk_index < size_; ++chunk_index)
    {
        const std::string line = VectorExtensions::join(field_[chunk_index], '|', true);

        table+= "\t\t";

        table += line;

        if (chunk_index != size_ - 1)
        {
            table += "\n\t\t";
            table += std::string(line.size(), '-');
            table += '\n';
        }
    }

    return table;
}

bool Field::is_someone_win() const{
    /*
    const auto size = field_.size();

    std::vector<char> principal_diagonal;
    for (size_t i = 0; i < size; ++i)
    {
        if (field_[i][i] != ' ')
            principal_diagonal.push_back(field_[i][i]);
    }

    std::sort(principal_diagonal.begin(), principal_diagonal.end());
    principal_diagonal.erase(std::unique(principal_diagonal.begin(), principal_diagonal.end()), principal_diagonal.end());

    if (principal_diagonal.size() == 1)
        return true;


    std::vector<char> secondary_diagonal;
    size_t k = size - 1;
    for (size_t i = 0; i < size; i++)
    {
        if (field_[i][k] != ' ')
            secondary_diagonal.push_back(field_[i][k--]);
    }

    std::sort(secondary_diagonal.begin(), secondary_diagonal.end());
    secondary_diagonal.erase(std::unique(secondary_diagonal.begin(), secondary_diagonal.end()), secondary_diagonal.end());

    if (secondary_diagonal.size() == 1)
        return true;

    return false;*/
    return false;
}

bool Field::add(const char ch, const int x, const int y){

    if (x >= size_ || y >= size_ || field_[x][y] != ' ')
        return false;
    
    field_[x][y] = ch;

    return true;
}
