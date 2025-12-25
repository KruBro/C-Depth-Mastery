````markdown
# Project 11: Binary Save System

## Overview

This project implements a **binary save/load system** for a game character using **raw memory serialization** in C.  
Instead of storing data in human-readable text, the program writes the **exact memory representation** of a `struct` directly to disk.

This mirrors how **real games, embedded systems, and low-level software** persist state efficiently and securely.

---

## Why Binary Saves?

Binary storage is used because:

- ⚡ **Fast** — no string parsing or conversion overhead
- 💾 **Efficient** — fixed-size memory layout
- 🔒 **Obfuscated** — unreadable in text editors
- 🧠 **Low-level control** — exact byte-for-byte persistence

This is fundamentally different from CSV or text-based saves.

---

## Core Concepts Used

- Binary File I/O (`"wb"`, `"rb"`)
- Struct Serialization using `fwrite()` and `fread()`
- Magic Number Validation (file integrity check)
- Persistent Game State
- Manual Hex Dump Inspection

---

## Data Structure (Serialized)

```c
typedef struct {
    char name[30];
    int level;
    int health;
    int maxHealth;
    int gold;
    int inventory[5];
} Hero;
````

The entire structure is written to disk **as raw memory**, not field-by-field.

---

## Save File Layout (`data.bin`)

| Offset | Size | Description                        |
| ------ | ---- | ---------------------------------- |
| 0x00   | 4    | Magic Number (0x4F524548 = "HERO") |
| 0x04   | N    | Raw Hero struct memory             |

---

## Magic Number Protection

Before loading any save file, the program:

1. Reads the first 4 bytes
2. Compares them against the expected Magic ID
3. Rejects the file if the value does not match

This prevents:

* Loading corrupt files
* Reading invalid binary formats
* Accidental misuse of wrong files

---

## Program Flow

### Startup

* Initialize a default Hero
* Attempt to load `data.bin`
* If no file exists → start a new game

---

### Main Menu

```
[1] Train (Lvl Up)
[2] Take Damage
[3] Earn Gold
[4] SAVE Game
[5] LOAD Game
[6] View Save File (HEX DUMP)
[7] Exit
```

---

## Feature Behavior

### Train (Level Up)

* Increases level by 1
* Caps at **Level 20**

### Take Damage

* Reduces health by 20
* Prevents further damage if health is already zero

### Earn Gold

* Adds **500 gold**

### SAVE Game

* Writes Magic Number
* Writes entire Hero struct to `data.bin`

### LOAD Game

* Validates Magic Number
* Restores Hero state safely

### View Save File (HEX DUMP)

* Reads `data.bin` in binary mode
* Displays:

  * File offsets
  * Hexadecimal byte values
  * ASCII equivalents (if printable)

Example output:

```
--- RAW HEX DUMP: data.bin ---
Offset   00 01 02 03 04 05 06 07   ASCII
------------------------------------------------
0000     48 45 52 4F 41 72 74 68   HEROArth
0008     75 72 00 00 00 00 00 00   ur......
------------------------------------------------
```

This confirms the file contains **raw binary data**, not text.

---

## Binary vs Text Storage

| Text Mode          | Binary Mode        |
| ------------------ | ------------------ |
| `"12"` → 2 bytes   | `int 12` → 4 bytes |
| Human-readable     | Machine-native     |
| Easy to edit/cheat | Hard to tamper     |
| Parsing required   | Direct memory copy |

---

## Files

* `main.c` — Menu system & game loop
* `save_manager.c` — Save, Load, Hex Dump logic
* `save_manager.h` — Struct and function declarations
* `data.bin` — Binary save file (generated at runtime)

---

## What This Project Demonstrates

* Understanding of **binary serialization**
* Safe persistence using validation
* Awareness of memory layout
* Ability to inspect raw data manually

This is **systems programming**, not scripting.

---

## Next Improvements

* Save file versioning
* Checksums / CRC validation
* Multiple save slots
* Endianness handling
* Memory-mapped file I/O

---

## Final Note

If you understand this project fully, you understand how:

* Games save progress
* Embedded devices store configuration
* Systems preserve state across reboots

This is not beginner C anymore.
This is **low-level software engineering**.

```
```

