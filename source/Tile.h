
#ifndef ASSIGN2_TILE_H
#define ASSIGN2_TILE_H
#include <string>
// Define a Colour type
typedef char Colour;

// Define a Shape type
typedef int Shape;

class Tile {
public:
   Tile(Colour colour, Shape shape);
   
   Shape getShape();
   Colour getColour();

   std::string toString();

private:
   Colour colour;
   Shape  shape;
};

#endif // ASSIGN2_TILE_H
