
#include "Tile.h"

Tile::Tile(Colour colour, Shape shape)
{
   this -> colour = colour;
   this -> shape = shape;      
}

Shape Tile::getShape(){
    return shape;
}

Colour Tile::getColour(){
    return colour;
}
