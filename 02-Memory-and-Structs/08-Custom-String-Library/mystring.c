#include <stdio.h>
#include "mystring.h"

// Count characters until we hit '\0'
int my_strlen(char const *str)
{
    int len = 0;
    while(*str) // While value at address is NOT 0
    {
        len++;
        str++;  // Move to next memory address
    }
    return len;
}

// Copy source to destination byte-by-byte
char *my_strcpy(char *dest, char const *src)
{
    char *ptr = dest; // Save the Starting address to return later

    while(*src) // Loop until src hits null terminator
    {
        *dest = *src; // Copy value
        src++;        // Move src pointer forward
        dest++;       // Move dest pointer forward
    }

    *dest = '\0'; // Manual Null Termination is required!

    return ptr; // Return the original start address
}

// Append src to the end of dest
char *my_strcat(char *dest, char const *src)
{
    char *start = dest; // Save start address

    // 1. Fast-forward 'dest' pointer to the end of the string
    while (*dest != '\0') 
    {
        dest++; 
    }

    // 2. We are now sitting on the existing '\0'. Start copying over it.
    while (*src)
    {
        *dest = *src;
        dest++;
        src++;
    }

    // 3. Add the new null terminator at the very end
    *dest = '\0';

    return start;
}

// Compare two strings alphabetically
int my_strcmp(const char *s1, const char *s2)
{
    // Loop while s1 is not null AND values are equal
    // Note: The moment *s1 != *s2, the loop breaks.
    while(*s1 && (*s1 == *s2))
    {
        s1++;
        s2++;
    }

    // Return the difference between the mismatching characters
    // Cast to (unsigned char) to safely handle extended ASCII
    return *(unsigned char *)s1 - *(unsigned char *)s2;
}

// Reverse string in place using Two-Pointer approach
void my_strrev(char *str)
{
    // Pointer 1: The Head
    char *start = str; 
    
    // Pointer 2: The Tail
    // (Address of Start + Length - 1)
    char *end = str + my_strlen(str) - 1; 

    // Loop until pointers meet in the middle
    while (start < end)
    {
        // 1. Swap characters
        char temp = *start;
        *start = *end;
        *end = temp;

        // 2. Pinch pointers closer together
        start++; // Move Right
        end--;   // Move Left
    }
}