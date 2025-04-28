#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

class Employee {
protected:
    std::string name;
    int id;
public:
    Employee(const std::string& name, int id) : name(name), id(id) {}
    virtual ~Employee() {}

    virtual double calculateSalary() const = 0;

    virtual void displayInfo() const {
        std::cout << "ID: " << id << ", Name: " << name;
    }
};

class SalariedEmployee : public Employee {
private:
    double monthlySalary;
public:
    SalariedEmployee(const std::string& name, int id, double monthlySalary)
        : Employee(name, id), monthlySalary(monthlySalary) {}

    double calculateSalary() const override {
        return monthlySalary;
    }

    void displayInfo() const override {
        Employee::displayInfo();
        std::cout << ", Type: Salaried, Monthly Salary: $" 
                  << std::fixed << std::setprecision(2) 
                  << monthlySalary << std::endl;
    }
};

class HourlyEmployee : public Employee {
private:
    double hourlyRate;
    int hoursWorked;
public:
    HourlyEmployee(const std::string& name, int id, double hourlyRate, int hoursWorked)
        : Employee(name, id), hourlyRate(hourlyRate), hoursWorked(hoursWorked) {}

    double calculateSalary() const override {
        return hourlyRate * hoursWorked;
    }

    void displayInfo() const override {
        Employee::displayInfo();
        std::cout << ", Type: Hourly, Hours Worked: " << hoursWorked
                  << ", Hourly Rate: $" << std::fixed << std::setprecision(2) 
                  << hourlyRate << ", Salary: $" << calculateSalary() << std::endl;
    }
};

class CommissionEmployee : public Employee {
private:
    double baseSalary;
    double salesAmount;
    double commissionRate;
public:
    CommissionEmployee(const std::string& name, int id, double baseSalary, double salesAmount, double commissionRate)
        : Employee(name, id), baseSalary(baseSalary), salesAmount(salesAmount), commissionRate(commissionRate) {}

    double calculateSalary() const override {
        return baseSalary + (salesAmount * commissionRate);
    }

    void displayInfo() const override {
        Employee::displayInfo();
        std::cout << ", Type: Commission, Base Salary: $" << std::fixed << std::setprecision(2) 
                  << baseSalary << ", Sales: $" << salesAmount 
                  << ", Commission Rate: " << (commissionRate * 100) << "%"
                  << ", Salary: $" << calculateSalary() << std::endl;
    }
};

int main() {
    std::ifstream inputFile("employees.txt");
    if (!inputFile) {
        std::cerr << "Sorry! Could not open file employees.txt" << std::endl;
        return 1;
    }

    std::vector<Employee*> employees;
    std::string type;
    int id;
    std::string name;

    while (inputFile >> type >> id >> name) {
        if (type == "Salaried") {
            double monthlySalary;
            if (inputFile >> monthlySalary) {
                employees.push_back(new SalariedEmployee(name, id, monthlySalary));
            } else {
                std::cerr << "Sorry! Invalid data for SalariedEmployee.\n";
                break;
            }
        } else if (type == "Hourly") {
            double hourlyRate;
            int hoursWorked;
            if (inputFile >> hourlyRate >> hoursWorked) {
                employees.push_back(new HourlyEmployee(name, id, hourlyRate, hoursWorked));
            } else {
                std::cerr << "Sorry! Invalid data for HourlyEmployee.\n";
                break;
            }
        } else if (type == "Commission") {
            double baseSalary, salesAmount, commissionRate;
            if (inputFile >> baseSalary >> salesAmount >> commissionRate) {
                employees.push_back(new CommissionEmployee(name, id, baseSalary, salesAmount, commissionRate));
            } else {
                std::cerr << "Sorry! Invalid data for CommissionEmployee.\n";
                break;
            }
        } else {
            std::cerr << "Sorry! Unknown employee type \"" << type << "\".\n";
            break;
        }
    }

    inputFile.close();

    std::cout << std::fixed << std::setprecision(2);
    for (const auto& emp : employees) {
        emp->displayInfo();
    }

    for (auto& emp : employees) {
        delete emp;
    }
    employees.clear();

    return 0;
}
