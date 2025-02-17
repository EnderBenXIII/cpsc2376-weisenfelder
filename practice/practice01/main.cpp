#include <iostream>
#include <vector>

void printVector(const std::vector<int>& numbers);
void doubleVector(std::vector<int>& numbers);
int calculateSum(const std::vector<int>& numbers);
void printMultiples(const std::vector<int>& numbers, int value);

int main() {
    std::vector<int> numbers;
    int choice;

    do { //menu display
        std::cout << "\nVector Control Menu:\n"; 
        std::cout << "1. Add an item to the vector\n";
        std::cout << "2. Print the vector\n";
        std::cout << "3. Double the vector\n";
        std::cout << "4. Find the sum\n";
        std::cout << "5. Print multiples of a value\n";
        std::cout << "6. End the Program\n";
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
                std::cout << "Sorry, I didn't get that, please try again.\n";
        }
    } while (choice != 6);
    
    return 0;
}

void printVector(const std::vector<int>& numbers) { //print vector
    std::cout << "Vector elements: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << "\n";
}

void doubleVector(std::vector<int>& numbers) { //double sum
    for (int i = 0; i < numbers.size(); i++) {
        numbers.at(i) *= 2;
    }
}

int calculateSum(const std::vector<int>& numbers) { //calculate sum
    int sum = 0;
    for (int num : numbers) {
        sum += num;
    }
    return sum;
}

void printMultiples(const std::vector<int>& numbers, int value) { //print multiples
    std::cout << "Multiples of " << value << ": ";
    for (int num : numbers) {
        if (num % value == 0) {
            std::cout << num << " ";
        }
    }
    std::cout << "\n";
}
