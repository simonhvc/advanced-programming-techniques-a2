#include "Bag.h"

Bag::Bag() {
    for(int duplicate = 0; duplicate < 2; duplicate++){
        for(int colours = 0; colours < 6; colours++){
            for(int shapes = 1; shapes < 7; shapes++){
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
    }
    //std::random_shuffle(all, 35);
}
LinkedList* Bag::getLinkedList() {
  return tiles;
}
bool Bag::hasTile(char color, int shape) {
  return tiles->hasTile(color, shape);
}
Tile* Bag::getTile(){
       return tiles->getRandomTile();
}
