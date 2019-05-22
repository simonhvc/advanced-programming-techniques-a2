#include "Tile.h"
#include <string>
#include <iostream>

class Board{
    public:
        Board(int y_size, int x_size);

        int placeTile(int x, int y, Tile* tile);

        int colourScore(int y_change, int x_change, Colour colour, int score, int x, int y);

        int shapeScore(int y_change, int x_change, Shape shape, int score, int x, int y);

        int isValid(int y, int x, Tile* tile, int y_change, int x_change);

        int straightLine(int x_start, int y_start, int x_change, int y_change, int length);

        int getIndexOfChar(char ch);

        bool nullCheck(int y, int x);

        void firstTile(Tile* tile);

        int getY();

        int getX();

        std::string toString();

    private:
      std::string letters[26] = {"A", "B", "C", "D", "E", "F", "G",
                                  "H", "I", "J", "K", "L", "M", "N",
                                  "O", "P", "Q", "R", "S", "T", "U",
                                  "V", "W", "X", "Y", "Z"};
        Tile* map[26][26];
        int x_size;
        int y_size;

};
