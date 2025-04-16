#include <iostream>
#include <vector>
#include <algorithm>  
#include <limits>
#include <numeric>

int main() {
    std::vector<int> numbers;
    int n;

    std::cout << "Enter integers (type a non-integer and the press the 'Enter' key to stop):\n";

    while (std::cin >> n) {
        numbers.push_back(n);
    }

    // Clear the error
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Squared values:\n";
    std::for_each(numbers.begin(), numbers.end(), [](int num) {
        std::cout << num * num << " ";
    });
    std::cout << std::endl;

    int sum_of_squares = std::accumulate(numbers.begin(), numbers.end(), 0, [](int sum, int num) {
        return sum + num * num;
    });

    std::cout << "Sum of squared values: " << sum_of_squares << std::endl;

    return 0;
}
