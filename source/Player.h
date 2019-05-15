#include <string>
#include <LinkedList.h>
#include <Bag.cpp>

class Player { 
    
    public:
        Player(std::string name, std::string studentNumber, std::string Email);
        
        void Draw(Bag bag, int amount);

        void handToString();

    private:
        std::string name, studentNumber, Email;
        int score;
        LinkedList* hand = new LinkedList();
};