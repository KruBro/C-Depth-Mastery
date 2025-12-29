/*
Project 07- RECURSIVE MAZE SOLVER
NB: 
WE USE RAND TO GENERATE A RANDOM MAZE, 
IT MIGHT GENERATE DEAD END MAZE WHERE NO SOULTION, 
THOUGH CHANCES ARE RARE FOR SUCH AN EVEN TO HAPPEN.
OUR PROGRAM DOES NOT FIND OPTIMAL PATH OR SHORT PATH,
IT ALWAYS MOVE UP/ DOWN/ LEFT/ RIGHT OF THE CURRENT POSITION.
IT IS JUST AN IMPLEMENTATION TEST FOR TESTING THE RECURSIVE FUNCTION KNOWLEDGE.
NB: THE COMMENDS YOU FIND BELOW ARE AI GENERATED FOR THE BETTER READBILITY.
>>>>HAPPY CODING<<<<<
Shahad K
21-12-2025
*/ 

#include <stdio.h>
#include <stdlib.h> // for rand(), srand(), system()
#include <time.h>   // for time()
#include <unistd.h> // for usleep()

#define ROWS 6
#define COLS 6

// Function Prototypes
int solveMaze(char maze[ROWS][COLS], int row, int col);
void printMaze(char maze[ROWS][COLS]);
void refreshFrame(char maze[ROWS][COLS]);
void generateRandomMaze(char maze[ROWS][COLS]);

int main() {
    // 1. Seed the random number generator
    // If you skip this, the "random" maze will be the same every time!
    srand(time(NULL));

    char maze[ROWS][COLS];

    // 2. Generate a fresh random maze
    generateRandomMaze(maze);

    // 3. Setup Animation
    printf("\033[H\033[J"); // Clear Screen
    printf("--- Random Maze Generated ---\n");
    printMaze(maze);
    sleep(1); // Pause for 1 second so you can see the problem before solving

    // 4. Solve
    if (solveMaze(maze, 0, 0)) {
        // Cursor to bottom to avoid overwriting the maze
        printf("\n\n--- Maze Solved! ---\n"); 
    } else {
        printf("\n\nNo Solution Found! (Random walls blocked the way)\n");
    }

    return 0;
}

void generateRandomMaze(char maze[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            // 30% Chance to be a Wall (#), 70% Chance to be a Path (.)
            int r = rand() % 100;
            if (r < 30) {
                maze[i][j] = '#';
            } else {
                maze[i][j] = '.';
            }
        }
    }

    // Force Start and End to be open (overwrite any random walls there)
    maze[0][0] = 'S';
    maze[ROWS-1][COLS-1] = 'E'; // Placing Exit at bottom-right corner
}

void printMaze(char maze[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (maze[i][j] == '*') printf("\033[1;32m* \033[0m");      // Green Path
            else if (maze[i][j] == '#') printf("\033[1;31m# \033[0m"); // Red Wall
            else if (maze[i][j] == 'S') printf("\033[1;33mS \033[0m"); // Yellow Start
            else if (maze[i][j] == 'E') printf("\033[1;33mE \033[0m"); // Yellow End
            else printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

void refreshFrame(char maze[ROWS][COLS]) {
    printf("\033[H"); // Move cursor to top-left
    printf("--- Solving ---\n");
    printMaze(maze);
    usleep(1000000); // 0.15 seconds delay
}

int solveMaze(char maze[ROWS][COLS], int row, int col) {
    // 1. BASE CASES
    if (row < 0 || row >= ROWS || col < 0 || col >= COLS) return 0;
    if (maze[row][col] == '#' || maze[row][col] == '*') return 0;
    if (maze[row][col] == 'E') return 1;

    // 2. RECURSIVE STEP
    if (maze[row][col] != 'S') maze[row][col] = '*'; // Mark Path
    
    refreshFrame(maze); // ANIMATE

    // Check all 4 directions
    if (solveMaze(maze, row - 1, col) == 1) return 1; // UP
    if (solveMaze(maze, row + 1, col) == 1) return 1; // DOWN
    if (solveMaze(maze, row, col - 1) == 1) return 1; // LEFT
    if (solveMaze(maze, row, col + 1) == 1) return 1; // RIGHT

    // 3. BACKTRACKING
    if (maze[row][col] != 'S') maze[row][col] = '.'; // Unmark
    
    refreshFrame(maze); // ANIMATE

    return 0;
}
