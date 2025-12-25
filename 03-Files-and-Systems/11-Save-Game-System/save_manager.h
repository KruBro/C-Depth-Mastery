#ifndef SAVE_MANAGER_H
#define SAVE_MANAGER_H
#include<stdio.h>

typedef struct{
    char name[30];
    int level;
    int health;
    int maxHealth;
    int gold;
    int inventory[5];
} Hero;

//---Function Prototypes
void saveData(Hero *hero);
void loadData(Hero *hero);
void trainLevel(Hero *hero);
void foundGold(Hero *hero);
void takeDamage(Hero *hero);
void viewHexDump(const char *filename);

#endif