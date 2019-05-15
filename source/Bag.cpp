#include <string>
#include <LinkedList.h>
#include <Tile.h>
#include <algorithm>

class Bag { 
    LinkedList* tiles = new LinkedList();
  
    Bag() {
        Tile* all[35];
        for(int colours = 0; colours < 6; colours++){
            for(int shapes = 0; shapes < 6; shapes++){
                all[colours + shapes] = new Tile(colours, shapes);
            }
        }
        std::random_shuffle(all, 35);
    }
    Tile* getTile(){
       return tiles->getHead;
    }
};
