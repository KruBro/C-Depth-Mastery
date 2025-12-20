### **Project 06: Student Record Manager**

**Goal:** Create a persistent database application that manages student records. Student data must be saved to a text file (`records.txt`) so that records remain available even after the program is closed and reopened.

---

### **1. Core Concepts**

* **Structures (`struct`):** Used to group related data (ID, Name, GPA) into a single custom data type.
* **File I/O (Persistence):**

  * `fopen()` – Open a file stream
  * `fprintf()` – Write formatted data to a file
  * `fscanf()` – Read formatted data from a file
  * `fclose()` – Close the file safely
* **Pointers to Structs:** Passing a `Student *` avoids expensive data copying and allows direct modification.
* **Arrays of Structs:** Used as an in-memory database.

---

### **2. Data Structure Definition**

Each student record follows this structure:

```c
typedef struct {
    int id;
    char name[50];
    float gpa;
} Student;
```

This structure represents a single row in the student database.

---

### **3. Logic Design (Menu System)**

The program runs inside an infinite loop (`while(1)`) and presents a menu-driven interface:

```
--- Student Record System ---
1. Add Student
2. View Students
3. Save & Exit
```

#### **Menu Operations**

1. **Add Student**

   * Prompt user for:

     * Student ID
     * Student Name
     * GPA
   * Store the record in an array: `Student database[100]`

2. **View Students**

   * Loop through the database array
   * Display all stored student records

3. **Save & Exit**

   * Open `records.txt`
   * Write all student records to the file
   * Close the file
   * Exit the program

---

### **4. File Handling Strategy**

* **Automatic Load on Startup**

  * When the program starts, it opens `records.txt` (if it exists)
  * Reads stored student records into the database array

* **Manual Save on Exit**

  * All records are written back to `records.txt` before exiting

This guarantees data persistence across program restarts.

---

### **5. Sample Output**

```text
--- Student Record System ---
1. Add Student
2. View Students
3. Save & Exit
Choice: 1

Enter ID: 101
Enter Name: John_Doe
Enter GPA: 3.8
Student Added!
```

```text
--- Student Record System ---
1. Add Student
2. View Students
3. Save & Exit
Choice: 2

ID: 101 | Name: John_Doe | GPA: 3.8
```

*(If the program is restarted, John_Doe should still be present.)*

---

### **6. Constraints & Notes**

* Maximum students: **100**
* Names are read without spaces (use underscores if needed)
* File format must remain consistent for correct reading/writing
* Always close files after use to avoid corruption

---

### **Your Mission**

1. Create this `README.md` file.
2. Implement `main.c` using structs, file I/O, and a menu loop.
3. Verify persistence by restarting the program and confirming saved records reload correctly.

**This project introduces real-world persistence. If this works, you are no longer writing throwaway programs.**
