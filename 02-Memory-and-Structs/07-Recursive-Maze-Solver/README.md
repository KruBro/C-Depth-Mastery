### **Project 07: Recursive Maze Solver (Backtracking)**

**Goal:** Create a program that automatically navigates through a randomly generated 2D maze from a Start point (`S`) to an Exit (`E`) using **recursion and backtracking**, while visually animating the solving process in the terminal.

---

### **1. Core Concepts**

* **Recursion:** The maze is solved by a function that repeatedly calls itself to explore possible paths.
* **Base Cases:** Conditions that immediately stop recursion (out of bounds, wall, visited cell, or exit found).
* **Backtracking:** When a path fails, the algorithm undoes its move and tries a different direction.
* **Call Stack Visualization:** Each recursive call represents a decision point stored on the stack.
* **Terminal Animation:** ANSI escape codes are used to redraw the maze as it is being solved.

---

### **2. Maze Configuration (Matches Code)**

* Fixed maze size defined at compile time:

```c
#define ROWS 6
#define COLS 6
```

* Maze is **randomly generated** at runtime:

  * `30%` walls (`#`)
  * `70%` open paths (`.`)

* Special cells:

  * `S` → Start position (always at `[0][0]`)
  * `E` → Exit position (always at `[ROWS-1][COLS-1]`)

---

### **3. Cell Representation (Terminal Output)**

| Symbol | Meaning              | Color   |
| ------ | -------------------- | ------- |
| `S`    | Start                | Yellow  |
| `E`    | Exit                 | Yellow  |
| `#`    | Wall                 | Red     |
| `.`    | Empty Path           | Default |
| `*`    | Current / Final Path | Green   |

---

### **4. The Recursive Algorithm**

The solver is implemented using:

```c
int solveMaze(char maze[ROWS][COLS], int row, int col);
```

For **every step**, the following logic is applied **in order**:

1. **Out of bounds?** → return `0`
2. **Wall (`#`) or already visited (`*`)?** → return `0`
3. **Exit (`E`) found?** → return `1`
4. **Otherwise:**

   * Mark current cell as part of path (`*`) unless it is `S`
   * Animate the frame
   * Recursively try:

     * Up
     * Down
     * Left
     * Right
   * If any direction succeeds → return `1`
5. **Dead end:**

   * Unmark cell back to `.`
   * Animate backtracking
   * Return `0`

This guarantees that **all possible paths are explored** until the exit is found or all options fail.

---

### **5. Animation Flow**

1. Random maze is generated
2. Maze is printed once before solving
3. Recursive solving begins
4. Each recursive step:

   * Updates the maze
   * Clears and redraws the screen
   * Waits briefly (`usleep`)

This creates a visible, step‑by‑step solving animation.

---

### **6. Sample Output (Representative – Matches Code Behavior)**

**Initial Maze (Random Example):**

```text
--- Random Maze Generated ---
S . # . . .
. . . # . .
# . # . . .
. . . . # .
. # . . . .
. . . # . E
```

**During Solving (Animated):**

```text
--- Solving ---
S * # . . .
* * * # . .
# . # . . .
. . . . # .
. # . . . .
. . . # . E
```

**Final Result:**

```text
--- Maze Solved! ---
```

*(If the random walls block all paths, the program prints `No Solution Found!` instead.)*

---

### **7. Design Choices**

* **Edge Handling:**

  * Out-of-bounds positions are treated as invalid moves
* **Visited Tracking:**

  * Visited cells are marked with `*` to prevent infinite loops
* **No Wrapping:**

  * Maze edges do not wrap around

---

### **8. Files & Functions Overview**

* `generateRandomMaze()` – Creates a new random maze
* `printMaze()` – Prints the maze with colors
* `refreshFrame()` – Clears and redraws the screen for animation
* `solveMaze()` – Recursive backtracking solver
* `main()` – Setup, visualization, and execution

---

### **Your Mission**

1. Create this `README.md` file.
2. Compile and run the program.
3. Observe recursion, backtracking, and the call stack in action.

**If you truly understand this project, recursion will never scare you again.**
