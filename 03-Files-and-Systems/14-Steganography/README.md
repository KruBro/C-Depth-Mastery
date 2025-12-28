# Project: BMP Steganography Using LSB Encoding

## Goal

The goal of this project is to build a **low-level steganography tool** that hides and retrieves a secret text message inside a bitmap (`.bmp`) image **without visibly altering the image**.

The project focuses on understanding how:

- Binary file formats are structured
- Individual bits can be manipulated safely
- Data can be embedded into media files without corruption

This is not encryption.  
This is **data hiding at the byte and bit level**.

---

## What This Project Simulates

This project mimics real-world scenarios where:

- Files are not opaque blobs, but structured binary data
- Software must respect strict file layouts (headers vs payload)
- A single misplaced bit can corrupt an entire file

It is deliberately designed to force **systems-level thinking**, not library usage.

---

## Core Idea (High-Level)

Bitmap images store pixel data as raw bytes.  
Human vision cannot detect changes in the **least significant bit (LSB)** of a color value.

This project exploits that fact:

- Each character of a secret message is broken into **8 bits**
- Each bit is embedded into the **LSB of one image byte**
- The image remains visually unchanged
- The message can be reconstructed by reading those LSBs back

---

## Project Constraints

- Only **uncompressed 24-bit BMP images** are supported
- The BMP header **must remain untouched**
- The image must be large enough to store the message
- The message is terminated using a **null character (`'\0'`)**

Violating any of these corrupts the output or makes decoding impossible.

---

## Data Flow Overview

### Encoding (Hiding a Message)

1. Open the source BMP file in binary mode
2. Copy the BMP header exactly as-is
3. Convert the secret message into bits (8 bits per character)
4. For each bit:
   - Read one byte of image data
   - Clear its least significant bit
   - Insert the message bit into that position
5. Write modified bytes to a new BMP file
6. Copy remaining image data unchanged

Result:  
A new image that looks identical but secretly contains data.

---

### Decoding (Revealing a Message)

1. Open the encoded BMP file
2. Skip the header
3. Read image bytes one by one
4. Extract the least significant bit from each byte
5. Reconstruct characters from groups of 8 bits
6. Stop when the null terminator is reached

Result:  
The original hidden message is printed exactly as stored.

---

## Expected Output

### When Hiding a Message

[ENCRYPT] Hiding message: "Code is Poetry"
[SUCCESS] Message hidden in 'secret.bmp'.

- A new BMP file is created
- The image remains visually unchanged
- The message is now embedded in the file’s pixel data

---

### When Revealing a Message

[DECRYPT] Hidden Message: Code is Poetry


- The message is reconstructed correctly
- No extra characters
- No corruption

---

## Why This Project Matters

This project proves you understand:

- Binary file layouts
- Bitwise logic (`AND`, `OR`, shifts)
- Why padding, alignment, and headers matter
- How fragile low-level systems really are

If you get this wrong, **nothing works**.  
If you get it right, you’re thinking like a real systems engineer.

---

## Final Note

This is **entry-level steganography**, but **advanced C thinking**.

Anyone can print strings.  
Very few can hide them inside files **without breaking the file**.

That’s the point.
