/*
 * Project: Hangman Game
 * Author: Shahad K
 * 23 Dec 2025
 */
#include "game_logic.h"

int main()
{
    srand(time(NULL));
    GameState gamestate;
    
    // Load Word
    if(loadWord(&gamestate) != 0) {
        // Fallback if file fails
        strcpy(gamestate.secretWord, "LINUX");
        strcpy(gamestate.maskWord, "_____");
    }

    // Initialize Lives (e.g., 6 for standard Hangman)
    gamestate.lives = 6; 
    
    printf("--- WELCOME TO HANGMAN ---\n");

    // MAIN LOOP
    // Run while Lives > 0 AND Word is NOT solved
    while (gamestate.lives > 0 && strcmp(gamestate.secretWord, gamestate.maskWord) != 0)
    {
        printf("\n-----------------------------------\n");
        printf("Lives Remaining: %d\n", gamestate.lives);
        printGameStatus(&gamestate);

        char guess;
        printf("Guess a Character: ");
        scanf(" %c", &guess); // Space before %c skips whitespace/newlines

        // Validation
        if (!isalpha(guess)) {
            printf("⚠️  Please enter a valid letter (A-Z).\n");
            continue;
        }

        // Check Duplicate
        if (isAlreadyGuessed(&gamestate, guess)) {
            printf("⚠️  You already guessed '%c'!\n", toupper(guess));
            continue;
        }

        // Process Guess
        storeGuessWords(&gamestate, guess);
        
        if (updateMaskWord(gamestate.secretWord, gamestate.maskWord, guess)) {
            printf("✅ Good guess!\n");
        } else {
            printf("❌ Wrong!\n");
            gamestate.lives--; // Only decrease on failure
        }
    }

    // END GAME
    printf("\n-----------------------------------\n");
    printGameStatus(&gamestate); // Show final state
    
    if (strcmp(gamestate.secretWord, gamestate.maskWord) == 0) {
        printf("🏆 YOU WON! The word was: %s\n", gamestate.secretWord);
    } else {
        printf("💀 GAME OVER! The word was: %s\n", gamestate.secretWord);
    }

    return 0;
}
