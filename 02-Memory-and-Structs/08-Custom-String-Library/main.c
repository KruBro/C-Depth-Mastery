#include <stdio.h>
#include "mystring.h"

int main()
{

    printf("\n---------------------------------\n");
    printf("welcome to my_string.h Demonstration\n");
    int choice;
    char *mainMenu[] = {"1. my_strlen(char *)", 
                        "2. my_strcpy(char *, const char*)",
                        "3. my_strcat(char *, const char *)", 
                        "4. my_strcmp(char *, char *)", 
                        "5. my_strrev(char *)", 
                        "6. Exit"};

    char s1[50], s2[50];

    do
    {
        printf("MENU:\n");
        for(int i = 0; i < 6; i++) {printf("%s\n", mainMenu[i]); }
        printf("\n------------------------------\n");
        printf("Enter the Choice:---->");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: 
                printf("Enter a string to find the length:\n");
                scanf(" %[^\n]", s1);

                printf("length of the string --> %s = %d\n", s1, my_strlen(s1));

                break;
            case 2:
                printf("Enter a string:\n");
                scanf(" %[^\n]", s1);
                printf("Enter a string you want to copy to '%s':\n", s1);
                scanf(" %[^\n]", s2);

                printf("Result: %s\n", my_strcpy(s1,s2));
                break;
            case 3:
                printf("Enter a string:\n");
                scanf(" %[^\n]", s1);
                printf("Enter a string you want to append to '%s':\n", s1);
                scanf(" %[^\n]", s2);

                printf("Result: %s\n", my_strcat(s1,s2));
                break;
            case 4: 
                printf("Enter a string:\n");
                scanf(" %[^\n]", s1);
                printf("Enter a string you want to compare with '%s':\n", s1);
                scanf(" %[^\n]", s2);

                if(my_strcmp(s1,s2))    printf("%s != %s\n", s1,s2);
                else    printf("%s is equal to %s\n", s1,s2);
                break;
            case 5: 
                printf("Enter a string to Reverse:\n");
                scanf(" %[^\n]", s1);
                printf("Before Reverse: %s\n", s1);
                my_strrev(s1);
                printf("After Reverse: %s\n", s1);
                break;
            default:
                printf("Invalid Choice\n");
        }
    } while (choice != 6);
    
    return 0;
}