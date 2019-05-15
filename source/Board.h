#include <Tile.h>
#include <string>

class Board{
    public:
    Board(int x_size, int y_size);

    int placeTile(int x, int y, Tile tile);

    std::string toString();



};