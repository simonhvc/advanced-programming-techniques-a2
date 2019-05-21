#include "Board.h"

Board::Board(){
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
    std::string text = "  0  1  2  3  4  5  \n--------------------\nA |";
    for(int y = 0; y<6;y++){
        for(int x = 0; x<6;x++){
            if(x == 0 && y == 1){
                text += "\nB |";
            }
            if(x == 0 && y == 2){
                text += "\nC |";
            }
            if(x == 0 && y == 3){
                text += "\nD |";
            }
            if(x == 0 && y == 4){
                text += "\nE |";
            }
            if(x == 0 && y == 5){
                text += "\nF |";
            }
            if(map[0][x] == NULL){
                text += " |";
            }
            else{
                text += map[0][x]->getColour() + map[0][x]->getShape() + "|";
            }
        }
    }
   
    return text;
}