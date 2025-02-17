#include <iostream>
#include <vector>

// Function prototypes
void printVector(const std::vector<int>& numbers);
void doubleVector(std::vector<int>& numbers);
int calculateSum(const std::vector<int>& numbers);
void printMultiples(const std::vector<int>& numbers, int value);

int main() {
    std::vector<int> numbers;
    int choice;

    do { //Display the Menu for the User
        std::cout << "\nVector Control Menu:\n"; 
        std::cout << "1. Add an item to the vector\n";
        std::cout << "2. Print the vector\n";
        std::cout << "3. Double the vector\n";
        std::cout << "4. Find the sum\n";
        std::cout << "5. Print multiples of a user-defined value\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                int num;
                std::cout << "Enter a number to add: ";
                std::cin >> num;
                numbers.push_back(num);
                break;
            }
            case 2:
                printVector(numbers);
                break;
            case 3:
                doubleVector(numbers);
                std::cout << "Vector doubled.\n";
                break;
            case 4:
                std::cout << "Sum of the vector: " << calculateSum(numbers) << "\n";
                break;
            case 5: {
                int value;
                std::cout << "Enter a number to find multiples of: ";
                std::cin >> value;
                printMultiples(numbers, value);
                break;
            }
            case 6:
                std::cout << "Exiting program.\n";
                break;
            default:
                std::cout << "Invalid choice, please try again.\n";
        }
    } while (choice != 6);
    
    return 0;
}

// Function to print the vector
void printVector(const std::vector<int>& numbers) {
    std::cout << "Vector elements: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << "\n";
}

// Function to double each element in the vector
void doubleVector(std::vector<int>& numbers) {
    for (int i = 0; i < numbers.size(); i++) {
        numbers.at(i) *= 2;
    }
}

// Function to calculate the sum of the vector elements
int calculateSum(const std::vector<int>& numbers) {
    int sum = 0;
    for (int num : numbers) {
        sum += num;
    }
    return sum;
}

// Function to print multiples of a given value
void printMultiples(const std::vector<int>& numbers, int value) {
    std::cout << "Multiples of " << value << ": ";
    for (int num : numbers) {
        if (num % value == 0) {
            std::cout << num << " ";
        }
    }
    std::cout << "\n";
}
