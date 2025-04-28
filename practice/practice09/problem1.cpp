#include <iostream>
#include <string>

int main() {
    float redPotion{0.0f};    // Amount of red potion in mL
    float bluePotion{0.0f};   // Amount of blue potion in mL
    float* flask{nullptr};    // Pointer to the selected potion

    std::string choice;
    
    while (true) {
        std::cout << "\nWhich potion would you like to add to? Type in 'Red' or 'Blue' or type 'Done' to finish: ";
        std::getline(std::cin, choice);

        // Convert input to lowercase for easier matching if needed
        if (choice == "Done" || choice == "done") {
            break;
        } else if (choice == "Red" || choice == "red") {
            flask = &redPotion;
        } else if (choice == "Blue" || choice == "blue") {
            flask = &bluePotion;
        } else {
            std::cout << "Invalid choice. Please enter Red, Blue, or Done." << std::endl;
            continue;
        }

        float amount{0.0f};
        std::cout << "How many milliliters would you like to add to this potion? ";
        std::cin >> amount;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer

        if (amount < 0) {
            std::cout << "Sorry! I cannot add a negative amount. Please try again." << std::endl;
            continue;
        }

        *flask += amount;

        // Display potion levels
        std::cout << "Current potion levels:" << std::endl;
        std::cout << "Red Potion: " << redPotion << " mL" << std::endl;
        std::cout << "Blue Potion: " << bluePotion << " mL" << std::endl;
    }

    std::cout << "\nPotion brewing session ended!" << std::endl;
    return 0;
}
