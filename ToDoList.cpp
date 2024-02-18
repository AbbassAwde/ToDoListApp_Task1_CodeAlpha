#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> tasks;

void displayMenu() {
 cout << "\nTo-Do List Menu:" << endl;
 cout << "1. Add task" << endl;
 cout << "2. View tasks" << endl;
 cout << "3. Mark task as complete" << endl;
 cout << "4. Remove task" << endl;
 cout << "5. Exit" << endl;
 cout << "Enter your choice: ";
}

int main() {
 int choice;
 displayMenu();
 do {

   cin >> choice;

   switch (choice) {
     case 1: {
       string task;
       cout << "Enter task: ";
       getline(cin >> ws, task); // Clear input buffer before getline
       tasks.push_back(task);
       cout << "Task added successfully!" << endl;
       break;
     }
     case 2: {
       if (tasks.empty()) {
         cout << "No tasks to display." << endl;
       } else {
         cout << "\nYour tasks:" << endl;
         for (int i = 0; i < tasks.size(); i++) {
           cout << i + 1 << ". " << tasks[i] << endl;
         }
       }
       break;
     }
     case 3: {
       int taskIndex;
       cout << "Enter task number to mark as complete: ";
       cin >> taskIndex;
       if (taskIndex > 0 && taskIndex <= tasks.size()) {
         tasks[taskIndex - 1] = "(Completed) " + tasks[taskIndex - 1];
         cout << "Task marked as complete!" << endl;
       } else {
         cout << "Invalid task number." << endl;
       }
       break;
     }
     case 4: {
       int taskIndex;
       cout << "Enter task number to remove: ";
       cin >> taskIndex;
       if (taskIndex > 0 && taskIndex <= tasks.size()) {
         tasks.erase(tasks.begin() + taskIndex - 1);
         cout << "Task removed successfully!" << endl;
       } else {
         cout << "Invalid task number." << endl;
       }
       break;
     }
     case 5:
       cout << "Exiting to-do list." << endl;
       break;
     default:
       cout << "Invalid choice." << endl;
   }
 } while (choice != 5);

 return 0;
}
