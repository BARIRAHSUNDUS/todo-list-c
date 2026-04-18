#include <stdio.h>
#include <stdlib.h>
#include "auth.h"
#include "tasks.h"

int main() {
    int choice;
    char currentUser[50];

    while (1) {
        printf("\n===== TO-DO LIST SYSTEM =====\n");
        printf("1. Register\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerUser();
                break;

            case 2:
                if (loginUser(currentUser)) {
                    printf("\nWelcome, %s!\n", currentUser);

                    int taskChoice;
                    while (1) {
                        printf("\n--- TASK MENU ---\n");
                        printf("1. Add Task\n");
                        printf("2. View Tasks\n");
                        printf("3. Mark Completed\n");
                        printf("4. Delete Task\n");
                        printf("5. Logout\n");
                        printf("Enter choice: ");
                        scanf("%d", &taskChoice);

                        switch (taskChoice) {
                            case 1:
                                addTask(currentUser);
                                break;
                            case 2:
                                viewTasks(currentUser);
                                break;
                            case 3:
                                markCompleted(currentUser);
                                break;
                            case 4:
                                deleteTask(currentUser);
                                break;
                            case 5:
                                printf("Logged out!\n");
                                break;
                            default:
                                printf("Invalid choice!\n");
                        }

                        if (taskChoice == 5)
                            break;
                    }
                } else {
                    printf("Login failed!\n");
                }
                break;

            case 3:
                printf("Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}