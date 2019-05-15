#include <bag.h>
  
Bag::Bag() {
    for(int colours = 0; colours < 6; colours++){
        for(int shapes = 0; shapes < 6; shapes++){
            if(colours == 0){
            tiles->addToFront(new Tile('R', shapes));
            }
            if(colours == 1){
            tiles->addToFront(new Tile('O', shapes));
            }
            if(colours == 2){
            tiles->addToFront(new Tile('Y', shapes));
            }
            if(colours == 3){
            tiles->addToFront(new Tile('G', shapes));
            }
            if(colours == 4){
            tiles->addToFront(new Tile('B', shapes));
            }
            if(colours == 5){
            tiles->addToFront(new Tile('P', shapes));
            }
        }
    }
    //std::random_shuffle(all, 35);
}
Tile* Bag::getTile(){
       return tiles->getHead;
}

