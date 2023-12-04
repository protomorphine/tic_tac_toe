#include "game_field.h"

#include <algorithm>
#include <iostream>

#include "vector_extensions.h"

game::Field::Field(const int dimension) : dimension_(dimension), field_(dimension_ * dimension_, ' ') {}

std::string game::Field::ToString() const {
  std::stringstream stream;

  const std::vector<std::vector<char>> by_chunks = VectorExtensions::Chunks(field_, dimension_);

  for (size_t chunk_index = 0; chunk_index < by_chunks.size(); ++chunk_index) {
    stream << '\t';
    stream << VectorExtensions::Join(by_chunks.at(chunk_index), " | ");

    if (chunk_index != dimension_ - 1) {
      stream << "\n\t";
      stream << std::string(15, '-');
      stream << '\n';
    }
  }

  return stream.str();
}

bool game::Field::Check(int start, int step, int lastValueRatio) const {
  int xCount = 0;
  int oCount = 0;

  for (int i = start; i < dimension_ * lastValueRatio; i += step) {
    switch (field_[i]) {
      case 'X':
        xCount++;
        break;
      case 'O':
        oCount++;
        break;
      default:
        break;
    }
  }

  if (xCount == dimension_ || oCount == dimension_) {
    return true;
  }

  return false;
}

bool game::Field::IsSomeoneWin() const {
  for (int i = 0; i < dimension_ * dimension_; i += dimension_) {
    if (Check(i, 1)) {
      return true;
    }
  }

  for (int i = 0; i < dimension_; ++i) {
    if (Check(i, dimension_, dimension_)) {
      return true;
    }
  }

  return Check(0, dimension_ + 1, dimension_) || Check(dimension_ - 1, dimension_ - 1, dimension_);
}

game::TurnResult game::Field::Add(const char ch, const int x, const int y) {
  size_t allowed_positions = std::count_if(field_.begin(), field_.end(), [](const char& cell) { return cell == ' '; });

  if (allowed_positions == 0) {
    return TurnResult::NO_TURNS_ALLOWED;
  }

  if (x >= dimension_ || y >= dimension_ || field_[y + (dimension_ * x)] != ' ') {
    return TurnResult::INVALID_COORDS;
  }

  field_[y + (dimension_ * x)] = ch;
  return TurnResult::SUCCESS_TURN;
}
