#ifndef MYSTRING_H
#define MYSTRING_H

#include <stdio.h>

/*
 * Calculates the length of a string (excluding the null terminator).
 * Returns: Number of characters.
 */
int my_strlen(char const *str);

/*
 * Copies the string pointed to by src to dest.
 * Returns: Pointer to dest.
 */
char *my_strcpy(char *dest, char const *src);

/*
 * Appends the string src to the end of string dest.
 * Returns: Pointer to dest.
 */
char *my_strcat(char *dest, char const *src);

/*
 * Compares two strings lexicographically.
 * Returns: 0 if equal, <0 if s1 < s2, >0 if s1 > s2.
 */
int my_strcmp(const char *s1, const char *s2);

/*
 * Reverses a string in place (modifies the original string).
 */
void my_strrev(char *str);

#endif