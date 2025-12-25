#include "save_manager.h"
#include <ctype.h>
// 0x4F524548 is the Hex representation of ASCII text 'H' 'E' 'R' 'O'
// H=0x48, E=0x45, R=0x52, O=0x4F (stored in Little Endian usually)
#define MAGIC_ID 0x4F524548

void saveData(Hero *hero)
{
    FILE *fp = fopen("data.bin", "wb");
    if(fp == NULL) { perror("Error"); return; }

    // 1. Write the Security Stamp (Magic Number)
    int magic = MAGIC_ID;
    fwrite(&magic, sizeof(int), 1, fp);

    // 2. Write the Data
    fwrite(hero, sizeof(Hero), 1, fp);

    printf("Saved successfully with Magic ID.\n");
    fclose(fp);
}

void loadData(Hero *hero)
{
    FILE *fp = fopen("data.bin", "rb");
    if(fp == NULL) { 
        printf("No save file found. Starting New Game.\n"); 
        return; 
    }

    // 1. Read the first 4 bytes
    int fileMagic;
    fread(&fileMagic, sizeof(int), 1, fp);

    // 2. Security Check
    if (fileMagic != MAGIC_ID) {
        printf("⚠️  ERROR: Corrupt or Invalid Save File! (Magic Mismatch)\n");
        fclose(fp);
        return;
    }

    // 3. Safe to Load
    fread(hero, sizeof(Hero), 1, fp);
    printf("Save verified and loaded.\n");

    fclose(fp);
}

void trainLevel(Hero *hero)
{
    if(hero->level >= 20)
    {
        hero->level = 20;
        printf("Max Level has reached!\n");
        return;
    }
    hero->level += 1;
    printf("Training is complete! Level is now %d\n", hero->level);
}

void foundGold(Hero *hero)
{
    hero->gold += 500;
    printf("....Found 500 Gold\n");
    return;
}

void takeDamage(Hero *hero)
{
    if(hero->health <= 0)
    {
        printf("Player is already Dead\n");
        return;
    }
    int damage = -20;
    hero->health += damage;

    printf("Player took a damage of %d and current health is %d\n", damage, hero->health);
}
 // for isprint()

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