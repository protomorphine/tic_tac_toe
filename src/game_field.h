#pragma once
#include <string>
#include <vector>

namespace game {

/**
 * \brief result of players Turn.
 */
enum class TurnResult { SUCCESS_TURN = 0, INVALID_COORDS = 1, NO_TURNS_ALLOWED = 2 };

/**
 * \brief represent game Field.
 */
class Field {
  /**
   * \brief adds passed char to Field.
   * \param ch char to Add.
   * \param x x coordinate.
   * \param y y coordinate.
   */
  TurnResult Add(char ch, int x, int y);

  /**
   * \brief checks cells for winner.
   * \param start start cell.
   * \param step step.
   * \param lastValueRatio multiplayer for field dimension, used as last loop
   * value. \return bool, indicates is someone won on checked cells.
   */
  bool Check(int start, int step, int lastValueRatio = 1) const;

  /**
   * \brief field dimension.
   */
  int dimension_;

  /**
   * \brief Field.
   */
  std::vector<char> field_;

 public:
  /**
   * \brief checks if someone win.
   * \return bool, indicates is someone win.
   */
  bool IsSomeoneWin() const;

  /**
   * \brief creates new instance of Field.
   * \param dimension dimension of generated Field.
   */
  explicit Field(int dimension);

  /**
   * \brief adds 'x' by passed coords.
   * \param x x coordinate.
   * \param y y coordinate.
   */
  TurnResult AddX(const int x, const int y) { return Add('X', x, y); }

  /**
   * \brief adds '0' by passed coords.
   * \param x x coordinate.
   * \param y y coordinate.
   */
  TurnResult AddO(const int x, const int y) { return Add('O', x, y); }

  /**
   * \brief represent field_ in single string to display on screen.
   * \return string representation of field_.
   */
  std::string ToString() const;

  /**
   * \brief returns field dimension.
   * \return dimension.
   */
  int inline dimension() const { return dimension_; }
};
}  // namespace game