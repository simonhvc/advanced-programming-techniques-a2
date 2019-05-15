#include <string>
#include <LinkedList.h>
#include <Tile.h>
#include <algorithm>

class Bag { 
    public:
        Bag();

        Tile* getTile();


    private:
        LinkedList* tiles = new LinkedList();



};