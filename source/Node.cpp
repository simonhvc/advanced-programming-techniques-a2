
#include "Node.h"

Node::Node(Tile* tile, Node* next)
{
   this -> tile = tile;
   this -> next = next;      
}

Tile* Node::getTile(){
   return tile;
}

Node* Node::getNext(){
   return next;
}

void Node::setTile(Tile* tile){
   this -> tile = tile;
}

void Node::setNext(Node* next){
   this -> next = next;
}

Node::Node(Node& other)
{
  // other.tile -> tile;
   //other.next -> next;
}
