#include "Board.h"

Board::Board(int y_size, int x_size){
      this->y_size = y_size;
      this->x_size = x_size;
}

int Board::placeTile(int x, int y, Tile* tile){
    if (map[y][x] == NULL){
         int score = isValid(y, x, tile, true, 0, 0, 0);
         if (score > 0){
             map[y][x] = tile;
         }
        return score;
    }
    return 0;
}

int Board::isValid(int y, int x, Tile* tile, bool result, int score, int y_change, int x_change){
    for(int y_change = -1; y_change < 2; y_change += 2){
            if(map[y + y_change][x]->getColour() == tile->getColour()){
                if(y_change > 0){
                    y_change++;
                    score++;
                   score += isValid(y,x,tile,result,score,y_change,x_change);
                }
                if(y_change < 0){
                    y_change--;
                    score++;
                  score += isValid(y,x,tile,result,score,y_change,x_change);
                }
                
            }
                else if(nullCheck(y + y_change, x)){
                    result = false;
                }
             if(map[y + y_change][x]->getShape() == tile->getShape()){
                if(y_change > 0 ){
                    y_change++;
                    score++;
                   score += isValid(y,x,tile,result,score,y_change,x_change);
                }
                if(y_change < 0){
                    y_change--;
                    score++;
                  score += isValid(y,x,tile,result,score,y_change,x_change);
                }
            }
                else if(nullCheck(y + y_change, x)){
                    result = false;
                }
        }
        for(int x_change = -1; x_change < 2; x_change += 2){
            if(map[y][x + x_change]->getColour() == tile->getColour()){
                if(x_change > 0){
                    x_change++;
                    score++;
                   score += isValid(y,x,tile,result,score,y_change,x_change);
                }
                if(x_change < 0){
                    x_change--;
                    score++;
                  score += isValid(y,x,tile,result,score,y_change,x_change);
                }
                
            }
                else if(nullCheck(y, x + x_change)){
                    result = false;
                }
             if(map[y][x + x_change]->getShape() == tile->getShape()){
                if(x_change > 0){
                    x_change++;
                    score++;
                   score += isValid(y,x,tile,result,score,y_change,x_change);
                }
                if(x_change < 0){
                    x_change--;
                    score++;
                  score += isValid(y,x,tile,result,score,y_change,x_change);
                }
            }
            else if(nullCheck(y, x + x_change)){
                    result = false;
                }
        }
        if (result == false){
            score = 0;
        }
        if (x_change > 6 || x_change < -6){
            score = 0;
        }
        if (y_change > 6 || y_change < -6){
            score = 0;
        }
        if (x_change == 6 || x_change == -6){
            score += 6;
            std::cout << "QWIRKLE!!!";
        }
        if (y_change == 6 || y_change == -6){
            score += 6;
            std::cout << "QWIRKLE!!!";
        }
    return score;
}

bool Board::nullCheck(int y, int x){
    if(map[y][x] == NULL){
        return false;
    }
    return true;
}

int Board::getX(){
    return x_size;
}

int Board::getY(){
    return y_size;
}

void Board::firstTile(Tile* tile){
    int x = x_size/2;
    int y = y_size/2;
    map[y][x] = tile;
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
                text += map[y][x]->toString() + "|";
            }
        }
    }
   
    return text;
}