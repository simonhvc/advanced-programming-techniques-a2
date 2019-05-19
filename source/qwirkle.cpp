#include "Menu.h"
#include <memory>

#define EXIT_SUCCESS    0

int main(void) {

   std::unique_ptr<Menu> menu = std::make_unique<Menu>(); // shared smart pointer
   menu->startMenu();
   return EXIT_SUCCESS;
}

