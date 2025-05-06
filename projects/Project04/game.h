#ifndef GAME_H
#define GAME_H

#include <vector>
#include <iostream>
#include <SDL2/SDL.h>

const int ROWS = 6;
const int COLS = 7;
const int CELL_SIZE = 100;
const int SCREEN_WIDTH = COLS * CELL_SIZE;
const int SCREEN_HEIGHT = ROWS * CELL_SIZE;

enum Status { ONGOING, PLAYER_1_WINS, PLAYER_2_WINS, DRAW };
enum Cell { EMPTY, PLAYER_1, PLAYER_2 };

class Game {
private:
    std::vector<std::vector<Cell>> board;
    bool player1_turn;
    Status game_status;

    bool is_valid_move(int col) const;
    void check_winner();

public:
    Game();
    void play(int col);
    Status status() const;
    void draw(SDL_Renderer* renderer) const;
    friend std::ostream& operator<<(std::ostream& os, const Game& game);
};

#endif
