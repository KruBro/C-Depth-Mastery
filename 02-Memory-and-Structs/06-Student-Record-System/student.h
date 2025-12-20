#ifndef STUDENT_H
#define STUDENT_H

typedef struct {
    char id[12];
    char name[50];
    char gpa[5]; // Keeping GPA as string is fine for simple storage
} Student;

typedef struct {
    Student students[100];
    int studentCount;
} StudentDB;

// Renamed parameter to 'db' for clarity
void addStudent(StudentDB *db);
void viewStudents(StudentDB *db);
void saveFile(StudentDB *db);
int loadFile(StudentDB *db);

#endif