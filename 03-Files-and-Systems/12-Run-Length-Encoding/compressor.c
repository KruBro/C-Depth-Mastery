#include "compressor.h"

long getFileSize(const char *filename)
{
    FILE *fp; 
    fp = fopen(filename, "rb");
    if(!fp)
    {
        perror("Error: File Not Could Open!\n");
        return 1;
    }

    fseek(fp ,0, SEEK_END);
    long size = ftell(fp);
    fclose(fp);
    return size;
}

void compressFile(const char *inputFile, const char *outputFile)
{
    FILE *in = fopen(inputFile, "r");
    FILE *out = fopen(outputFile, "wb");

    if(!in || !out) {
        perror("Error Opening File");
        return;
    }

    int current = fgetc(in);
    if(current == EOF) { fclose(in); fclose(out); return; } // Empty file check

    int next;
    unsigned char count = 1;

    printf("[COMPRESS] processing......\n");

    while((next = fgetc(in)) != EOF)
    {
        if(next == current)
        {
            // Same character? Increase count.
            count++;
            
            // Edge Case: Byte Overflow (255)
            if(count == 255)
            {
                unsigned char chToWrite = (unsigned char) current;
                fwrite(&count, 1, 1, out);
                fwrite(&chToWrite, 1, 1 ,out);
                count = 0; // Reset counter, we keep the same 'current'
            }
        }
        else
        {
            // Different character? Streak ended.
            // 1. Write the previous streak
            unsigned char chToWrite = (unsigned char) current;
            fwrite(&count, 1, 1, out);
            fwrite(&chToWrite, 1, 1 ,out);

            // 2. Start the new streak
            current = next;
            count = 1;
        }
    }

    // The loop ended because we hit EOF, but we are still holding 
    // the data for the very last run. We must write it now.
    unsigned char chToWrite = (unsigned char) current;
    fwrite(&count, 1, 1, out);
    fwrite(&chToWrite, 1, 1 ,out);

    fclose(in);
    fclose(out);
}


void viewHexDump(const char *filename)
{
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL)
    {
        printf("Error: Could not open file '%s'\n", filename);
        return;
    }

    printf("\n--- RAW HEX DUMP: %s ---\n", filename);
    printf("Offset   00 01 02 03 04 05 06 07   ASCII\n");
    printf("------------------------------------------------\n");

    unsigned char buffer[8]; // Read 8 bytes at a time (1 row)
    size_t bytesRead;
    int offset = 0;

    // Loop until we reach End of File
    while ((bytesRead = fread(buffer, 1, 8, fp)) > 0)
    {
        // 1. Print Offset (Where we are in the file)
        printf("%04X     ", offset);

        // 2. Print Hex Bytes
        for (int i = 0; i < 8; i++)
        {
            if (i < bytesRead)
                printf("%02X ", buffer[i]);
            else
                printf("   "); // Padding for partial last row
        }

        printf("  ");

        // 3. Print ASCII Representation (The "Decode")
        for (int i = 0; i < bytesRead; i++)
        {
            // isprint checks if char is readable (like 'A' or '5')
            // If it's unreadable (like value 0 or 10), print '.'
            if (isprint(buffer[i]))
                printf("%c", buffer[i]);
            else
                printf(".");
        }

        printf("\n");
        offset += 8;
    }

    fclose(fp);
    printf("------------------------------------------------\n");
}

void decompressFile(const char *inputFile, const char *outputFile) {
    FILE *in = fopen(inputFile, "rb"); // Read Binary pairs
    FILE *out = fopen(outputFile, "w"); // Write Text
    
    if (!in || !out) { 
        perror("Error opening file"); 
        return; 
    }

    printf("[DECOMPRESS] Processing...\n");
    
    unsigned char count;
    unsigned char ch; // Use unsigned to safely handle byte values 0-255

    // Loop: Attempt to read the 'Count' byte
    while (fread(&count, 1, 1, in) == 1) 
    {
        // Immediately read the 'Character' byte
        if (fread(&ch, 1, 1, in) != 1) {
            printf("[ERROR] File is corrupt (missing pair for count %d)\n", count);
            break;
        }

        // Expand: Write the character 'count' times
        for (int i = 0; i < count; i++) {
            fputc(ch, out);
        }
    }

    printf("[DONE] Decompression complete.\n");

    fclose(in);
    fclose(out);
}
