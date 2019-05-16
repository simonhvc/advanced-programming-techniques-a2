class Menu { 
    
    public:
        Menu();

        void printMenu();
        
        int getSelection();

        void executeOption(int selection);
        
        void newGame();

        void loadGame();

        void showStudents();

        void quit();

    private:
        int selection = 0;
};