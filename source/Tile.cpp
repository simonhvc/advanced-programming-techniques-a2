
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

std::string Tile::toString(){
    
   // std::string unicode[6] = {\u20dd, \u2727, \u2662, \u20de,\u2736, \u1f340};
    Colour colours[6] = {'R', 'O', 'Y', 'G', 'B', 'P'};
    std::string shapes[6] = {"1","2","3","4","5","6"};
    std::string colourCodes[6] = {"\x1B[31m", "\x1B[93m", "\x1B[32m", "\x1B[34m", "\x1B[35m"};
    for(int i = 0; i < 6; i++){
        if(colours[i] == colour){
            return colourCodes[i] + colours[i] + shapes[shape] + "\x1B[0m";
        }
    }
    return "";
}
