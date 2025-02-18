#include <iostream>
#include <list>
#include <string>

void showMenu() {
    std::cout << "\n1. Add Task\n";
    std::cout << "2. Remove Task\n";
    std::cout << "3. Show Tasks\n";
    std::cout << "4. Exit\n";
    std::cout << "Choice: ";
}

void addTask(std::list<std::string>& tasks) {
    std::string task;
    std::cout << "Enter task: ";
    std::cin.ignore(); // for leftover newline characters from input
    std::getline(std::cin, task); // gets the whole line
    tasks.push_back(task);
    std::cout << "Task added!" << std::endl;
}

void removeTask(std::list<std::string>& tasks) {
    int taskNumber;
    std::cout << "Enter task number to remove: ";
    std::cin >> taskNumber;

    if (taskNumber <= 0 || taskNumber > tasks.size()) {
        std::cout << "Invalid task number!" << std::endl;
        return;
    }

    auto it = tasks.begin(); //moves to the next task and erases the line
    std::advance(it, taskNumber - 1); 
    tasks.erase(it); 
    std::cout << "Task removed!" << std::endl;
}

void showTasks(const std::list<std::string>& tasks) {
    if (tasks.empty()) { //catch for no tasks
        std::cout << "You don't have any Tasks!" << std::endl;
    } else {
        std::cout << "Tasks:\n"; //otherwise display
        int taskNumber = 1;
        for (const auto& task : tasks) {
            std::cout << taskNumber++ << ". " << task << std::endl;
        }
    }
}

int main() {
    std::list<std::string> tasks;
    int choice;

    do {
        showMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                removeTask(tasks);
                break;
            case 3:
                showTasks(tasks);
                break;
            case 4:
                std::cout << "See ya!\n";
                break;
            default:
                std::cout << "Sorry, please make a valid selection.\n";
        }
    } while (choice != 4);

    return 0;
}
