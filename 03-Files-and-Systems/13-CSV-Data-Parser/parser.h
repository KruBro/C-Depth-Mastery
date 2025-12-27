#ifndef PARSER_H
#define PARSER_H
#define MAX 100
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    char name[50];
    int id;
    float gpa;
} Student;

typedef struct{
    Student *student;
    int studentCount;
} StudentDB;

int loadData(StudentDB *data);
float avgGpa(StudentDB *data);
float maxGpa(StudentDB *data);
void print(StudentDB *data);

#endif