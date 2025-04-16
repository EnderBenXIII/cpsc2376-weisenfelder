#include <iostream>
#include <vector>
#include <algorithm>  

int main() {
    std::vector<int> numbers = {11, 25, 51, 52, 44};

    auto largest = std::max_element(numbers.begin(), numbers.end());

    auto smallest = std::min_element(numbers.begin(), numbers.end());

    std::cout << "The largest element is: " << *largest << std::endl;
    std::cout << "The smallest element is: " << *smallest << std::endl;

    return 0;
}
