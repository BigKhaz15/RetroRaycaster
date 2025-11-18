#include <iostream>
#include "Game.h"

int main() {
    Game game;

    if (!game.init()) {
        std::cerr << "Failed to initialize game.\n";
        return 1;
    }

    game.run();

    std::cout << "Game exited cleanly.\n";
    return 0;
}
