#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool completed;

    Task(const string& desc) : description(desc), completed(false) {}
};

class TodoList {
private:
    vector<Task> tasks;

public:
    void addTask(const string& description) {
        tasks.push_back(Task(description));
        cout << "Task added: " << description << endl;
    }

    void markCompleted(int index) {
        if (index >= 0 && index < tasks.size()) {
            tasks[index].completed = true;
            cout << "Task marked as completed: " << tasks[index].description << endl;
        } else {
            cout << "Invalid task index!" << endl;
        }
    }

    void printTasks() {
        cout << "Tasks:" << endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << "[" << i << "] ";
            if (tasks[i].completed) {
                cout << "[X] ";
            } else {
                cout << "[ ] ";
            }
            cout << tasks[i].description << endl;
        }
    }

    void clearTasks() {
        tasks.clear();
        cout << "All tasks cleared." << endl;
    }

    size_t getTaskCount() const {
        return tasks.size();
    }
};

int main() {
    TodoList todo;
    int choice;

    cout << "===== To-Do List =====" << endl;
    do {
        cout << "\n1. Add Task\n2. Mark Task as Completed\n3. Display Tasks\n4. Clear All Tasks\n5. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string taskDescription;
                cout << "Enter task description: ";
                cin.ignore(); // Ignore newline character left in stream
                getline(cin, taskDescription);
                todo.addTask(taskDescription);
                break;
            }
            case 2: {
                if (todo.getTaskCount() == 0) {
                    cout << "No tasks to mark as completed." << endl;
                } else {
                    int index;
                    cout << "Enter task index to mark as completed: ";
                    cin >> index;
                    todo.markCompleted(index);
                }
                break;
            }
            case 3:
                if (todo.getTaskCount() == 0) {
                    cout << "No tasks added yet." << endl;
                } else {
                    todo.printTasks();
                }
                break;
            case 4:
                if (todo.getTaskCount() == 0) {
                    cout << "No tasks to clear." << endl;
                } else {
                    todo.clearTasks();
                }
                break;
            case 5:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 5);

    return 0;
}
