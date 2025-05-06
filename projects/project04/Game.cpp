#include "Game.h"
#include "Engine.h"
#include <algorithm>

Game::Game() : board(6, std::vector<char>(7, ' ')), status(ONGOING), currentPlayer(0), moves(0) {}

void Game::play(int row, int col)
{
    if (col < 0 || col >= 7 || row < 0 || row >= 6 || board[row][col] != ' ' || status != ONGOING)
        return;

    for (int r = 5; r >= 0; --r)
    {
        if (board[r][col] == ' ')
        {
            board[r][col] = currentPlayer == 0 ? 'X' : 'O';
            moves++;
            if (checkWin(r, col))
            {
                status = currentPlayer == 0 ? X_WON : O_WON;
            }
            else if (moves == 42)
            {
                status = DRAW;
            }
            else
            {
                switchPlayer();
            }
            break;
        }
    }
}

bool Game::checkWin(int row, int col)
{
    // Check all 4 directions (horizontal, vertical, diagonal)
    return checkDirection(row, col, 0, 1) ||  // Horizontal
           checkDirection(row, col, 1, 0) ||  // Vertical
           checkDirection(row, col, 1, 1) ||  // Diagonal \
           checkDirection(row, col, 1, -1);   // Diagonal /
}

bool Game::checkDirection(int row, int col, int dRow, int dCol)
{
    char currentPiece = board[row][col];
    int count = 1;

    for (int i = 1; i < 4; ++i)
    {
        int r = row + dRow * i;
        int c = col + dCol * i;
        if (r >= 0 && r < 6 && c >= 0 && c < 7 && board[r][c] == currentPiece)
        {
            count++;
        }
        else
        {
            break;
        }
    }

    for (int i = 1; i < 4; ++i)
    {
        int r = row - dRow * i;
        int c = col - dCol * i;
        if (r >= 0 && r < 6 && c >= 0 && c < 7 && board[r][c] == currentPiece)
        {
            count++;
        }
        else
        {
            break;
        }
    }

    return count >= 4;
}

void Game::switchPlayer()
{
    currentPlayer = 1 - currentPlayer;
}

void Game::draw(Engine* engine, int row, int col)
{
    for (int r = 0; r < 6; ++r)
    {
        for (int c = 0; c < 7; ++c)
        {
            SDL_Color color = {255, 255, 255, 255}; 
            if (board[r][c] == 'X')
                color = {255, 0, 0, 255}; // Red for X
            else if (board[r][c] == 'O')
                color = {0, 0, 255, 255}; // Blue for O

            engine->drawCircle(50 + c * 100, 50 + r * 100, 40, color); 
        }
    }
}

Game::GameStatus Game::getStatus() const
{
    return status;
}

int Game::moveCount() const
{
    return moves;
}
