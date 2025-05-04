# Board Game Café Lending System Design

## 1. Program Specification

This tool is a lightweight system designed to help manage board game lending in a local board game café. 
The program allows the café staff to keep track of their inventory of board games, including how many copies are available for lending. 
It also records customer checkouts, who has which game, and when the games are due back. 
When a customer returns a game, the system updates the inventory accordingly.

The main entities are **BoardGame**, **Customer**, and **LendingRecord**. 
The system supports listing all games with their availability, checking out games to customers, and returning them efficiently.

## 2. Nouns and Verbs

### Key Nouns (Potential Classes or Attributes)
- BoardGame
- Customer
- LendingRecord
- Game ID
- Customer Name
- Due Date
- Number of Copies

### Key Verbs (Potential Methods or Behaviors)
- Add a game to inventory
- List all games
- Check out a game
- Return a game
- View lending records

## 3. Class Declarations

### BoardGame
```cpp
class BoardGame {
public:
    BoardGame(std::string title, int totalCopies);

    std::string getTitle() const;
    int getAvailableCopies() const;
    void checkoutCopy();
    void returnCopy();

private:
    std::string title;
    int totalCopies;
    int copiesAvailable;
};
