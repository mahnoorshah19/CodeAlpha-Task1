#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool completed;

    Task(string desc) : description(desc), completed(false) {}
};

class ToDoList {
private:
    vector<Task> tasks;

public:
    void addTask(const string& task) {
        tasks.push_back(Task(task));
        cout << "Task added: " << task << endl;
    }

    void markTaskCompleted(int index) {
        if (index < 0 || index >= tasks.size()) {
            cout << "Invalid task number." << endl;
            return;
        }
        tasks[index].completed = true;
        cout << "Task marked as completed: " << tasks[index].description << endl;
    }

    void viewTasks() const {
        if (tasks.empty()) {
            cout << "No tasks available." << endl;
            return;
        }

        cout << "Current tasks:" << endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i].description
                << (tasks[i].completed ? " [Completed]" : "") << endl;
        }
    }
};

void displayMenu() {
    cout << "\nTo-Do List Application\n";
    cout << "1. Add Task\n";
    cout << "2. Mark Task as Completed\n";
    cout << "3. View Tasks\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    ToDoList todoList;
    int choice;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
        case 1: {
            cin.ignore(); // Ignore newline character left in buffer
            string task;
            cout << "Enter task description: ";
            getline(cin, task);
            todoList.addTask(task);
            break;
        }
        case 2: {
            int taskNumber;
            cout << "Enter task number to mark as completed: ";
            cin >> taskNumber;
            todoList.markTaskCompleted(taskNumber - 1);
            break;
        }
        case 3:
            todoList.viewTasks();
            break;
        case 4:
            cout << "Exiting the application." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
