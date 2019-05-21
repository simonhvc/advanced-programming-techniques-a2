#include "Board.h"

Board::Board(int y_size, int x_size){
      this->y_size = y_size;
      this->x_size = x_size;
}

int Board::placeTile(int x, int y, Tile* tile){
    int highestScore = 0;
    if (map[y][x] == NULL){
         map[y][x] = tile;
        for(int y_change = -1; y_change < 2; y_change += 2){
            if(colourScore(y_change, 0, tile->getColour(), 0, x, y) > highestScore){
                highestScore = colourScore(y_change, 0, tile->getColour(), 0, x, y);
            }
            if(shapeScore(y_change, 0, tile->getShape(), 0, x, y) > highestScore){
                highestScore = shapeScore(y_change, 0, tile->getShape(), 0, x, y);
            }
        }
        for(int x_change = -1; x_change < 2; x_change += 2){
            if(colourScore(0, x_change, tile->getColour(), 0, x, y) > highestScore){
                highestScore = colourScore(0, x_change, tile->getColour(), 0, x , y);
            }
        
            if(shapeScore(0, x_change, tile->getShape(), 0, x , y) > highestScore){
                highestScore = shapeScore(0, x_change, tile->getShape(), 0, x , y);
            }
        }    
    }
    return highestScore;
}

int Board::colourScore(int y_change, int x_change, Colour colour, int score, int x, int y){
    if(map[y + y_change][x + x_change] != NULL){
        if(map[y + y_change][x + x_change]->getColour() == colour ){
            score++;
            if(x_change > 0){
                x_change++;
                colourScore(0, x_change, colour, score, x , y);
            }
            if(x_change < 0){
                x_change--;
               colourScore(0, x_change, colour, score, x , y);
            }
            if(y_change > 0){
                y_change++;
                colourScore(y_change, 0, colour, score, x , y);
            }
            if(y_change < 0){
                y_change--;
                colourScore(y_change, 0, colour, score, x , y);
            }
        }
    }
    return score;
}
int Board::shapeScore(int y_change, int x_change, Shape shape, int score, int x, int y){
    if(map[y + y_change][x + x_change] != NULL){
        if(map[y + y_change][x + x_change]->getShape() == shape ){
            score++;
            if(x_change > 0){
                x_change++;
                shapeScore(0, x_change, shape, score, x , y);
            }
            if(x_change < 0){
                x_change--;
               shapeScore(0, x_change, shape, score, x , y);
            }
            if(y_change > 0){
                y_change++;
                shapeScore(y_change, 0, shape, score, x , y);
            }
            if(y_change < 0){
                y_change--;
                shapeScore(y_change, 0, shape, score, x , y);
            }
        }
    }
    return score;
}

std::string Board::toString(){
    std::string text = " ";
    std::string letters[26] = {"A", "B", "C", "D", "E", "F", "G",
                                "H", "I", "J", "K", "L", "M", "N",
                                "O", "P", "Q", "R", "S", "T", "U",
                                "V", "W", "X", "Y", "Z"};
    std::string numbers[26] = {"1", "2", "3", "4", "5", "6", "7",
                                "8", "9", "10", "11", "12", "13", "14",
                                "15", "16", "17", "18", "19", "20", "21",
                                "22", "23", "24", "25", "26"};

    for(int top = 0; top < x_size;top++){
        text += " " + numbers[top]; 
    }

    //text+= " \n--------------------\n";

    for(int y = 0; y < y_size;y++){
        for(int x = 0; x < x_size;x++){
            if(x == 0 ){
                text += "\n" + letters[y] + " |";
            }
            if(map[y][x] == NULL){
                    text += " |";
            }
            else{
                text += map[y][x]->getColour() + map[y][x]->getShape() + "|";
            }
        }
    }
   
    return text;
}