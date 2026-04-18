#include <stdio.h>
#include <string.h>
#include "auth.h"

// REGISTER:
void registerUser() {
    FILE *fp;
    char username[50], password[50];
    char tempUser[50], tempPass[50];

    printf("\n===== REGISTER =====\n");
    printf("Enter username: ");
    scanf("%s", username);

    
    fp = fopen("users.txt", "r");
    if (fp != NULL) {
        while (fscanf(fp, "%s %s", tempUser, tempPass) == 2) {
            if (strcmp(username, tempUser) == 0) {
                printf("Username already taken! Try another.\n");
                fclose(fp);
                return;
            }
        }
        fclose(fp);
    }

    printf("Enter password: ");
    scanf("%s", password);

    
    fp = fopen("users.txt", "a");
    if (fp == NULL) {
        printf("Error: Could not open users file.\n");
        return;
    }
    fprintf(fp, "%s %s\n", username, password);
    fclose(fp);

    printf("Registration successful! You can now login.\n");
}

// LOGIN:
int loginUser(char currentUser[]) {
    FILE *fp;
    char username[50], password[50];
    char tempUser[50], tempPass[50];

    printf("\n===== LOGIN =====\n");
    printf("Enter username(without space): ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    fp = fopen("users.txt", "r");
    if (fp == NULL) {
        printf("No users registered yet!\n");
        return 0; 
    }


    while (fscanf(fp, "%s %s", tempUser, tempPass) == 2) {
        if (strcmp(username, tempUser) == 0 && strcmp(password, tempPass) == 0) {
            strcpy(currentUser, username);
            fclose(fp);
            return 1; 
        }
    }

    fclose(fp);
    return 0; 
}
