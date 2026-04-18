#ifndef TASKS_H
#define TASKS_H

struct Task {
    char username[50]; 
    int  id;           
    char title[100];   
    char status[20];   
};

void addTask(char currentUser[]);
void viewTasks(char currentUser[]);
void deleteTask(char currentUser[]);
void markCompleted(char currentUser[]);

#endif
