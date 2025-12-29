# Project 15: Hex Dump Viewer (hexvr)

## Phase 3: Files & Systems

---

## 📌 Goal

The goal of **hexvr** is to provide a **binary-accurate inspection tool** that displays the raw contents of any file **without interpretation, decoding, or corruption**.

Standard text editors attempt to interpret bytes as characters using encodings such as ASCII or UTF-8. This interpretation layer hides the actual data stored on disk.

**hexvr bypasses all decoding layers** and exposes the true byte-level structure of a file exactly as it exists.

This tool is designed to:

- Verify binary file formats created in earlier projects  
- Inspect headers, metadata, and payload regions  
- Understand how data is physically laid out in storage  
- Debug corrupted or malformed binary files  

The output follows the **industry-standard hex dump layout** used by debuggers, firmware tools, and reverse-engineering utilities.

---

## 🧠 Output Structure

Each row of output represents **16 consecutive bytes** from the file and is divided into three aligned columns.

### 1. Offset (Address)

- Indicates the byte position in the file where the row begins  
- Displayed in hexadecimal  
- Mirrors memory and storage addressing conventions  

### 2. Hexadecimal View

- Displays the exact byte values stored in the file  
- Values range from `00` to `FF`  
- This column is the authoritative representation of the file’s contents  

### 3. ASCII View

- Provides a human-readable interpretation of the same bytes  
- Printable characters are displayed directly  
- Non-printable or control bytes are replaced with `.`  

This prevents terminal corruption and makes patterns visually detectable.

---

## Why 16 Bytes per Row

Sixteen bytes per row are used because:

- `16` aligns cleanly with hexadecimal addressing  
- It maps directly to common memory inspection tools  
- It balances readability with information density  

This layout is not arbitrary — it is a de facto standard.

---

## ⚙️ Implementation Logic (Conceptual)

The program operates as a **streaming binary inspector**, processing data incrementally rather than loading entire files into memory.

### 1. Binary-Safe File Access

The file is opened in binary mode to ensure:

- No newline translation  
- No encoding interference  
- Exact byte-for-byte fidelity  

Any deviation here invalidates the output.

---

### 2. Fixed-Size Buffering

- The file is read in **fixed chunks of 16 bytes**
- An **unsigned byte representation** is mandatory to avoid:
  - Sign extension
  - Incorrect hexadecimal output for values above `0x7F`

---

### 3. Incremental Read Loop

The file is read repeatedly until no more bytes are available:

- Full reads generate complete rows  
- Partial reads at end-of-file still generate output  

Every byte is shown. Nothing is skipped. Nothing is inferred.

---

### 4. Alignment & Padding Strategy

When the final chunk contains fewer than 16 bytes:

- Missing hexadecimal slots are padded with spaces  
- ASCII output is limited strictly to existing bytes  

This guarantees:

- Column alignment remains intact  
- Output stays visually scannable  
- No fabricated or misleading data appears  

---

### 5. ASCII Sanitization

Each byte is evaluated individually:

- Printable bytes are rendered as characters  
- Non-printable bytes are replaced with `.`  

This avoids undefined terminal behavior and matches professional debugging tools.

---

## 🧪 Expected Behavior

- Text files reveal readable strings alongside their hex values  
- Binary executables expose headers, instruction streams, and embedded strings  
- Image and archive files reveal magic numbers and structural metadata  
- Corrupted files expose malformed or unexpected byte patterns  

The tool **does not interpret file formats**.  
It shows what exists — not what it *means*.

---

## 🎯 Why This Project Matters

If you cannot read a hex dump comfortably, you do not truly understand:

- File formats  
- Memory layouts  
- Serialization  
- Binary protocols  
- Low-level debugging  

This project is not about writing C code.

It is about **seeing the machine’s truth without filters**.

That’s the difference between using systems  
and **understanding** them.

