#include <iostream>
#include <vector>
#include <string>

struct Task {
    std::string description;
    bool completed;

    Task(const std::string& desc) : description(desc), completed(false) {}
};

class TodoList {
private:
    std::vector<Task> tasks;

public:
    void addTask(const std::string& desc) {
        tasks.push_back(Task(desc));
        std::cout << "Task added: " << desc << std::endl;
    }

    void viewTasks() {
        std::cout << "Tasks:" << std::endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            std::cout << i + 1 << ". [" << (tasks[i].completed ? "X" : " ") << "] " << tasks[i].description << std::endl;
        }
    }

    void markTaskAsCompleted(size_t index) {
        if (index >= 1 && index <= tasks.size()) {
            tasks[index - 1].completed = true;
            std::cout << "Task marked as completed: " << tasks[index - 1].description << std::endl;
        } else {
            std::cout << "Invalid task index." << std::endl;
        }
    }

    void removeTask(size_t index) {
        if (index >= 1 && index <= tasks.size()) {
            std::cout << "Task removed: " << tasks[index - 1].description << std::endl;
            tasks.erase(tasks.begin() + index - 1);
        } else {
            std::cout << "Invalid task index." << std::endl;
        }
    }
};

int main() {
    TodoList todoList;

    while (true) {
        std::cout << "Options:\n1. Add Task\n2. View Tasks\n3. Mark Task as Completed\n4. Remove Task\n5. Exit\n";
        int choice;
        std::cin >> choice;

        if (choice == 1) {
            std::cout << "Enter task description: ";
            std::string desc;
            std::cin.ignore(); // Clear the newline character from the buffer
            std::getline(std::cin, desc);
            todoList.addTask(desc);
        } else if (choice == 2) {
            todoList.viewTasks();
        } else if (choice == 3) {
            std::cout << "Enter task number to mark as completed: ";
            size_t index;
            std::cin >> index;
            todoList.markTaskAsCompleted(index);
        } else if (choice == 4) {
            std::cout << "Enter task number to remove: ";
            size_t index;
            std::cin >> index;
            todoList.removeTask(index);
        } else if (choice == 5) {
            break;
        } else {
            std::cout << "Invalid choice. Please select a valid option." << std::endl;
        }
    }

    return 0;
}

