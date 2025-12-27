#include "parser.h"

int main()
{
    StudentDB *db = (StudentDB *)malloc(sizeof(StudentDB));
    if(db == NULL)  return 1;
    db->student = (Student *)malloc(MAX * sizeof(Student));
    if(db->student == NULL)
    {
        free(db);
        return 1;
    }

    db->studentCount = 0;

    printf("\n---CSV DATA PARSER---\n");
    db->studentCount = loadData(db);
    print(db);

    free(db->student);
    free(db);

    return 0;
}