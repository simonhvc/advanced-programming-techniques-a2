#include <bag.h>
  
    Bag::Bag() {
        Tile* all[35];
        for(int colours = 0; colours < 6; colours++){
            for(int shapes = 0; shapes < 6; shapes++){
                all[colours + shapes] = new Tile(colours, shapes);
            }
        }
        std::random_shuffle(all, 35);
    }
    Tile* Bag::getTile(){
       return tiles->getHead;
    }
};
