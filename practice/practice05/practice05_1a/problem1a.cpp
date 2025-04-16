#include <iostream>
#include <vector>
#include <iterator>
#include <limits>  // For std::numeric_limits

int main() {
    std::vector<int> numbers;
    int n;

    std::cout << "Enter integers (type 'q' or any non-integer to stop):\n";

    while (true) {
        std::cout << "Enter a number: ";
        if (std::cin >> n) {
            numbers.push_back(n);
        } else {
            // Invalid input: break out of the loop
            break;
        }
    }

    // Clear the error state and flush the bad input
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "\nYou entered: ";
    for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) {
        std::cout << *it << " ";
    }

    int evenSum = 0;
    for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) {
        if (*it % 2 == 0) {
            evenSum += *it;
        }
    }

    std::cout << "\nSum of even numbers: " << evenSum << std::endl;

    return 0;
}
