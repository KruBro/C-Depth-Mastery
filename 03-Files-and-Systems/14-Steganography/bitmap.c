#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bitmap.h"

#define HEADER_SIZE 54

// Helper: Extract a specific bit (0 or 1) from a character
// Example: getBit('A', 0) returns the rightmost bit of 'A'
int getBit(char byte, int bitIndex) {
    return (byte >> bitIndex) & 1;
}

void hideMessage(const char *sourceFile, const char *destFile, const char *secret) {
    FILE *in = fopen(sourceFile, "rb");
    FILE *out = fopen(destFile, "wb");
    
    if (!in || !out) {
        perror("Error opening files");
        return;
    }

    // 1. COPY HEADER (First 54 bytes must remain untouched)
    BMPHeader header;
    fread(&header, sizeof(BMPHeader), 1, in);
    fwrite(&header, sizeof(BMPHeader), 1, out);

    printf("[ENCRYPT] Hiding message: \"%s\"\n", secret);

    // 2. ENCODE MESSAGE
    // We loop through the string, including the null terminator '\0'
    int len = strlen(secret);
    for (int i = 0; i <= len; i++) {
        char ch = secret[i];

        // Loop through the 8 bits of the character (7 down to 0)
        for (int bit = 7; bit >= 0; bit--) {
            unsigned char imgByte;
            if (fread(&imgByte, 1, 1, in) != 1) {
                printf("Error: Image too small for this message!\n");
                break;
            }

            // --- THE MAGIC ---
            // A. Clear the LSB (Least Significant Bit) of the image byte
            //    Example: 1111 1111 (255) & 1111 1110 (0xFE) becomes 1111 1110
            imgByte &= 0xFE;

            // B. Get the bit from our secret character (0 or 1)
            int secretBit = getBit(ch, bit);

            // C. Combine them using OR
            //    Example: 1111 1110 | 1 becomes 1111 1111
            imgByte |= secretBit;

            fwrite(&imgByte, 1, 1, out);
        }
    }

    // 3. COPY REST OF IMAGE
    // We must copy the remaining pixels or the image will look cut off
    int ch;
    while ((ch = fgetc(in)) != EOF) {
        fputc(ch, out);
    }

    printf("[SUCCESS] Message hidden in '%s'.\n", destFile);

    fclose(in);
    fclose(out);
}

void revealMessage(const char *sourceFile) {
    FILE *in = fopen(sourceFile, "rb");
    if (!in) {
        perror("Error opening file");
        return;
    }

    // 1. SKIP HEADER
    fseek(in, HEADER_SIZE, SEEK_SET);

    printf("[DECRYPT] Hidden Message: ");

    char ch = 0;
    while (1) {
        ch = 0; // Reset character builder

        // 2. RECONSTRUCT CHARACTER (Read 8 bytes -> Build 1 char)
        for (int bit = 7; bit >= 0; bit--) {
            unsigned char imgByte;
            if (fread(&imgByte, 1, 1, in) != 1) break;

            // A. Extract the LSB from the image byte
            int lsb = imgByte & 1;

            // B. Shift it into the correct position
            //    If we are at bit 7, we shift the LSB left by 7
            ch |= (lsb << bit);
        }

        // 3. CHECK TERMINATOR
        // If we hit the null terminator, the string is done
        if (ch == '\0') break;

        printf("%c", ch);
    }
    printf("\n");
    fclose(in);
}