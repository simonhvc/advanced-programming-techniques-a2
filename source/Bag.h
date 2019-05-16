#include <string>
#include "LinkedList.h"
#include "Tile.h"

class Bag {
    public:
        Bag();
        Tile* getTile();

    private:
        LinkedList* tiles = new LinkedList();
};
