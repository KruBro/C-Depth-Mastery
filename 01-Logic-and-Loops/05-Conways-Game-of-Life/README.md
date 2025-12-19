### **Project 05: Conway’s Game of Life**

**Goal:** Create a terminal-based simulation of Conway’s Game of Life, where a grid of cells evolves over time according to fixed mathematical rules.

---

### **1. Core Concepts**

* **2D Dynamic Arrays:** The world grid is dynamically allocated using `malloc`.
* **Double Buffering:** Two grids are used:

  * `current` → read-only for the current generation
  * `next` → written with the next generation
    Updating in place is forbidden and will break the simulation.
* **Neighbor Checking:** Each cell checks up to 8 neighbors (horizontal, vertical, diagonal).
* **Terminal Animation:** The screen is cleared and redrawn every frame to create motion.

---

### **2. The Rules of Life**

For each cell, count its alive neighbors:

1. **Underpopulation:** Alive cell with fewer than 2 neighbors → **Dies**
2. **Survival:** Alive cell with 2 or 3 neighbors → **Lives**
3. **Overpopulation:** Alive cell with more than 3 neighbors → **Dies**
4. **Reproduction:** Dead cell with exactly 3 neighbors → **Becomes Alive**

All rules are applied simultaneously using the next buffer.

---

### **3. Grid Design**

* Grid size is **randomly generated at runtime**

  * Rows: 3 to 8
  * Columns: 3 to 8
* Cell representation:

  * `1` → Alive → printed as `#`
  * `0` → Dead → printed as `.`

Example visual:

```
#  .  .  #
.  #  #  .
.  .  .  .
#  .  #  .
```

---

### **4. One Generation Algorithm**

1. Clear the terminal screen.
2. Print the current grid.
3. For each cell `[i][j]`:

   * Count alive neighbors (out-of-bounds treated as dead).
   * Apply the Game of Life rules.
   * Store result in `nextGrid`.
4. Copy `nextGrid` into `currentGrid`.
5. Sleep for **0.2 seconds**.
6. Repeat forever.

---

### **5. Sample Output (Matches Implementation)**

```text
Generating a 5x6 World....

--- Conway's Game of Life ---
Grid Size: 5x6 | Press Ctrl+C to Stop

	.  .  #  .  .  .
	#  .  #  #  .  .
	.  #  .  .  .  .
	.  .  #  .  #  .
	.  .  .  .  .  .
```

*(Each frame updates every 0.2 seconds. Patterns may stabilize, oscillate, or die out.)*

---

### **6. Functions Overview**

* **`dynamicAllocation(rows, cols)`**

  * Dynamically allocates a 2D grid.

* **`populateGrid()`**

  * Initializes the grid with a ~20% chance of alive cells.

* **`print()`**

  * Displays the grid using `#` and `.` characters.

* **`countNeighbours()`**

  * Counts alive neighbors safely (edges treated as dead).

* **`updateGrid()`**

  * Applies all Game of Life rules using double buffering.

---

### **7. Design Choice: Edge Handling**

**Easy Mode (Used):**

* Cells outside the grid are always treated as **dead**.
* No wrap-around behavior.

This keeps the logic correct and readable.

---

### **Final Notes**

* This program runs in an **infinite loop**. Exit with `Ctrl + C`.
* Memory is dynamically allocated and logically cleaned up (though unreachable).
* Correct behavior can be verified by observing still lifes and oscillators.

**This is the Phase‑1 Boss Battle. If this works correctly, your loop and array fundamentals are solid.**
