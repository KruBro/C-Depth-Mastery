#include "parser.h"

int loadData(StudentDB *db)
{
    FILE *fp;
    fp = fopen("data.csv", "r");
    if(fp == NULL)
    {
        perror("Error: File Could Not Open!\n");
        return 0;
    }

    printf("[INFO] Loading 'data.csv'.......\n");
    int row = 0;
    char buffer[200];

    int count = 0;
    while(fgets(buffer, 200, fp) && count < MAX)
    {
        row++;
        if(row == 1) continue; //skip header

        //Removing trailing newline
        buffer[strcspn(buffer, "\n")] = 0;

        char *name = strtok(buffer, ",");
        char *id = strtok(NULL, ",");
        char *gpa  = strtok(NULL, ",");

        if(name && id && gpa)
        {
            strncpy(db->student[count].name, name, 49);
            db->student[count].name[49] = '\0';
            db->student[count].id = atoi(id);
            db->student[count].gpa = atof(gpa);
            count++;
        }
    }
    fclose(fp);
    printf("%d Datas has been loaded\n", count);

    return count;
}

float avgGpa(StudentDB *data)
{
    float sum = 0.0;
    for(int i = 0; i < data->studentCount; i++)
    {
        sum += data->student[i].gpa;
    }

    return (sum/data->studentCount);
}

float maxGpa(StudentDB *data)
{
    float max = 0;
    for(int i = 0; i < data->studentCount; i++)
    {
        if(data->student[i].gpa > max)
        {
            max = data->student[i].gpa;
        }
    }
    return max;
}

void print(StudentDB *data)
{
    char rankHolder[50];
    float highest = maxGpa(data);
    printf("\n----------------------------------------------\n");
    printf("%-10s %-25s %-15s\n", "ID", "NAME", "GPA");
    printf("\n----------------------------------------------\n");
    for(int i = 0; i < data->studentCount; i++)
    {
        if(data->student[i].gpa == highest)
        {
            strcpy(rankHolder, data->student[i].name);
        }
        printf("%-10d %-25s %-15.2f\n", data->student[i].id, 
                                data->student[i].name,
                                data->student[i].gpa);
    }
    printf("\n----------------------------------------------\n");
    printf("[STATS]---> Total Record: %d\n", data->studentCount);
    printf("[STATS]---> Average GPA: %f\n", avgGpa(data));
    printf("[STATS]---> Highest GPA: %.2f (%s)\n", highest, rankHolder);
}