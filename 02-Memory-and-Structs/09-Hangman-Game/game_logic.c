#include "game_logic.h"

int validateGuess(const char c) {
    return isalpha(c);
}

void initMaskWord(const char *secret, char *mask) {
    int len = strlen(secret);
    for (int i = 0; i < len; i++) {
        mask[i] = '_';
    }
    mask[len] = '\0'; // Null terminate!
}

int loadWord(GameState *game) {
    FILE *fp = fopen("words.csv", "r");
    if (fp == NULL) {
        printf("Error: words.csv not found. Using default.\n");
        strcpy(game->secretWord, "DEFAULT");
        initMaskWord(game->secretWord, game->maskWord);
        return 1;
    }

    // 1. Count Lines
    int lines = 0;
    char buffer[100];
    while (fgets(buffer, 100, fp)) lines++;
    rewind(fp);

    // 2. Pick Random Line
    int randomLine = rand() % lines;
    for (int i = 0; i <= randomLine; i++) {
        fgets(buffer, 100, fp);
    }
    fclose(fp);

    // 3. Clean string (Remove newline)
    buffer[strcspn(buffer, "\n")] = 0;
    
    // 4. Set State
    strcpy(game->secretWord, buffer);
    initMaskWord(game->secretWord, game->maskWord);
    
    // Clear guessed letters
    game->guessesCount = 0;
    memset(game->guessedLetters, 0, 26);
    
    return 0;
}

int updateMaskWord(char *secretWord, char *maskWord, char guess) {
    int found = 0;
    int len = strlen(secretWord);
    guess = toupper(guess);

    for (int i = 0; i < len; i++) {
        if (secretWord[i] == guess) {
            maskWord[i] = guess;
            found = 1;
        }
    }
    return found;
}

int isAlreadyGuessed(GameState *gamestate, char guess) {
    guess = toupper(guess);
    for (int i = 0; i < gamestate->guessesCount; i++) {
        if (gamestate->guessedLetters[i] == guess) {
            return 1; // True
        }
    }
    return 0; // False
}

void storeGuessWords(GameState *gamestate, char guess) {
    if (gamestate->guessesCount < 26) { // FIX: Changed > to <
        gamestate->guessedLetters[gamestate->guessesCount] = toupper(guess);
        gamestate->guessesCount++;
    }
}

void printGameStatus(GameState *gamestate) {
    printf("\nWord: ");
    for(int i = 0; gamestate->maskWord[i] != '\0'; i++) {
        printf("%c ", gamestate->maskWord[i]);
    }
    printf("\nGuessed: ");
    for(int i = 0; i < gamestate->guessesCount; i++) {
        printf("%c ", gamestate->guessedLetters[i]);
    }
    printf("\n");
}
