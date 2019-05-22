#include "Board.h"

Board::Board(int y_size, int x_size){
      this->y_size = y_size;
      this->x_size = x_size;
}

int Board::placeTile(int x, int y, Tile* tile){
    std::cout << "1" << '\n';
    if (map[y][x] == NULL){
         int score = 0;
         if(isValid(y, x, tile, 1, 0) != -1){
           std::cout << "2" << '\n';
             score += isValid(y, x, tile, 1, 0); //UP
         }
         if(isValid(y, x, tile, -1, 0) != -1){
           std::cout << "3" << '\n';
             score += isValid(y, x, tile, -1, 0); //DOWN
         }
         if(isValid(y, x, tile, 0, 1) != -1){
           std::cout << "4" << '\n';
             score += isValid(y, x, tile, 0, 1); //RIGHT
         }
         if(isValid(y, x, tile, 0, -1) != -1){
           std::cout << "5" << '\n';
             score += isValid(y, x, tile, 0, -1); //LEFT
         }
         if (score > 0){
           std::cout << "6" << '\n';
             map[y][x] = tile;
         }
         std::cout << "7" << '\n';
        return score;
    }
    return 0;
}

int Board::isValid(int y, int x, Tile* tile, int y_change, int x_change){
  std::cout << "Checking Null" << '\n';
   if(nullCheck(y + y_change, x + x_change) == false){
        return 0;
   }
    std::cout << "6" << '\n';
   if(y + y_change > y_size || x + x_change > x_size || y + y_change < 0 || x + x_change < 0){
       return 0;
   }
    std::cout << y + y_change << '\n';
   if(map[y + y_change][x + x_change]->getShape() == tile->getShape() || map[y + y_change][x]->getColour() == tile->getColour()){
     std::cout << "checking straightline" << '\n';
       return straightLine(y, x, x_change, y_change, 0, 0);
       std::cout << "done checking straightline" << '\n';
   }

   std::cout << "done checking relative pos" << '\n';
    return -1;
}

int Board::straightLine(int y_start, int x_start, int x_change, int y_change, int length, int score){
    if(length > 6){
        return -1;
    }
      if(y_start + y_change > y_size || x_start + x_change > x_size){
       return score;
   }
   if(y_start + y_change < 0 || x_start + x_change < 0){
       return score;
   }
    if(y_change > 0){
        if(nullCheck(y_start + y_change, x_start + x_change) == true){
            score++;
            length++;
            y_change++;
            straightLine(y_start, x_start, x_change, y_change, length, score);
        }
    }
    if(y_change < 0){
             if(nullCheck(y_start + y_change, x_start + x_change) == true){
            score++;
            length++;
            y_change--;
            straightLine(y_start, x_start, x_change, y_change, length, score);
             }
    }
    if(x_change > 0){
             if(nullCheck(y_start + y_change, x_start + x_change) == true){
            score++;
            length++;
            x_change++;
            straightLine(y_start, x_start, x_change, y_change, length, score);
             }
    }
    if(x_change < 0){
             if(nullCheck(y_start + y_change, x_start + x_change) == true){
            score++;
            length++;
            x_change--;
            straightLine(y_start, x_start, x_change, y_change, length, score);
             }
    }
    if(length == 6){
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

int Board::getIndexOfChar(char ch) {
  int index = 0;
  for(int i = 0; i < 26; i++) {
    if (letters[i].at(0) == ch) {
      index = i;
    }
  }

  return index;
}
void Board::firstTile(Tile* tile){
    int x = (x_size - 1) /2;
    int y = (y_size - 1) /2;
    map[y][x] = tile;
}

std::string Board::toString(){
    std::string text = " ";

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
