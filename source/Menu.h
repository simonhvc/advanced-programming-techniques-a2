#include <string>
#include "Player.h"

class Menu { 
    
    public:
        Menu();

        void startMenu();

        void printMenu();
        
        int getSelection();

        void executeOption(int selection);
        
        void newGame();

        void loadGame();

        void showStudents();

        void quit();
        
        void promptUser();

    private:
        int selection = 0;
        Player* players[2];
        const std::string students[3][3] = {
            {"Kyle Condron", "s3717110", "s3717110@student.rmit.edu.au"},
            {"Simon Helsinki", "s3694451", "s3694451@student.rmit.edu.au"},
            {"Luke Shuster", "s3725150", "s3725150@student.rmit.edu.au"}
        };
};