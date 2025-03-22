#include "game.h"

Game::Game() : board(ROWS, std::vector<Cell>(COLS, EMPTY)), player1_turn(true), game_status(ONGOING) {}

bool Game::is_valid_move(int col) const {
    return col >= 0 && col < COLS && board[0][col] == EMPTY;
}

void Game::play(int col) {
    if (!is_valid_move(col) || game_status != ONGOING) return;
    
    for (int row = ROWS - 1; row >= 0; --row) {
        if (board[row][col] == EMPTY) {
            board[row][col] = player1_turn ? PLAYER_1 : PLAYER_2;
            break;
        }
    }
    
    check_winner();
    player1_turn = !player1_turn;
}

Status Game::status() const {
    return game_status;
}

void Game::check_winner() {
    for (int r = 0; r < ROWS; ++r) {
        for (int c = 0; c < COLS; ++c) {
            if (board[r][c] == EMPTY) continue;
            
            Cell player = board[r][c];
            if (c + 3 < COLS && board[r][c+1] == player && board[r][c+2] == player && board[r][c+3] == player)
                game_status = (player == PLAYER_1) ? PLAYER_1_WINS : PLAYER_2_WINS;
            if (r + 3 < ROWS && board[r+1][c] == player && board[r+2][c] == player && board[r+3][c] == player)
                game_status = (player == PLAYER_1) ? PLAYER_1_WINS : PLAYER_2_WINS;
            if (r + 3 < ROWS && c + 3 < COLS && board[r+1][c+1] == player && board[r+2][c+2] == player && board[r+3][c+3] == player)
                game_status = (player == PLAYER_1) ? PLAYER_1_WINS : PLAYER_2_WINS;
            if (r - 3 >= 0 && c + 3 < COLS && board[r-1][c+1] == player && board[r-2][c+2] == player && board[r-3][c+3] == player)
                game_status = (player == PLAYER_1) ? PLAYER_1_WINS : PLAYER_2_WINS;
        }
    }
    
    bool full = true;
    for (int c = 0; c < COLS; ++c) {
        if (board[0][c] == EMPTY) {
            full = false;
            break;
        }
    }
    if (full) game_status = DRAW;
}

std::ostream& operator<<(std::ostream& os, const Game& game) {
    for (const auto& row : game.board) {
        for (const auto& cell : row) {
            os << (cell == PLAYER_1 ? 'X' : cell == PLAYER_2 ? 'O' : '.') << ' ';
        }
        os << '\n';
    }
    return os;
}
