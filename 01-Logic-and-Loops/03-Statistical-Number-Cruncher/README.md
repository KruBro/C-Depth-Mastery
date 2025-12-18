---

### **Project 03: Statistical Number Cruncher**

**Goal:** Create a program that accepts a stream of `N` numbers (integers) from the user and calculates the four core statistical metrics: **Mean**, **Median**, **Mode**, and **Standard Deviation**.

---

### **1. Core Concepts**

* **1D Arrays:** Storing the dataset in memory.
* **Math Library (`math.h`):** Using `pow()` and `sqrt()` for deviation calculations.
* **Sorting Algorithms:** You **cannot** find the Median of a dataset unless it is sorted first. You must implement a sorting algorithm (like Bubble Sort or Selection Sort) manually.
* **Frequency Counting:** To find the Mode, you must count how many times each number appears.

---

### **2. The Logic Design**

#### **A. Mean (The Average)**

* **Logic:** Sum all elements and divide by the count (N).

#### **B. Sorting (The Prerequisite)**

Before finding the Median or Mode, the array **must be sorted** in ascending order.

* **Input:** `[5, 1, 4, 2, 5]`
* **Sorted:** `[1, 2, 4, 5, 5]`
* **Algorithm:** Use **Bubble Sort** (easiest to implement) or **Selection Sort**.

#### **C. Median (The Middle)**

* **If N is Odd:** The element exactly in the middle.
* Index = N / 2


* **If N is Even:** The average of the two middle elements.
* Index 1 = (N / 2) - 1
* Index 2 = N / 2



#### **D. Mode (The Most Common)**

* **Logic:** Traverse the sorted array. Count the frequency of the current number. If it exceeds the `maxCount` found so far, that number becomes the new Mode.

#### **E. Standard Deviation (The Spread)**

This measures how "spread out" the numbers are from the average.


1. Calculate the Mean.
2. For each number, subtract the Mean and square the result.
3. Sum all those squared differences.
4. Divide by N.
5. Take the square root.

---

### **3. Expected Output**

```text
--- Statistical Number Cruncher ---

Enter the number of elements (N): 6
Enter 6 numbers:
10 55 23 10 8 45

--- Results ---
Dataset (Sorted):  8, 10, 10, 23, 45, 55

MEAN:   25.17
MEDIAN: 16.50  (Average of 10 and 23)
MODE:   10     (Appears 2 times)
SD:     18.64

```

---

