/*
 * Project: Bitwise Permission Manager
 * Author: Shahad K
 * 24 Dec 2025
 */
#include <stdio.h>
#include "permissions.h"

int main()
{
    uint8_t user = 0x0;
    printf("Current Permissions :");
    printStatusBits(&user);

    char *menu[] = {"1. Add Permissions",
        "2. Remove Permissions",
        "3. Check Permissions",
        "4. Toggle Permissions",
        "5. Exit"};
    
    int choice;
    
    do
    {
        for(int i = 0; i < 5; i++) {printf("%s\n", menu[i]);}
        printf("Enter the choice:\t");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: addPermission(&user);   break;
            case 2: removePermission(&user);    break;
            case 3: checkPermission(user); break;
            case 4: togglingPermission(&user); break;
            case 5: printf("Exiting\n\r");return 0; break;
            default: printf("Inavlid Choice!\n");
        }
    } while (choice != 5);
    

    return 0;
}
