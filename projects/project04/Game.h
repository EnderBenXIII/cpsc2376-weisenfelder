#pragma once
#include <iostream>
#include <vector>

class Game
{
public:
    enum GameStatus { ONGOING, X_WON, O_WON, DRAW };
    Game();

    void play(int row, int col);
    void draw(Engine* engine, int row, int col);
    GameStatus getStatus() const;
    int moveCount() const;

private:
    std::vector<std::vector<char>> board;
    GameStatus status;
    int currentPlayer;
    int moves;

    bool checkWin(int row, int col);
    bool checkDirection(int row, int col, int dRow, int dCol);
    void switchPlayer();
};
