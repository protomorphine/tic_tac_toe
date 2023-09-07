#include <iostream>
#include "game_field.h"

#include "vector_extensions.h"

Field::Field(const int dimension){
    dimension_ = dimension;
    field_ = std::vector<char>(dimension_ * dimension_, ' ');
}

std::string Field::ToString() const {

    std::string table;

    const std::vector<std::vector<char>> by_chunks = VectorExtensions::Chunks(field_, dimension_);

    for (int chunk_index = 0; chunk_index < by_chunks.size(); ++chunk_index)
    {
        const std::string line = VectorExtensions::Join(by_chunks.at(chunk_index), '|');

        table+= "\t";

        table += line;

        if (chunk_index != dimension_ - 1)
        {
            table += "\n\t";
            table += std::string(line.size(), '-');
            table += '\n';
        }
    }

    return table;
}

bool Field::IsSomeoneWin() const{
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

TurnResult Field::Add(const char ch, const int x, const int y){

    int allowed_positions = 0;
    for (char &cell: field_) {
        if ( cell == ' ' )
            allowed_positions++;
    }

    if (allowed_positions == 0)
        return TurnResult::NO_TURNS_ALLOWED;

    if (x >= dimension_ || y >= dimension_ || field_[y + (dimension_ * x)] != ' ')
        return TurnResult::INVALID_COORDS;
    
    field_[y + (dimension_ * x)] = ch;

    return TurnResult::SUCCESS_TURN;
}
