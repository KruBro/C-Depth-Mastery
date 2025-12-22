
---

````markdown
# Project 08: Custom String Library

**Phase 2: Memory & Pointers**

A manual re-implementation of the standard C string library (`<string.h>`), built to demonstrate a deep understanding of **pointer arithmetic and raw memory manipulation**. All string operations are performed by directly moving pointers—no array indexing shortcuts allowed.

---

## 🧠 The Challenge

In C, strings are contiguous blocks of memory terminated by a **null character (`'\0'`)**. To truly understand how strings work at the lowest level, this project enforces two strict constraints:

1. **NO `<string.h>`**  
   Every function is implemented from scratch—no standard string utilities are used.

2. **NO Brackets (`[]`)**  
   Array indexing is completely forbidden. All traversal is done using pointer arithmetic (`*ptr`, `ptr++`, `ptr--`).

---

## 🛠 Implemented Functions

| Function | Prototype | Description |
|--------|-----------|-------------|
| **Length** | `int my_strlen(const char *str)` | Counts characters until the null terminator is reached. |
| **Copy** | `char *my_strcpy(char *dest, const char *src)` | Copies characters from source to destination, byte-by-byte. |
| **Concatenate** | `char *my_strcat(char *dest, const char *src)` | Appends the source string to the end of the destination string. |
| **Compare** | `int my_strcmp(const char *s1, const char *s2)` | Performs lexicographical string comparison. |
| **Reverse** | `void my_strrev(char *str)` | Reverses a string in-place using a two-pointer (start/end) technique. |

---

## 🔬 Implementation Guarantees

- No array indexing (`[]`) is used anywhere in the project
- All string traversal relies solely on:
  - Pointer increment/decrement (`ptr++`, `ptr--`)
  - Dereferencing (`*ptr`)
- No helper functions from `<string.h>` are referenced or linked

---

## 🚀 How to Run

### 1. Compile

```bash
gcc main.c mystring.c -o mystring
````

### 2. Execute

```bash
./mystring
```

---

## 📂 Code Structure

* **`mystring.h`** — Function prototypes and declarations
* **`mystring.c`** — Core string logic implemented using pointer arithmetic
* **`main.c`** — Menu-driven CLI for testing and demonstration

---

## 📸 Sample Usage

```text
---------------------------------
welcome to my_string.h Demonstration
MENU:
1. my_strlen(char *)
2. my_strcpy(char *, const char*)
3. my_strcat(char *, const char *)
4. my_strcmp(char *, char *)
5. my_strrev(char *)
6. Exit
------------------------------
Enter the Choice:----> 5
Enter a string to Reverse:
Hello World
Before Reverse: Hello World
After Reverse: dlroW olleH
```

---

## ⚠️ Assumptions & Limitations

* Destination buffers must be sufficiently large (`my_strcpy`, `my_strcat`)
* Input strings must be valid and null-terminated
* Behavior is undefined for NULL pointers (consistent with standard C library behavior)

---

## 💡 Key Takeaway: Pointer Arithmetic

Instead of accessing memory via indices like `str[i]`, this library advances the pointer itself.

* **Array Indexing:** `str[i]` → translated internally to address arithmetic
* **Pointer Arithmetic:** `ptr++` → explicit control over memory traversal

This approach aligns closely with how low-level C code operates and builds a strong foundation for systems, embedded, and kernel-level programming.

---

## 🔁 Why Rebuild `<string.h>`?

Re-implementing standard library functions exposes:

* Memory layout awareness
* Pointer movement mechanics
* Boundary and termination handling
* Undefined behavior edges

This project prioritizes **understanding over convenience**.

```

---

Done.  
Commit it.  

```
