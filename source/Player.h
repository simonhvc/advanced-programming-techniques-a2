#include <string>
#include "LinkedList.h"
#include "Bag.h"

class Player { 
    
    public:
        Player(std::string name);

        void Draw(Bag* bag, int tiles);

        void handToString();

        void updateScore(int score);

        int getScore();

    private:
        std::string name, studentNumber, Email;
        int score;
        LinkedList* hand = new LinkedList();
};