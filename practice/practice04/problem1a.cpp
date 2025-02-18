#include <iostream>
#include <iomanip> 

// Function to convert temperature
double convertTemperature(double temp, char scale = 'F') { //One function for both conversions
    if (scale == 'F') { //Farenheit to Celsius
        return (temp * 9.0 / 5.0) + 32;
    } else { //Celsius to Farenheit
        return (temp - 32) * 5.0 / 9.0;
    } 
}

int main() { //Menu + setup of values
    int choice;
    double temp;
    char scale;

    std::cout << "Temperature Converter\n";
    std::cout << "1. Convert Celsius to Fahrenheit\n";
    std::cout << "2. Convert Fahrenheit to Celsius\n";
    std::cout << "Choose an option: ";
    std::cin >> choice;

    std::cout << "Enter temperature: "; //user input
    std::cin >> temp;

    if (choice == 1) {
        scale = 'F';
        double result = convertTemperature(temp, scale);
        std::cout << "Converted: " << std::fixed << std::setprecision(2) << result << "°F\n";
    } else if (choice == 2) {
        scale = 'C';
        double result = convertTemperature(temp, scale);
        std::cout << "Converted: " << std::fixed << std::setprecision(2) << result << "°C\n";
    } else {
        std::cerr << "Invalid choice! Please choose 1 or 2.\n";
    }

    return 0;
}
