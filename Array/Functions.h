#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <string>
using namespace std;

class TaskList {
    private:
        static const int SIZE = 7;

        string taskList[SIZE];
        int numTasks;

    public:
    // Constructor
    TaskList(){
        numTasks = 0;
    }

        /*1. Add task X to the list at a particular position p*/
        void addTask(string task, int p){
            // Full List Case
            if(numTasks >= SIZE){
                cout << "Task list is full." << endl;
                return;
            }

            // Case of placing in an index outside the array index positions
            if(p < 1 || p > numTasks + 1){
                cout << "Invalid position" << endl;
                return;
            }

            // Shift elements to the right in the case that there is an item 
            for(int i = numTasks; i >= p - 1; i--){
                taskList[i] = taskList[i - 1];
            }

            // Adding Task
            taskList[p - 1] = task;            
            numTasks++;
        }

        /*2. Delete task X from the task list at position q*/
        void deleteTask(int q){
            // Empty List Case
            if(numTasks == 0){
                cout << "Task list is empty." << endl;
                return;
            }

            // Case of placing an index outside the array index positions
            if(q < 1 || q > numTasks + 1){
                cout << "Invalid Position" << endl;
                return;
            }

            // Shift elements to the left to replace the deleted element
            for(int i = q - 1; i < numTasks - 1; i++){
                taskList[i] = taskList[i + 1];
            }

            // Deleting Task
            numTasks--;
        }

        /*3. Print the number of tasks in the task list*/
        void printNumTasks(){
            cout  << "Number of Tasks: " << numTasks << endl;
        }

        /*4. Print all the tasks in the task list in the order of the position*/
        void printInOrder(){
            // Empty List Case
            if(numTasks == 0){
                cout << "Task list is empty." << endl;
                return;
            }

            // Loop through to print list in order
            for(int i = 0; i < numTasks; i++){
                cout << i + 1 << ":" << taskList[i] << " ";
            }
            cout << endl;
        }

        /*5. Print all the tasks in the task list in reverse order of position*/
        void printReverseOrder(){
            // Empty List Case
            if(numTasks == 0){
                cout << "Task list is empty." << endl;
                return;
            }

            // Loop through to print list in order
            for(int i = numTasks - 1; i >= 0; i--){
                cout << i + 1 << ":" << taskList[i] << " ";
            }
            cout << endl;
        }

        // Getter for list
        string getTask(int p){ return taskList[p - 1];}

        //Checks position validity
        bool posInvalid(int p){
            if(p < 1 || p > numTasks + 1){
                return true;
            } else {
                return false;
            }
        }

        // Check if list is empty
        bool isEmpty(){
            if(numTasks == 0){
                return true;
            } else {
                return false;
            }
        }

        bool isFull(){
            if(numTasks > SIZE){
                return true;
            } else {
                return false;
            }
        }

};

#endif