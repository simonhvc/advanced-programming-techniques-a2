#include <string>
#include "LinkedList.h"
#include "Tile.h"

class Bag {
    public:
        Bag();
        Tile* getTile();
        LinkedList* getLinkedList();
        bool hasTile(char color, int shape);
        void fillBag();
        void addToBag(Tile* tile);

    private:
        LinkedList* tiles = new LinkedList();
};
