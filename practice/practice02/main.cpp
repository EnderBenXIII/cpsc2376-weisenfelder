#include <iostream>
#include <fstream>
#include <iomanip>
#include <limits>

using namespace std;

double readBalanceFromFile(const string& filename) { //read balance
    ifstream inFile(filename);
    double balance = 100.00; //default balance as per assignment example run 

    if (inFile.is_open()) {
        inFile >> balance;
        inFile.close();
    } else {
        ofstream outFile(filename);
        outFile << fixed << setprecision(2) << balance;
        outFile.close();
    }

    return balance;
}

void writeBalanceToFile(const string& filename, double balance) { //write balance
    ofstream outFile(filename);
    if (outFile.is_open()) {
        outFile << fixed << setprecision(2) << balance;
        outFile.close();
    } else {
        cerr << "Couldn't open the file for writing." << endl;
    }
}

void checkBalance(double balance) { //balance check
    cout << "Your current balance is: $" << fixed << setprecision(2) << balance << endl;
}

void deposit(double& balance) { //deposit money
    double depositAmount;
    cout << "Enter deposit amount: $";
    cin >> depositAmount;

    if (depositAmount <= 0) {
        cout << "Deposit amount must be positive." << endl;
    } else {
        balance += depositAmount;
        cout << "Deposit complete. Your new balance is: $" << fixed << setprecision(2) << balance << endl;
    }
}

void withdraw(double& balance) { //withdraw money
    double withdrawAmount;
    cout << "Enter withdrawal amount: $";
    cin >> withdrawAmount;

    if (withdrawAmount <= 0) {
        cout << "Withdrawal amount must be positive." << endl;
    } else if (withdrawAmount > balance) {
        cout << "Insufficient funds. Your balance is $" << fixed << setprecision(2) << balance << endl;
    } else {
        balance -= withdrawAmount;
        cout << "Withdrawal complete. Your new balance is: $" << fixed << setprecision(2) << balance << endl;
    }
}

int main() {
    string filename = "account_balance.txt";
    double balance = readBalanceFromFile(filename);
    
    cout << "Welcome to Your (FAKE) Bank Account!" << endl;
    cout << "Your current balance is: $" << fixed << setprecision(2) << balance << endl;

    while (true) { //menu display
        cout << "\nMenu:\n";
        cout << "1. Check your balance\n";
        cout << "2. Deposit some money\n";
        cout << "3. Withdraw some money\n";
        cout << "4. End the Program\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                checkBalance(balance);
                break;
            case 2:
                deposit(balance);
                break;
            case 3:
                withdraw(balance);
                break;
            case 4:
                writeBalanceToFile(filename, balance);
                cout << "Exiting program..." << endl;
                return 0;
            default:
                cout << "Error: Invalid choice. Please select a valid option." << endl;
        }

        writeBalanceToFile(filename, balance); //save balance
    }

    return 0;
}
