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

bool Field::Check(int start, int step, int lastValueRatio) const {
    int xCount = 0, oCount = 0;

    for (int i = start; i < dimension_ * lastValueRatio; i += step) {
        switch (field_[i]) {
            case 'X':
                xCount++;
                break;
            case 'O':
                oCount++;
                break;
        }
    }

    if (xCount == dimension_ || oCount == dimension_)
        return true;

    return false;
}

bool Field::IsSomeoneWin() const {

    for (int i = 0; i < dimension_ * dimension_; i += dimension_) {
        if (Check(i, 1))
            return true;
    }

    for (int i = 0; i < dimension_; ++i) {
        if (Check(i, dimension_, dimension_))
            return true;
    }

    return Check(0, dimension_ + 1, dimension_) ||
            Check(dimension_ - 1, dimension_ - 1, dimension_);
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
