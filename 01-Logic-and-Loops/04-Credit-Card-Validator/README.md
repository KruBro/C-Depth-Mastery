### **Project 04: Credit Card Validator (Luhn Algorithm)**

**Goal:** Create a program that takes a Credit Card Number as input (as a string) and determines if it is **Valid** or **Invalid** using the Luhn Algorithm.

---

### **1. Core Concepts**

* **String Manipulation:** Reading a long numeric sequence as a string (since credit card numbers exceed the size of a standard `int`).
* **ASCII to Integer Conversion:** Converting a character `'5'` into the integer `5` using the math trick `char - '0'`.
* **Modulo Operator (`%`):** Used to detect if the final sum is divisible by 10.
* **The Luhn Algorithm:** A checksum formula used to validate a variety of identification numbers.

---

### **2. The Logic Design (The Luhn Formula)**

The algorithm works from **Right to Left**.

1. **Step 1:** Starting from the **second to last digit** (index `N-2`), double the value of every **second** digit.

* *Constraint:* If doubling a number results in a value greater than 9 (e.g., 8 × 2 = 16), you must sum the digits of the result (1 + 6 = 7).
* *Shortcut:* If `num > 9`, use `num - 9`. (Mathematically equivalent).

2. **Step 2:** Add all the digits together (the newly processed ones and the skipped ones).
3. **Step 3:** Valid check.

* If `TotalSum % 10 == 0`, the card is **Valid**.
* Otherwise, it is **Invalid**.

#### **Visual Example:**

Card: `4561`

1. **Reverse/Right-to-Left traversal:** `1`, `6`, `5`, `4`
2. **Odd Positions (1st, 3rd...):** Keep as is. -> `1`, `5`
3. **Even Positions (2nd, 4th...):** Double them.

* `6` -> 12. (Logic: 1+2=3). Value is **3**.
* `4` -> 8. Value is **8**.

4. **Sum:** 1 + 3 + 5 + 8 = 17.
5. **Check:** 17 % 10 ≠ 0. **Invalid**.

---

### **3. Implementation Plan**

1. **Input:** Read the card number as a `string` (char array). Attempting to read it as an `int` will overflow.
2. **Length Check:** Calculate `strlen`. A valid card is usually between 13 and 19 digits.
3. **Traversal Loop:** Loop backwards from `length - 1` down to `0`.
4. **The Toggle Flag:** Use a variable `isSecond` (boolean logic) to track if you are on a digit that needs doubling. Flip it true/false every iteration.
5. **Summation:** Add the processed digit to `totalSum`.
6. **Validation:** Print result.

---

### **4. Sample Output**

```text
--- Credit Card Validator (Luhn Algorithm) ---

Enter Credit Card Number: 49927398716

Processing...
Length: 11 digits
Luhn Sum: 70

Status: VALID ✅

```

```text
--- Credit Card Validator (Luhn Algorithm) ---

Enter Credit Card Number: 1234567812345670

Processing...
Length: 16 digits
Luhn Sum: 67 (Not divisible by 10)

Status: INVALID ❌

```

---

### **Your Mission**

1. Create the `README.md`.
2. Open `main.c`.
3. **Concept check:**

* To get the integer value of a char `c`, use: `int digit = c - '0';`
* To toggle a flag `int isSecond = 0;`, inside the loop do: `isSecond = !isSecond;`
