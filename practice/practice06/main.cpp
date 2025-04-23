#include <iostream>
#include "Fraction.h"
#include "MixedFraction.h"

void showMenu() {
    std::cout << "\nOptions:\n";
    std::cout << "1. Enter a fraction manually\n";
    std::cout << "2. Add a fraction\n";
    std::cout << "3. Subtract a fraction\n";
    std::cout << "4. Multiply by a fraction\n";
    std::cout << "5. Divide by a fraction\n";
    std::cout << "6. Display as Mixed Fraction\n";
    std::cout << "7. Clear Fraction\n";
    std::cout << "8. Exit\n";
}

Fraction inputFraction() {
    int n, d;
    std::cout << "Enter numerator: ";
    std::cin >> n;
    std::cout << "Enter denominator: ";
    std::cin >> d;
    return Fraction(n, d);
}

int main() {
    Fraction current;

    bool running = true;
    while (running) {
        std::cout << "\nCurrent Fraction: " << current << "\n";
        showMenu();
        int choice;
        std::cout << "Enter choice: ";
        std::cin >> choice;

        try {
            switch (choice) {
                case 1:
                    current = inputFraction();
                    break;
                case 2:
                    current = current + inputFraction();
                    break;
                case 3:
                    current = current - inputFraction();
                    break;
                case 4:
                    current = current * inputFraction();
                    break;
                case 5:
                    current = current / inputFraction();
                    break;
                case 6: {
                    MixedFraction mixed(current);
                    std::cout << "Mixed Fraction: " << mixed << "\n";
                    break;
                }
                case 7:
                    current = Fraction();
                    break;
                case 8:
                    running = false;
                    break;
                default:
                    std::cout << "Invalid option. Try again.\n";
            }
        } catch (std::exception& e) {
            std::cout << "Error: " << e.what() << "\n";
        }
    }

    std::cout << "Goodbye!\n";
    return 0;
}
