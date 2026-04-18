#include <stdio.h>
#include <string.h>
#include "tasks.h"

// ADD TASK:
void addTask(char currentUser[]) {
    FILE *fp;
    struct Task t;

    strcpy(t.username, currentUser);

    printf("\nAdd Task\n");
    printf("Enter Task ID: ");
    scanf("%d", &t.id);

    getchar(); 

    printf("Enter Task (use underscore instead of spaces): ");
    scanf("%s", t.title);

    strcpy(t.status, "Pending");

    fp = fopen("tasks.txt", "a");
    if (fp == NULL) {
        printf("Could not open file.\n");
        return;
    }

    fprintf(fp, "%s %d %s %s\n", t.username, t.id, t.title, t.status);
    fclose(fp);

    printf("Task added!\n");
}

// VIEW TASKS:
void viewTasks(char currentUser[]) {
    FILE *fp;
    struct Task t;
    int found = 0;

    fp = fopen("tasks.txt", "r");
    if (fp == NULL) {
        printf("Could not open file.\n");
        return;
    }

    printf("\n Your Tasks \n");

    while (fscanf(fp, "%s %d %s %s", t.username, &t.id, t.title, t.status) == 4) {
        if (strcmp(t.username, currentUser) == 0) {
            printf("ID: %d | Title: %s | Status: %s\n", t.id, t.title, t.status);
            found = 1;
        }
    }

    if (!found) {
        printf("You have no tasks yet!\n");
    }

    fclose(fp);
}

// DELETE TASK:
void deleteTask(char currentUser[]) {
    FILE *fp, *temp;
    struct Task t;
    int id, found = 0;

    fp = fopen("tasks.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        return;
    }

    temp = fopen("temp.txt", "w");
    if (temp == NULL) {
        printf("Could not create temp file.\n");
        fclose(fp);
        return;
    }

    printf("\n Delete Task \n");
    printf("Enter Task ID: ");
    scanf("%d", &id);

    while (fscanf(fp, "%s %d %s %s", t.username, &t.id, t.title, t.status) == 4) {
        if (strcmp(t.username, currentUser) == 0 && t.id == id) {
            found = 1;
        } else {
            fprintf(temp, "%s %d %s %s\n", t.username, t.id, t.title, t.status);
        }
    }

    fclose(fp);
    fclose(temp);

    remove("tasks.txt");
    rename("temp.txt", "tasks.txt");

    if (found)
        printf("Task removed.\n");
    else
        printf("Task ID not found!\n");
}

// MARK COMPLETED:
void markCompleted(char currentUser[]) {
    FILE *fp, *temp;
    struct Task t;
    int id, found = 0;

    fp = fopen("tasks.txt", "r");
    if (fp == NULL) {
        printf("Could not open file.\n");
        return;
    }

    temp = fopen("temp.txt", "w");
    if (temp == NULL) {
        printf("Could not create temp file.\n");
        fclose(fp);
        return;
    }

    printf("\n Mark Task as Completed \n");
    printf("Enter Task ID: ");
    scanf("%d", &id);

    while (fscanf(fp, "%s %d %s %s", t.username, &t.id, t.title, t.status) == 4) {
        if (strcmp(t.username, currentUser) == 0 && t.id == id) {
            strcpy(t.status, "Completed");
            found = 1;
        }

        fprintf(temp, "%s %d %s %s\n", t.username, t.id, t.title, t.status);
    }

    fclose(fp);
    fclose(temp);

    remove("tasks.txt");
    rename("temp.txt", "tasks.txt");

    if (found)
        printf("Task completed!\n");
    else
        printf("Task ID not found!\n");
}