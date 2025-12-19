/*
Project-05-CONWAYS-GAME-OF-LIFE
Read the README.md File for Implementation Details
*/ 

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h> // For sleep()

// --- Prototypes ---
int** dynamicAllocation(int rows, int cols);
void populateGrid(int **mat, int rows, int cols);
void print(int **arr, int rows, int cols);
int countNeighbours(int **arr, int currRow, int currCol, int maxRows, int maxCols);
void updateGrid(int **current, int **next, int rows, int cols);

int main()
{
    srand(time(NULL)); 

    // Randomize Grid Size (3x3 to 8x8)
    int rows = (rand() % 6) + 3;
    int cols = (rand() % 6) + 3;

    printf("Generating a %dx%d World....\n", rows, cols);
    sleep(1); // Brief pause to read the size

    int **mat = dynamicAllocation(rows, cols);
    int **matNext = dynamicAllocation(rows, cols);

    // Initial Setup
    populateGrid(mat, rows, cols);

    // The Simulation Loop
    while(1)
    {
        // 1. Clear Screen
        system("clear"); // Use "cls" if on Windows

        printf("--- Conway's Game of Life ---\n");
        printf("Grid Size: %dx%d | Press Ctrl+C to Stop\n\n", rows, cols);

        // 2. Visual Output
        print(mat, rows, cols);

        // 3. Calculate Next Gen
        updateGrid(mat, matNext, rows, cols);

        // 4. Swap Buffers (Update Current Grid)
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                mat[i][j] = matNext[i][j];
            }
        }
        
        // 5. Animation Delay (0.2 seconds is smoother than 1s)
        usleep(200000); 
    }

    // Cleanup (Unreachable in infinite loop, but good practice)
    for(int i=0; i<rows; i++) free(mat[i]);
    free(mat);
    for(int i=0; i<rows; i++) free(matNext[i]);
    free(matNext);
    
    return 0;
}

// --- Helper Functions ---

int** dynamicAllocation(int rows, int cols)
{
    int **mat = (int **)malloc(rows * sizeof(int *));
    for(int i = 0; i < rows; i++)
    {
        mat[i] = (int *)malloc(cols * sizeof(int));
    }
    return mat;
}

void populateGrid(int **mat, int rows, int cols)
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            // 20% Chance of being Alive at start (Cleaner look than 50/50)
            mat[i][j] = (rand() % 5 == 0) ? 1 : 0;
            // mat[i][j] = rand() & 1;
        }
    }
}

void print(int **arr, int rows, int cols)
{
    for(int i = 0; i < rows; i++)
    {
        printf("\t"); // Indent the grid slightly
        for(int j = 0; j < cols; j++)
        {
            // VISUAL UPDATE: Print '#' for Alive, '.' for Dead
            printf("%c  ", arr[i][j] ? '#' : '.');
        }
        printf("\n");
    }
}

int countNeighbours(int **arr, int currRow, int currCol, int maxRows, int maxCols)
{
    int count = 0;
    for(int i = -1; i <= 1; i++)
    {
        for(int j = -1; j <= 1; j++)
        {
            if(i == 0 && j == 0) continue;

            int newRow = currRow + i;
            int newCol = currCol + j;

            if(newRow >= 0 && newRow < maxRows && newCol >= 0 && newCol < maxCols)
            {
                if(arr[newRow][newCol] == 1) count++;
            }
        }
    }
    return count;
}

void updateGrid(int **current, int **next, int rows, int cols)
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            int neighbourCount = countNeighbours(current, i, j, rows, cols);
            int isAlive = current[i][j];

            // Rule 1 & 3: Die
            if(isAlive && (neighbourCount < 2 || neighbourCount > 3)) 
                next[i][j] = 0;
            // Rule 2: Survive
            else if(isAlive && (neighbourCount == 2 || neighbourCount == 3)) 
                next[i][j] = 1;
            // Rule 4: Birth
            else if(!isAlive && neighbourCount == 3)    
                next[i][j] = 1;
            // Status Quo
            else    
                next[i][j] = 0;    
        }
    }
}
