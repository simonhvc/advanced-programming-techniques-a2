#include <Tile.h>
#include <string>

class Board{
    public:
        Board();

        int placeTile(int x, int y, Tile tile);

        std::string toString();

    private:
        Tile* map[26][26];

};