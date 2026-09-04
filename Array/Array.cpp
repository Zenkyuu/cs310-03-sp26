#include <iostream>
#include "Functions.h"
using namespace std;

int main(){
    TaskList tasks;

    int operation;
    int p;
    string task;
    
    while(operation != 6){
        cout << "Operation Menu" <<
        "\n 1. Add Task" <<
        "\n 2. Delete Task" <<
        "\n 3. Print Number of Tasks" <<
        "\n 4. Print Tasks in Order" <<
        "\n 5. Print Tasks in Reverse Order" <<
        "\n 6. Quit\n" << endl;

        cout << "Select an Operation: ";
        cin >> operation;

        if(operation == 1){
            cout << "Please enter a task name and position: ";
            cin >> task >> p;

            if(!tasks.isFull() && !tasks.posInvalid(p)){
            tasks.addTask(task, p);
            }

            if(!tasks.posInvalid(p)){
            cout << "Task \"" << task << "\"" << " added to position " << p << endl << endl;
            }
        }
        
        if(operation == 2){
            cout << "Please enter a task position to delete: ";
            cin >> p;

            string deletedTask = tasks.getTask(p);

            if(!tasks.isEmpty() && !tasks.posInvalid(p)){
            tasks.deleteTask(p);
            cout << "Task \"" << deletedTask << "\"" << " deleted from position " << p << endl << endl;
            }
            
            if(!tasks.isEmpty() && !tasks.posInvalid(p)){
            //cout << "Task \"" << deletedTask << "\"" << " deleted from position " << p << endl << endl;
            }
        }

        if(operation == 3){
            tasks.printNumTasks();
            cout << endl;
        }

        if(operation == 4){
            tasks.printInOrder();
            cout << endl;
        }

        if(operation == 5){
            tasks.printReverseOrder();
            cout << endl;
        }
    }
}