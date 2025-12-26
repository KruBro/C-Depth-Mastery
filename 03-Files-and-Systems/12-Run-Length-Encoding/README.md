Here is the `README.md` file tailored exactly to your project, with the output section transcribed directly from your screenshots to document your successful execution.

---

# Project 12: Run-Length Encoding (RLE) Compression Tool

**Phase 3: Files & Systems** **Date:** December 27, 2025

**Author:** Shahad K.

## 📂 Project Overview

This project implements a **Binary Compression Utility** using the **Run-Length Encoding (RLE)** algorithm. It demonstrates advanced file handling in C, moving beyond text files to manipulate raw binary data streams.

The tool reduces file size by detecting repeating sequences of bytes (e.g., "AAAAA") and replacing them with a compact binary pair: `[Count][Character]`.

### Key Features

* **Binary Serialization:** Reads and writes raw bytes (`rb`/`wb` modes) to handle non-text data.
* **Compression Logic:** Compresses repeating patterns into 2-byte pairs.
* **Decompression Logic:** Restores the original file perfectly from the binary format.
* **Hex Dump Viewer:** Integrated tool to visualize the raw memory of the files on disk.
* **Efficiency Tracking:** meaningful console output showing file size reduction.

---

## ⚙️ How It Works (The Logic)

### 1. The Compression Algorithm

The program reads the input file one byte at a time and compares it to the next byte.

* **Variables:** It tracks `current_char` and a `count`.
* **The Loop:**
* If `next_char == current_char`: Increment `count`.
* If `next_char != current_char` (Streak ends): Write the pair `[Count, Char]` to the file and reset.


* **The 255 Limit:** Since `count` is stored as an `unsigned char` (1 byte), it cannot exceed 255. If a run is longer than 255, the program forces a write and starts a new count for the remaining characters.

### 2. The Decompression Algorithm

The restoration process reverses the logic:

* It reads the file in **2-byte chunks**.
* **Byte 1:** The Count (How many times to repeat).
* **Byte 2:** The Character (What to repeat).
* It then runs a simple loop to print the character `N` times to the output file.

---

## 🔨 Build & Run

### Compilation

The project is modular. Compile all source files together:

```bash
gcc main.c compressor.c -o rle

```

### Execution

Run the executable. The program is interactive and will guide you through the process.

```bash
./rle

```

*(Ensure you have a `test.txt` file in the directory before running)*

---

## 🖥️ Execution Logs

*Evidence of successful compression and decompression based on `test.txt`.*

### Step 1: Compression

The input file (`test.txt`) contains patterns of repeated characters.

* **Original Size:** 167 bytes
* **Compressed Size:** 62 bytes
* **Result:** Significant size reduction (approx 63% smaller).

```text
Enter the file name to compress: test.txt
File To Compress is test.txt
test.txt file size before compression is 167

--- RAW HEX DUMP: test.txt ---
Offset   00 01 02 03 04 05 06 07   ASCII
........................................
0000     57 57 57 57 57 57 57 57   WWWWWWWW
0008     57 57 57 57 57 57 57 57   WWWWWWWW
0010     57 57 57 57 0A 57 2E 2E   WWWW.W..
0018     2E 2E 2E 2E 2E 2E 2E 2E   ........
...
[COMPRESS] processing......
File Size After Compression is 62

--- RAW HEX DUMP: compressed.rle ---
Offset   00 01 02 03 04 05 06 07   ASCII
........................................
0000     14 57 01 0A 01 57 12 2E   .W...W..
0008     01 57 01 0A 01 57 12 2E   .W...W..
0010     01 57 01 0A 01 57 03 2E   .W...W..
0018     0C 41 03 2E 01 57 01 0A   .A...W..

```

*Hex Explanation:* * `14 57` -> `0x14` is 20 in decimal. `0x57` is 'W'. This represents 20 'W's.

* `12 2E` -> `0x12` is 18. `0x2E` is '.'. This represents 18 dots.

### Step 2: Decompression

The tool reads `compressed.rle` and attempts to restore the original data into `test2.txt`.

```text
[DECOMPRESS] Processing...
[DONE] Decompression complete.
File Size After decompression is 167

--- RAW HEX DUMP: test2.txt ---
Offset   00 01 02 03 04 05 06 07   ASCII
........................................
0000     57 57 57 57 57 57 57 57   WWWWWWWW
0008     57 57 57 57 57 57 57 57   WWWWWWWW
0010     57 57 57 57 0A 57 2E 2E   WWWW.W..
...
00A0     57 57 57 57 57 57 57 57   WWWWWWWW

```

*Verification:* The decompressed file size (167 bytes) matches the original file size exactly. The data is identical.

---

## 📂 Project Structure

```text
.
├── main.c           # Entry point, menu logic, and file size helpers
├── compressor.c     # Implementation of RLE logic (compress/decompress)
├── compressor.h     # Function prototypes and includes
├── test.txt         # Original input file
├── compressed.rle   # The binary output file
└── test2.txt        # The restored file

```