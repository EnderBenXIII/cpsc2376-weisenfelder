#include <iostream>
#include <memory>
#include <algorithm>
#include <cctype>
#include <string>
#include <vector>
#include <sstream>

class TextFilterStrategy {
public:
    virtual std::string apply(const std::string& text) const = 0;
    virtual ~TextFilterStrategy() = default;
};

class ReverseStrategy : public TextFilterStrategy {
public:
    std::string apply(const std::string& text) const override {
        std::string reversed = text;
        std::reverse(reversed.begin(), reversed.end());
        return reversed;
    }
};

class UppercaseStrategy : public TextFilterStrategy {
public:
    std::string apply(const std::string& text) const override {
        std::string upper = text;
        std::transform(upper.begin(), upper.end(), upper.begin(),
                       [](char c) { return std::toupper(static_cast<unsigned char>(c)); });
        return upper;
    }
};

class RemoveVowelsStrategy : public TextFilterStrategy {
public:
    std::string apply(const std::string& text) const override {
        std::string result;
        for (char c : text) {
            if (std::string("aeiouAEIOU").find(c) == std::string::npos) {
                result += c;
            }
        }
        return result;
    }
};

class CensorBadWordsStrategy : public TextFilterStrategy {
public:
    std::string apply(const std::string& text) const override {
        std::vector<std::string> badWords = {"bad", "ugly"};
        std::istringstream iss(text);
        std::ostringstream oss;
        std::string word;
        while (iss >> word) {
            std::string clean = word;
            std::string lowercaseWord = word;
            std::transform(lowercaseWord.begin(), lowercaseWord.end(), lowercaseWord.begin(),
                           [](char c) { return std::tolower(static_cast<unsigned char>(c)); });

            bool isBad = false;
            for (const auto& bad : badWords) {
                if (lowercaseWord.find(bad) != std::string::npos) {
                    isBad = true;
                    break;
                }
            }

            if (isBad) {
                clean = std::string(word.size(), '*');
            }

            oss << clean << ' ';
        }
        return oss.str();
    }
};

class TextProcessor {
    std::unique_ptr<TextFilterStrategy> strategy;
public:
    void setStrategy(std::unique_ptr<TextFilterStrategy> s) {
        strategy = std::move(s);
    }

    std::string process(const std::string& text) const {
        if (strategy) {
            return strategy->apply(text);
        }
        return text;
    }
};

void showMenu() {
    std::cout << "\nChoose a text filter strategy:\n";
    std::cout << "1. Reverse text\n";
    std::cout << "2. Uppercase text\n";
    std::cout << "3. Remove vowels\n";
    std::cout << "4. Censor bad words\n";
    std::cout << "5. Exit\n";
    std::cout << "Enter choice: ";
}

int main() {
    std::string input;
    std::cout << "Enter a sentence: ";
    std::getline(std::cin, input);

    TextProcessor processor;
    int choice = 0;

    do {
        showMenu();
        std::cin >> choice;
        std::cin.ignore(); 

        switch (choice) {
            case 1:
                processor.setStrategy(std::make_unique<ReverseStrategy>());
                break;
            case 2:
                processor.setStrategy(std::make_unique<UppercaseStrategy>());
                break;
            case 3:
                processor.setStrategy(std::make_unique<RemoveVowelsStrategy>());
                break;
            case 4:
                processor.setStrategy(std::make_unique<CensorBadWordsStrategy>());
                break;
            case 5:
                std::cout << "Goodbye!\n";
                return 0;
            default:
                std::cout << "Invalid option.\n";
                continue;
        }

        std::string result = processor.process(input);
        std::cout << "\nFiltered result: " << result << "\n";

    } while (choice != 5);

    return 0;
}
