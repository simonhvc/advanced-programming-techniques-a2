#include <string>
#include "LinkedList.h"
#include "Tile.h"

class Bag {
    public:
        Bag();
        Tile* getTile();
        LinkedList* getLinkedList();
        bool hasTile(char color, char shape);

    private:
        LinkedList* tiles = new LinkedList();
};
