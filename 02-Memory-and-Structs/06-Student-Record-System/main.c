/*
 * Project: Student Record System
 * Author: Shahad K
 * 20 Dec 2025
 */
#include <stdio.h>
#include "student.h"

int main()
{
    StudentDB db;
    db.studentCount = 0; // Initialize count
    
    // Load data immediately into the struct
    db.studentCount = loadFile(&db);

    char *mainMenu[] = {"1. Add Student", "2. View Students", "3. Save & Exit"};
    printf("---> Welcome to Student Manager <---\n");
    
    int choice;
    do
    {
        printf("\n------------------\n");
        printf("----> Main Menu <----\n");
        for(int i = 0; i < 3; i++) { printf("%s\n", mainMenu[i]); }
        
        printf("Choice: ");
        if(scanf("%d", &choice) != 1) {
            // Flush input buffer if user types text instead of number
            while(getchar() != '\n'); 
            printf("Please Enter a Number.\n");   
            continue;
        }

        switch(choice)
        {
            // Pass the address of the database (&db)
            case 1: addStudent(&db); break;
            case 2: viewStudents(&db); break;
            case 3: saveFile(&db); break;
            default: printf("Invalid Choice!\n");
        }

    } while (choice != 3);

    return 0;
}
