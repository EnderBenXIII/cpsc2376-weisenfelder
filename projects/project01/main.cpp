//Connect 4 Code!
#include <iostream>
#include <vector>

// enum classes
enum class Cell { EMPTY, PLAYER_1, PLAYER_2 };
enum class GameState { ONGOING, PLAYER_1_WINS, PLAYER_2_WINS, DRAW };

const int ROWS = 6;
const int COLS = 7;

void makeBoard(std::vector<std::vector<Cell>> &board) { //make board function
    board.assign(ROWS, std::vector<Cell>(COLS, Cell::EMPTY));
}

void printBoard(const std::vector<std::vector<Cell>> &board) { // prints the board for users to see
    std::cout << " 1 2 3 4 5 6 7\n";
    for (const auto &row : board) {
        for (const auto &cell : row) {
            if (cell == Cell::EMPTY) std::cout << " .";
            else if (cell == Cell::PLAYER_1) std::cout << " X";
            else std::cout << " O";
        }
        std::cout << '\n';
    }
    std::cout << "---------------\n";
}

bool isValidMove(const std::vector<std::vector<Cell>> &board, int column) { //test for move validity
    return column >= 0 && column < COLS && board[0][column] == Cell::EMPTY;
}

void dropDisc(std::vector<std::vector<Cell>> &board, int column, Cell player) { //goes through empty spaces
    for (int row = ROWS - 1; row >= 0; --row) {
        if (board[row][column] == Cell::EMPTY) {
            board[row][column] = player;
            break;
        }
    }
}

bool checkWinDirection(const std::vector<std::vector<Cell>> &board, int row, int col, int dRow, int dCol, Cell player) { //checks for row win, column win, or diagonal!
    for (int i = 0; i < 4; ++i) {
        int r = row + i * dRow, c = col + i * dCol;
        if (r < 0 || r >= ROWS || c < 0 || c >= COLS || board[r][c] != player) return false;
    }
    return true;
}

bool checkWin(const std::vector<std::vector<Cell>> &board, Cell player) { 
    for (int row = 0; row < ROWS; ++row) {
        for (int col = 0; col < COLS; ++col) {
            if (checkWinDirection(board, row, col, 0, 1, player) || 
                checkWinDirection(board, row, col, 1, 0, player) || 
                checkWinDirection(board, row, col, 1, 1, player) || 
                checkWinDirection(board, row, col, 1, -1, player))  
            {
                return true;
            }
        }
    }
    return false;
}

GameState gameStatus(const std::vector<std::vector<Cell>> &board) {
    if (checkWin(board, Cell::PLAYER_1)) return GameState::PLAYER_1_WINS;
    if (checkWin(board, Cell::PLAYER_2)) return GameState::PLAYER_2_WINS;

    for (const auto &row : board) {
        for (Cell cell : row) {
            if (cell == Cell::EMPTY) return GameState::ONGOING;
        }
    }
    return GameState::DRAW;
}

void play() {
    std::vector<std::vector<Cell>> board;
    makeBoard(board);

    Cell currentPlayer = Cell::PLAYER_1;
    GameState state = GameState::ONGOING;

    while (state == GameState::ONGOING) { //user input for gameplay
        printBoard(board);
        std::cout << "Player " << (currentPlayer == Cell::PLAYER_1 ? "1 (X)" : "2 (O)") << ", please choose a column (1-7): ";

        int column;
        while (true) {
            std::cin >> column;
            if (std::cin.fail() || !isValidMove(board, column - 1)) {
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                std::cout << "That move doesn't work, please try again: ";
            } else break;
        }

        dropDisc(board, column - 1, currentPlayer);
        state = gameStatus(board);

        if (state == GameState::ONGOING) {
            currentPlayer = (currentPlayer == Cell::PLAYER_1) ? Cell::PLAYER_2 : Cell::PLAYER_1;
        }
    }

    printBoard(board); //prints the board after victory
    if (state == GameState::PLAYER_1_WINS) std::cout << "Player 1 (X) is the winner!\n";
    else if (state == GameState::PLAYER_2_WINS) std::cout << "Player 2 (O) is the winner!\n";
    else std::cout << "Looks like it's a draw.\n";
}

int main() { //simple main that calls the play function
    std::cout << "Time to play to Connect 4!\n";
    while (true) {
        play();
        std::cout << "Would yo like to play again? (y/n): ";
        char choice;
        std::cin >> choice;
        if (choice != 'y' && choice != 'Y') break;
    }
    std::cout << "Thank you so much for playing my game!\n";
    return 0;
}
