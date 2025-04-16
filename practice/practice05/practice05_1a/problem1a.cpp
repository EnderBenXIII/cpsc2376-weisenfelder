#include <iostream>
#include <vector>
#include <iterator>
#include <limits>  

int main() {
    std::vector<int> numbers;
    int n;

    std::cout << "Enter some integers. (type any non-integer and then press the 'Enter' key to stop):\n";

    while (true) {
        std::cout << "Enter a number: ";
        if (std::cin >> n) {
            numbers.push_back(n);
        } else {
            //break out of the loop
            break;
        }
    }

    // clear the error 
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
