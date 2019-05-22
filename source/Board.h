#include "Tile.h"
#include <string>
#include <iostream>

class Board{
    public:
        // Creates the boundaries used by methods and other classes to know the size of the board
        Board(int y_size, int x_size);

        //Places a tile on a given x and y location on the board
        int placeTile(int x, int y, Tile* tile);

        //Checks to see all 4 directions of the location that the tile is to be placed to ensure that the rules allow it to be placed
        //If there is a valid tile next to the starting location the straightline method is called in this direction to count the score to be given
        int isValid(int y, int x, Tile* tile, int y_change, int x_change);

        //A recursive algorithm which keeps calling itself untill there is no more tiles in a given direction or the total length is greater then 6
        //This then returns the score based off of the length
        int straightLine(int y_start, int x_start, int x_change, int y_change, int length, int score);

        int getIndexOfChar(char ch);

        //checks to see if a given location on the board is empty
        bool nullCheck(int y, int x);

        //allows for the first tile to be played at the start of the game in the middle of the board
        void firstTile(Tile* tile);

        //returns the y size of the board
        int getY();

        //returns the x size of the board
        int getX();

        //returns the contents of the board in readable format
        std::string toString();

    private:
      std::string letters[26] = {"A", "B", "C", "D", "E", "F", "G",
                                  "H", "I", "J", "K", "L", "M", "N",
                                  "O", "P", "Q", "R", "S", "T", "U",
                                  "V", "W", "X", "Y", "Z"};
        Tile* map[26][26]; //initalizes the max size of the board
        int x_size;
        int y_size;

};
