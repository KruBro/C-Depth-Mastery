#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h> // For usleep
#include "student.h"

// --- Helper Functions ---

int uniqueID(StudentDB *db, const char *id)
{
    for(int i = 0; i < db->studentCount; i++)
    {
        if(strcmp(db->students[i].id, id) == 0)
        {
            printf("❌ ID Already Exists!\n");
            return 1;
        }
    }
    return 0;
}

int validateName(const char *name)
{
    if (name[0] == '\0') return 1;
    for (int i = 0; name[i]; i++)
    {
        if (!isalpha(name[i]) && name[i] != ' ' && name[i] != '_')
        {
            printf("❌ Invalid name! Use letters, spaces, or underscores.\n");
            return 1;
        }
    }
    return 0;
}

int validateId(const char *id)
{
    // Simple numeric check
    for(int i = 0; id[i] != '\0'; i++) {
        if(!isdigit(id[i])) {
            printf("❌ ID must be numeric.\n");
            return 1;
        }
    }
    return 0;
}

int validateGPA(const char *gpa)
{
    char *end;
    float val = strtof(gpa, &end);
    if(val < 0.0 || val > 4.0) // Changed to standard 4.0 scale (or keep 5.0)
    {
        printf("❌ GPA must be between 0.0 and 4.0\n");
        return 1;
    }
    return 0;
}

// --- Main Functions ---

void addStudent(StudentDB *db)
{
    if(db->studentCount >= 100) {
        printf("Database is Full!\n");
        return;
    }

    Student newStudent;
    char temp[50];

    // ID Input
    do {
        printf("Enter ID: ");
        scanf("%s", newStudent.id);
    } while (validateId(newStudent.id) | uniqueID(db, newStudent.id));

    // Name Input
    do {
        printf("Enter Name (Use_Underscores): ");
        scanf(" %[^\n]", temp); // Simplified for CSV safety (no internal spaces)
    } while (validateName(temp));
    strcpy(newStudent.name, temp);

    // GPA Input
    do {
        printf("Enter GPA: ");
        scanf("%s", newStudent.gpa);
    } while (validateGPA(newStudent.gpa));
    
    // Save to DB
    db->students[db->studentCount] = newStudent;
    db->studentCount++;
    printf("✅ Student Added\n");
}

void viewStudents(StudentDB *db)
{
    if (db->studentCount == 0) {
        printf("No records found.\n");
        return;
    }

    int choice;
    printf("\n1. By ID | 2. By Name | 3. By GPA\nSort Choice: ");
    scanf("%d", &choice);

    // Bubble Sort Logic
    for(int i = 0; i < db->studentCount - 1; i++)
    {
        for(int j = 0; j < db->studentCount - i - 1; j++)
        {
            int swap = 0;
            // Determine swap condition based on choice
            if (choice == 1 && strcmp(db->students[j].id, db->students[j+1].id) > 0) swap = 1;
            else if (choice == 2 && strcmp(db->students[j].name, db->students[j+1].name) > 0) swap = 1;
            else if (choice == 3 && strcmp(db->students[j].gpa, db->students[j+1].gpa) > 0) swap = 1;

            if(swap) {
                Student temp = db->students[j];
                db->students[j] = db->students[j+1];
                db->students[j+1] = temp;
            }
        }
    }

    printf("\n%-5s %-10s %-20s %-5s\n", "#", "ID", "NAME", "GPA");
    printf("----------------------------------------\n");
    for(int i = 0; i < db->studentCount; i++)
    {
        printf("%-5d %-10s %-20s %-5s\n", i+1, 
            db->students[i].id,
            db->students[i].name, 
            db->students[i].gpa);
    }
}

int loadFile(StudentDB *db)
{
    FILE *fp = fopen("students.csv", "r");
    if(!fp) return 0; // File doesn't exist yet, return 0 count

    char buffer[200];
    // Skip Header line
    fgets(buffer, 200, fp);

    int count = 0;
    while(fscanf(fp, "%[^,],%[^,],%s\n", 
          db->students[count].id, 
          db->students[count].name, 
          db->students[count].gpa) == 3)
    {
        count++;
        if(count >= 100) break;
    }
    
    fclose(fp);
    printf("📂 Database Loaded (%d records)\n", count);
    return count;
}

void saveFile(StudentDB *db)
{
    FILE *fp = fopen("students.csv", "w");
    if(!fp) {
        printf("Error saving file!\n");
        return;
    }

    // CSV Header
    fprintf(fp, "ID,NAME,GPA\n");

    for(int i = 0; i < db->studentCount; i++)
    {
        fprintf(fp, "%s,%s,%s\n", 
            db->students[i].id, 
            db->students[i].name, 
            db->students[i].gpa);
    }

    fclose(fp);
    
    printf("Saving");
    for(int i = 0; i < 5; i++) {
        printf(".");
        fflush(stdout); // Force print without newline
        usleep(100000); // 0.1 seconds
    }
    printf("\n💾 Database Saved Successfully\n");
}