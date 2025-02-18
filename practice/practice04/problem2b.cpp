#include <iostream>
#include <string>

template <typename T> //one function, finds max value for both ints and strings
T findMax(T a, T b, T c) {
    if (a > b) {
        if (a > c) {
            return a;
        } else {
            return c;
        }
    } else {
        if (b > c) {
            return b;
        } else {
            return c;
        }
    }
}

int main() {
    int choice;
    
    std::cout << "Would you like to compare (1) Numbers or (2) Strings? "; //menu display
    std::cin >> choice; //user input

    if (choice == 1) { //int user input + function calling
        int num1, num2, num3;
        std::cout << "Enter first value: ";
        std::cin >> num1;
        std::cout << "Enter second value: ";
        std::cin >> num2;
        std::cout << "Enter third value: ";
        std::cin >> num3;

        int maxValue = findMax(num1, num2, num3); //string user input + function calling
        std::cout << "Max value: " << maxValue << std::endl;
    } else if (choice == 2) {
        // Compare strings
        std::string str1, str2, str3;
        std::cout << "Enter first value: ";
        std::cin >> str1;
        std::cout << "Enter second value: ";
        std::cin >> str2;
        std::cout << "Enter third value: ";
        std::cin >> str3;

        std::string maxValue = findMax(str1, str2, str3);
        std::cout << "Max value: " << maxValue << std::endl;
    } else {
        std::cerr << "Sorry! You must select 1 or 2." << std::endl; //error message
    }

    return 0;
}
