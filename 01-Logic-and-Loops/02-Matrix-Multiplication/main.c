/**
 * Project: Matrix Multiplication Engine
 * Description: Multiplies two user-defined matrices (Row x Col).
 * Complexity: O(n^3) - Triple nested loop.
 * * Concepts: 2D Arrays, VLA (Variable Length Arrays), Pointer Decay.
 * Shahad K
 * 17-12-2025
 */

#include <stdio.h>

// --- Function Prototypes ---
void scanMatrix(int rows, int cols, int matrix[rows][cols]);
void multiplyMatrices(int r1, int c1, int r2, int c2, 
                      int m1[r1][c1], int m2[r2][c2], int result[r1][c2]);
void printMatrix(int rows, int cols, int matrix[rows][cols]);

int main() {
    int r1, c1, r2, c2;

    // 1. Input Dimensions
    printf("--- Matrix Multiplication Engine ---\n");
    printf("Enter rows and cols for Matrix A: ");
    if (scanf("%d %d", &r1, &c1) != 2) return 1;

    printf("Enter rows and cols for Matrix B: ");
    if (scanf("%d %d", &r2, &c2) != 2) return 1;

    // 2. Validation Rule: Cols of A must equal Rows of B
    if (c1 != r2) {
        printf("\n[ERROR] Multiplication impossible!\n");
        printf("Rule: Columns of A (%d) must match Rows of B (%d).\n", c1, r2);
        return 1; 
    }

    // 3. Declare Variable Length Arrays (VLAs)
    int matrixA[r1][c1];
    int matrixB[r2][c2];
    int resultMatrix[r1][c2];

    // 4. Data Entry
    scanMatrix(r1, c1, matrixA);
    scanMatrix(r2, c2, matrixB);

    // 5. Calculate & Output
    multiplyMatrices(r1, c1, r2, c2, matrixA, matrixB, resultMatrix);
    
    printf("\n----- Resultant Matrix (%dx%d) -----\n", r1, c2);
    printMatrix(r1, c2, resultMatrix);

    return 0;
}

/**
 * Scans integers into a 2D array.
 * Uses a static char to auto-increment from Matrix 'A' to 'B'.
 */
void scanMatrix(int rows, int cols, int matrix[rows][cols]) {
    static char matrixName = 'A'; // Remembers state between calls
    
    printf("\n[Enter elements for Matrix %c]\n", matrixName);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%c[%d][%d]: ", matrixName, i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
    matrixName++;
}

/**
 * Performs matrix multiplication: R = A * B
 * Formula: R[i][j] = Sum(A[i][k] * B[k][j])
 */
void multiplyMatrices(int r1, int c1, int r2, int c2, 
                      int m1[r1][c1], int m2[r2][c2], int result[r1][c2]) {
    // Loop through Rows of Matrix A
    for (int i = 0; i < r1; i++) {
        // Loop through Columns of Matrix B
        for (int j = 0; j < c2; j++) {
            result[i][j] = 0; // Initialize accumulator
            
            // Loop through the common dimension (Cols of A / Rows of B)
            for (int k = 0; k < c1; k++) {
                result[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
}

/**
 * Displays a matrix in a clean grid format.
 */
void printMatrix(int rows, int cols, int matrix[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        printf("\t"); // Indent the matrix
        for (int j = 0; j < cols; j++) {
            printf("%-5d", matrix[i][j]); // Left-align numbers
        }
        printf("\n");
    }
}
