#include "Tile.h"
#include <string>

class Board{
    public:
        Board(int y_size, int x_size);

        int placeTile(int x, int y, Tile* tile);

        int colourScore(int y_change, int x_change, Colour colour, int score, int x, int y);

        int shapeScore(int y_change, int x_change, Shape shape, int score, int x, int y);

        int getY();

        int getX();

        std::string toString();

    private:
        Tile* map[26][26];
        int x_size;
        int y_size;

};