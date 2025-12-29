#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

typedef struct {
    char secretWord[50];
    char maskWord[50];
    char guessedLetters[26];
    int lives;
    int guessesCount; // How many unique letters tried
} GameState;

// Core Functions
int loadWord(GameState *game);
int updateMaskWord(char *secretWord, char *maskWord, char guess);
void storeGuessWords(GameState *gamestate, char guess);
int isAlreadyGuessed(GameState *gamestate, char guess);
void printGameStatus(GameState *gamestate);

#endif
