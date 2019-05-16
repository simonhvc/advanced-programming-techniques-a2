
#ifndef ASSIGN2_NODE_H
#define ASSIGN2_NODE_H

#include "Tile.h"

class Node {
public:

   Node(Tile* tile, Node* next);
   Node(Node& other);
   Tile* getTile();
   Node* getNext();
   void setTile(Tile* tile);
   void setNext(Node* next);

private:
   Tile*    tile;
   Node*    next;
};

#endif // ASSIGN2_NODE_H
