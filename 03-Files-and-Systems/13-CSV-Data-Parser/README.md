# Project 13: CSV Data Analysis

## Goal

To build a tool that reads a structured text file (`students.csv`), breaks each line into usable pieces of data (**Name, ID, GPA**), stores them into a C `struct`, and performs statistical analysis (finding the average GPA).

This mimics how real-world software imports data from Excel.

---

## 1. The Input Data (`students.csv`)

Create a file named `students.csv` with this content.  
Note that it is just text, but structured with commas.

```csv
Name,ID,GPA
Alice Smith,101,3.5
Bob Jones,102,2.8
Charlie Day,103,3.9
David Lee,104,3.2
Eve White,105,4.0
````

---

## 2. Implementation Details

### The Data Structure

We need a `struct` to represent one row of the Excel sheet.

```c
typedef struct {
    char name[50];
    int id;
    float gpa;
} Student;
```

---

### The Complex Function: `strtok`

C does not have a simple `split()` function like Python or JavaScript.
We must use `strtok` (String Tokenizer).

**Concept**

* It is a *destructive* function.
* It modifies the original string by replacing the delimiter (`,`) with a `\0` (null terminator).

**Usage**

1. **First call**

   ```c
   strtok(line, ",");
   ```

   Returns a pointer to the first token (e.g., `"Alice Smith"`).

2. **Subsequent calls**

   ```c
   strtok(NULL, ",");
   ```

   Tells C to continue tokenizing the same string.

---

### Parsing Logic

1. Open the file in read mode (`"r"`).
2. Skip the first line (header row).
3. Loop using `fgets()` to read line by line.
4. Inside the loop:

   * `token = strtok(line, ",")` → Name
   * `token = strtok(NULL, ",")` → ID (convert using `atoi()`)
   * `token = strtok(NULL, ",")` → GPA (convert using `atof()`)

---

## 3. Expected Output

When you run the program:

```bash
./csv_parser
```

The output should look like this:

```text
--- CSV DATA PARSER ---
[INFO] Loading 'students.csv'...

ID      NAME                  GPA
----------------------------------------
101     Alice Smith           3.50
102     Bob Jones             2.80
103     Charlie Day           3.90
104     David Lee             3.20
105     Eve White             4.00
----------------------------------------
[STATS] Total Records: 5
[STATS] Average GPA:   3.48
[STATS] Highest GPA:   Eve White (4.00)
```

---
