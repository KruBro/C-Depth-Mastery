#include "hexvr.h"
#define BYTES_PER_LINE 16

void viewHex(const char *fileName)
{
    FILE *fp = fopen(fileName, "rb");
    if(fp == NULL)
    {
        perror("Error: File Could Not Open\n");
        return;
    }

    unsigned char buffer[BYTES_PER_LINE];
    size_t byteRead;
    size_t offset = 0;

    printf("----- HEX DUMP: %s -----\n", fileName);
    printf("Offset    00 01 02 03 04 05 06 07  08 09 0A 0B 0C 0D 0E 0F  |ASCII|\n");
    printf("-----------------------------------------------------------------------\n");

    while((byteRead = fread(buffer, 1, BYTES_PER_LINE, fp)) > 0)
    {
        // 1. Column: Offset
        printf("%08lX  ", (unsigned long)offset);

        // 2. Column: Hex Bytes
        for(int i = 0; i < BYTES_PER_LINE; i++)
        {
            // Extra space after 8th byte for readability (split 16 into 8+8)
            if(i == 8) printf(" ");

            if(i < byteRead) 
                printf("%02X ", buffer[i]); // FIX 3: %02X for leading zeros
            else    
                printf("   "); // FIX 4: 3 spaces to match "%02X " width
        }

        printf(" |");

        // 3. Column: ASCII Decoding
        for(int i = 0; i < byteRead; i++)
        {
            if(isprint(buffer[i]))  
                printf("%c", buffer[i]);
            else    
                printf("."); // Non-Printable Char
        }

        printf("|\n");
        offset += byteRead;
    }

    printf("-----------------------------------------------------------------------\n");
    fclose(fp);
}