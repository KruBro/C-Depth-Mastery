# Project 09: Hangman (State Machine)

## Overview

This project implements a **console-based Hangman game in C**. Unlike linear programs, this game operates as a **state machine**: the program’s behavior changes depending on player input (correct guess, wrong guess, repeated guess, win, or loss).

The game persists state across a loop using a structured data model and cleanly separates **game logic** from **user interaction**.

---

## Goal

* Randomly select a secret word (from `words.csv` if available).
* Display a masked version of the word using underscores.
* Allow the player to guess one letter at a time.
* Track guessed letters and remaining lives.
* End with a **WIN** or **GAME OVER** state.

---

## Core Concepts Demonstrated

### 1. State Machine Design

The game transitions between states based on input:

* Valid guess → correct or wrong
* Repeated guess → warning
* Lives reach 0 → loss
* Masked word equals secret word → victory

This is managed inside a controlled `while` loop:

```
while (lives > 0 && maskedWord != secretWord)
```

---

### 2. Structured State (`GameState`)

All persistent data is stored in a single struct:

```c
typedef struct {
    char secretWord[50];
    char maskWord[50];
    char guessedLetters[26];
    int lives;
    int guessesCount;
} GameState;
```

This avoids global variables and makes the game logic explicit and testable.

---

### 3. Masked Word Logic

Two strings are maintained:

* `secretWord` → the actual answer (e.g., `LINUX`)
* `maskWord` → what the user sees (`_ _ _ _ _`)

When a correct letter is guessed, all matching positions are revealed.

---

### 4. Input Validation & Duplicate Detection

The game strictly validates input:

* Non-alphabetic characters are rejected
* Previously guessed letters are detected and blocked

This prevents invalid state transitions.

---

## Program Flow

1. **Startup**

   * Seed RNG
   * Load a random word from `words.csv`
   * Initialize masked word and lives

2. **Main Game Loop**

   * Display lives remaining
   * Display masked word and guessed letters
   * Accept a single-character guess
   * Validate input
   * Update state accordingly

3. **End State**

   * If word is solved → Victory
   * If lives reach zero → Game Over

---

## Sample Output (Actual Program Behavior)

```
--- WELCOME TO HANGMAN ---

-----------------------------------
Lives Remaining: 5

Word: C _ D _ _ G 
Guessed: A S T
Guess a Character: I
✅ Good guess!

-----------------------------------
Lives Remaining: 5

Word: C _ D I _ G 
Guessed: A S T I
```

---

## Files

```
09-Hangman/
├── main.c          // Game loop & UI
├── game_logic.c   // Core game mechanics
├── game_logic.h   // Structs & prototypes
├── words.csv      // Word list (optional)
└── README.md
```

---

## Why This Project Matters

* Demonstrates **real state management**
* Reinforces **string manipulation**
* Uses **structs + pointers correctly**
* Clean separation of concerns (logic vs control)

This is no longer "learning C" — this is **using C correctly**.

---

## Next Possible Upgrades

* ASCII Hangman drawing by lives
* Difficulty levels (word length / lives)
* Save & resume game state
* Replace `scanf` with safer input handling

---

**Project Status:** Complete and solid

