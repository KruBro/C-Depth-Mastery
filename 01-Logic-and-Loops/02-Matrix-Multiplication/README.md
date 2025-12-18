### **Project 02: Matrix Multiplication Engine**

**Goal:** Create a program that multiplies two matrices (Matrix A and Matrix B) provided by the user.

---

### **1. Core Concepts**

* **2D Arrays:** Storing data in rows and columns (e.g., `matrix[row][col]`).
* **Nested Loops:** You will need **three** nested loops to perform the calculation.
* **Input Validation:** Not all matrices can be multiplied. You must enforce the mathematical rules of linear algebra.
* **Algorithm Complexity:** This is a classic O(N^3) algorithm.

---

### **2. The Logic Design**

#### **A. The Golden Rule**

You can only multiply Matrix A (R_1 \times C_1) by Matrix B (R_2 \times C_2) **IF AND ONLY IF**:

*(The columns of the first matrix must equal the rows of the second).*

If the user enters dimensions that violate this rule, your program must print an error and exit (or ask again).

#### **B. The Result Dimensions**

The resulting Matrix R will have dimensions:

*(Rows of the first, Columns of the second).*

#### **C. The Formula**

To find the value of a single cell in the Result Matrix R[i][j]:

* You must take the **Dot Product** of **Row i** from Matrix A and **Column j** from Matrix B.
* R[i][j] = \sum (A[i][k] \times B[k][j])

---

### **3. Implementation Plan**

1. **Input:** Ask user for dimensions of Matrix A (rows, cols).
2. **Input:** Ask user for dimensions of Matrix B (rows, cols).
3. **Validation:** Check if `colsA == rowsB`. If not, stop.
4. **Data Entry:** Use nested loops to let the user fill in the values for Matrix A and Matrix B.
5. **Calculation:**

* Initialize Result Matrix to 0.
* Loop `i` through Rows of A.
* Loop `j` through Columns of B.
* Loop `k` through Columns of A (the common dimension).
* Perform the multiplication and addition.

6. **Output:** Display the resulting matrix in a clean grid format.

---

### **4. Sample Output**

```text
--- Matrix Multiplication Engine ---

Enter rows and columns for Matrix A: 2 3
Enter rows and columns for Matrix B: 3 2

Checking compatibility... Valid.

Enter elements for Matrix A (2x3):
A[0][0]: 1
A[0][1]: 2
A[0][2]: 3
A[1][0]: 4
A[1][1]: 5
A[1][2]: 6

Enter elements for Matrix B (3x2):
B[0][0]: 7
B[0][1]: 8
B[1][0]: 9
B[1][1]: 1
B[2][0]: 2
B[2][1]: 3

--- Resultant Matrix (2x2) ---
   31   19
   85   55

```

*(Verification: Row1 `[1,2,3]` dot Col1 `[7,9,2]` = $1*7 + 2*9 + 3*2 = 7 + 18 + 6 = 31$. Correct.)*

---