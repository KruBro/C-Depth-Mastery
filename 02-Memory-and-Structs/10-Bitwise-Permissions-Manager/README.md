# Project 10: Bitwise Permission Manager

## Overview

This project demonstrates **bitwise flags** by implementing a console-based permission manager, similar to Linux `chmod`. A single `uint8_t` variable stores multiple permissions, showcasing how embedded systems efficiently manage state using bits instead of separate variables.

This project is **not theoretical**. Every example below matches the **exact behavior and output** of the provided program.

---

## Goal

Manage user permissions using **bitwise operators**:

* Add permissions
* Remove permissions
* Check permissions
* Toggle permissions

All permissions are packed into **one byte of memory**.

---

## Permission Mapping (Bit Flags)

Each permission corresponds to a specific bit position:

| Permission | Bit | Hex  | Binary    |
| ---------- | --- | ---- | --------- |
| READ       | 0   | 0x01 | 0000 0001 |
| WRITE      | 1   | 0x02 | 0000 0010 |
| EXECUTE    | 2   | 0x04 | 0000 0100 |
| ADMIN      | 3   | 0x08 | 0000 1000 |

The remaining bits are unused but reserved for future expansion.

---

## Core Concepts Used

### Bitwise Operators

| Operator      | Purpose      | Example              |       |              |
| ------------- | ------------ | -------------------- | ----- | ------------ |
| `             | ` OR         | Set a bit            | `user | = PERM_READ` |
| `&` AND       | Check a bit  | `user & PERM_WRITE`  |       |              |
| `& ~` AND NOT | Clear a bit  | `user &= ~PERM_EXEC` |       |              |
| `^` XOR       | Toggle a bit | `user ^= PERM_ADMIN` |       |              |

---

## Program Flow

1. Initialize user permissions to `0000 0000`
2. Display a menu-driven interface
3. Perform bitwise operations based on user choice
4. Print permissions as **8-bit binary output** after every operation

The program runs until the user selects **Exit**.

---

## Sample Output (Actual Program Output)

### Initial State

```
Current Permissions :Status:	[0000 0000]
```

---

### Add Read Permission

```
1. Add Read Permission
2. Add Write Permission
3. Add Execute Permission
4. Add Admin Privilage
Enter the choice: 1
Adding Read.....
User Has Read Permission...
Status:	[0000 0001]
```

---

### Add Write Permission

```
Adding Write.....
User Has Write Permission...
Status:	[0000 0011]
```

---

### Check Execute Permission

```
1. Check Read
2. Check Write
3. Check Execute
4. Check Admin
Enter choice: 3
❌ Access DENIED.
```

---

### Toggle Write Permission

```
Toggling Write.....
Status:	[0000 0001]
```

---

### Remove Read Permission

```
Removing Read.....
User is denied Read Permission...
Status:	[0000 0000]
```

---

## Key Learning Outcomes

* One byte can represent **multiple independent states**
* Bitwise operations are deterministic, fast, and memory-efficient
* This pattern is foundational for:

  * Embedded systems
  * Hardware registers
  * Device drivers
  * RTOS flags
  * Permission systems

---

## Why This Project Matters

If you understand this project, you understand how:

* GPIO pins are controlled
* Hardware registers are configured
* Interrupt flags work
* Real firmware is written

This is **embedded programming reality**, not classroom theory.

---

## Next Step

Replace menu-based input with **scripted permission masks** and decode them automatically — exactly how kernels and microcontrollers operate.

You are now officially past beginner-level C.
