/**
 * Project: Credit Card Validator (Luhn Algorithm)
 * Description: Validates a credit card number using the Luhn checksum formula.
 * Logic: Reverse string -> Double every 2nd digit -> Sum -> Check Modulo 10.
 */

#include <stdio.h>
#include <string.h>

// --- Function Prototypes ---
int calculateLuhnSum(const char *str);
void reverseString(char *str);

int main()
{
    char str[20]; // Buffer for card number (Standard max is 19 digits)

    printf("--- Credit Card Validator (Luhn Algorithm) ---\n");
    printf("Enter Credit Card Number: ");
    
    // Safety: Limit input to 19 chars to prevent buffer overflow
    scanf("%19s", str);

    printf("Processing...\n");
    int len = strlen(str);
    
    // Basic length validation (Cards are usually 13-19 digits)
    if(len < 13 || len > 19)
    {
        printf("[ERROR] Invalid Length. Credit cards are 13-19 digits.\n");
        printf("You entered: %d digits.\n", len);
        return 1;
    }

    // Step 1: Reverse the string to simulate "Right-to-Left" processing
    reverseString(str);

    // Step 2: Calculate checksum
    int totalSum = calculateLuhnSum(str);
    
    printf("Luhn Sum: %d\n", totalSum);

    // Step 3: Validation (Sum must be divisible by 10)
    if(totalSum % 10 == 0)
    {
        printf("Status: VALID\n");
    }
    else
    {
        printf("Status: INVALID (Check digit mismatch)\n");
    }
    
    return 0;
}

/**
 * Reverses a string in place.
 * Useful because Luhn requires processing from Right to Left.
 */
void reverseString(char *str)
{
    int start = 0;
    int end = strlen(str) - 1;

    while(start < end)
    {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

/**
 * Traverses the string and applies Luhn Logic:
 * 1. Double every 2nd digit (indices 1, 3, 5...).
 * 2. If doubled value > 9, subtract 9.
 * 3. Sum all values.
 */
int calculateLuhnSum(const char *str)
{
    int i = 0;
    int sum = 0;

    // Iterate through the reversed string
    while(str[i] != '\0')
    {
        // Convert Char '5' to Integer 5
        int digit = str[i] - '0';

        // Apply doubling rule to every ODD index (1, 3, 5...)
        // (Since we reversed the string, index 0 is the check digit, which is skipped)
        if(i % 2 != 0)
        {
            digit *= 2;
            
            // Logic: If result is 16, we need 1 + 6 = 7.
            // Math Trick: 16 - 9 = 7. Same result, faster calculation.
            if(digit > 9)
            {
                digit -= 9;
            }
        }

        sum += digit;
        i++; 
    }

    return sum;
}