#include "permissions.h"

void printStatusBits(uint8_t *user)
{
    uint8_t *ptr = user;
    printf("Status:\t");
    printf("[");
    for(int i = 7; i >= 0; i--)
    {
        if((i+1) % 4 == 0 & i != 7)    printf(" ");
        if(*ptr >> i & 1)  printf("1");
        else    printf("0");
    }
    printf("]");
    printf("\n");
}

void addPermission(uint8_t *user)
{
    char *subMenu[] = {"1. Add Read Permission", 
        "2. Add Write Permission", 
        "3. Add Execute Permission", 
        "4. Add Admin Privilage"};
    
    for(int i = 0; i < 4; i++) {printf("%s\n", subMenu[i]);}

    int choice;
    printf("Enter the choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1: 
            printf("Adding Read.....\n");
            *user |= PERM_READ;
            printf("User Has Read Permission...\n");
            printStatusBits(user);
            break;
        case 2:
            printf("Adding Write.....\n");
            *user |= PERM_WRITE;
            printf("User Has Write Permission...\n");
            printStatusBits(user);
            break;
        case 3: 
            printf("Adding Execute.....\n");
            *user |= PERM_EXEC;
            printf("User Has Execute Permission...\n");
            printStatusBits(user);
            break;
        case 4:
            printf("Adding Admin Privilage.....\n");
            *user |= PERM_ADMIN;
            printf("User has Admin Privilage...\n");
            printStatusBits(user);
            break;
        default:
            printf("Invalid Choice\n");
    }
}

void removePermission(uint8_t *user)
{
        char *subMenu[] = {"1. Remove Read Permission", 
        "2. Remove Write Permission", 
        "3. Remove Execute Permission", 
        "4. Remove Admin Privilage"};
    
    for(int i = 0; i < 4; i++) {printf("%s\n", subMenu[i]);}

    int choice;
    printf("Enter the choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1: 
            printf("Removing Read.....\n");
            *user &= ~PERM_READ;
            printf("User is denied Read Permission...\n");
            printStatusBits(user);
            break;
        case 2:
            printf("Removing Write.....\n");
            *user &= ~PERM_WRITE;
            printf("User is denied Write Permission...\n");
            printStatusBits(user);
            break;
        case 3: 
            printf("Removing Execute.....\n");
            *user &= ~PERM_EXEC;
            printf("User is denied Execute Permission...\n");
            printStatusBits(user);
            break;
        case 4:
            printf("Removing Admin Privilage.....\n");
            *user &= ~PERM_ADMIN;
            printf("User is denied Admin Access...\n");
            printStatusBits(user);
            break;
        default:
            printf("Invalid Choice\n");
    }   
}

void checkPermission(uint8_t user)
{
    char *subMenu[] = {"1. Check Read", 
                       "2. Check Write", 
                       "3. Check Execute", 
                       "4. Check Admin"};
    
    for(int i = 0; i < 4; i++) { printf("%s\n", subMenu[i]); }

    int choice;
    printf("Enter choice: ");
    scanf("%d", &choice);

    uint8_t mask = 0;
    
    // Map choice to the correct bitmask
    switch(choice) {
        case 1: mask = PERM_READ; break;
        case 2: mask = PERM_WRITE; break;
        case 3: mask = PERM_EXEC; break;
        case 4: mask = PERM_ADMIN; break;
        default: printf("Invalid choice.\n"); return;
    }

    if( (user & mask) == mask ) {
        printf("✅ Access GRANTED.\n");
    } else {
        printf("❌ Access DENIED.\n");
    }
}

void togglingPermission(uint8_t *user)
{
    char *subMenu[] = {"1. Remove Read Permission", 
        "2. Remove Write Permission", 
        "3. Remove Execute Permission", 
        "4. Remove Admin Privilage"};
    
    for(int i = 0; i < 4; i++) {printf("%s\n", subMenu[i]);}

    int choice;
    printf("Enter the choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1: 
            printf("Togglinng Read.....\n");
            *user ^= PERM_READ;
            printStatusBits(user);
            break;
        case 2:
            printf("Toggling Write.....\n");
            *user ^= PERM_WRITE;
            printStatusBits(user);
            break;
        case 3: 
            printf("Toggling Execute.....\n");
            *user ^= PERM_EXEC;
            printStatusBits(user);
            break;
        case 4:
            printf("Toggling Admin Privilage.....\n");
            *user ^= PERM_ADMIN;
            printStatusBits(user);
            break;
        default:
            printf("Invalid Choice\n");
    }       
}