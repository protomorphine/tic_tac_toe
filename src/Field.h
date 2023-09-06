#pragma once
#include <string>
#include <vector>

enum class AddedResult {
    SUCCESS,
    FAIL
};

/**
 * \brief represent game Field.
 */
class Field
{
    /**
     * \brief adds passed char to Field.
     * \param ch char to add.
     * \param x x coordinate.
     * \param y y coordinate.
     */
    bool add(char ch, int x, int y);

    /**
     * \brief size of Field.
     */
    int size_;
 
    /**
     * \brief Field.
     */
    std::vector<std::vector<char>> field_;

public:
 
    bool is_someone_win() const;
 
    /**
     * \brief creates new instance of Field.
     * \param width width of generated Field.
     */
    explicit Field(int width);

    /**
     * \brief adds 'x' by passed coords.
     * \param x x coordinate.
     * \param y y coordinate.
     */
    bool add_x(const int x, const int y) { return add('X', x, y);}

    /**
     * \brief adds '0' by passed coords.
     * \param x x coordinate.
     * \param y y coordinate.
     */
    bool add_0(const int x, const int y){ return add('0', x, y); }
    
    /**
     * \brief represent field_ in single string to display on screen.
     * \return string representation of field_.
     */
    std::string to_string() const;
};
