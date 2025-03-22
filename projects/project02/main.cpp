#include "game.h"
#include <iostream>

int main() {
    Game game;
    int col;
    
    while (game.status() == ONGOING) {
        std::cout << game;
        std::cout << "Please enter the column you want to place your piece in (0-6): ";
        std::cin >> col;
        game.play(col);
    }
    
    std::cout << game;
    if (game.status() == PLAYER_1_WINS) std::cout << "Player 1 is the winner!\n";
    else if (game.status() == PLAYER_2_WINS) std::cout << "Player 2 is the winner!\n";
    else std::cout << "Wow, it's a draw!\n";
    
    return 0;
}
