#include "save_manager.h"
#include <string.h>
int main()
{
    Hero hero;
    strcpy(hero.name, "Arthur");
    hero.level = 1;
    hero.health = 100;
    hero.maxHealth = 100;
    hero.gold = 50;
    for(int i = 0; i < 5; i++)
    {
        hero.inventory[i] = 0;
    }
    loadData(&hero);
    
    char *menu[] = {"[1] Train (Lvl Up)",
                "[2] Take Damage",
                "[3] Earn Gold)",
                "[4] SAVE Game",
                "[5] LOAD Game",
                "[6] View Save File (HEX DUMP)",
                "[7] Exit"};
    
    int choice;

    do
    {
        for(int i = 0; i < 7; i++) {printf("%s\n", menu[i]);}
        printf("Enter the choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: trainLevel(&hero); break;
            case 2: takeDamage(&hero); break;
            case 3: foundGold(&hero); break;
            case 4: saveData(&hero); break;
            case 5: loadData(&hero); break;
            case 6: viewHexDump("data.bin"); break;
            case 7: saveData(&hero); return 0; break;
            default:    printf("Invalid Choice\n");
        }
    } while (choice != 7);

}