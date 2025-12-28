#ifndef BITMAP_H
#define BITMAP_H

#include <stdint.h> // For uint16_t, uint32_t

// Force 1-byte alignment so the struct matches the file exactly
#pragma pack(push, 1) 
typedef struct {
    uint16_t bfType;      // Magic Number "BM"
    uint32_t bfSize;      // File size
    uint16_t bfReserved1;
    uint16_t bfReserved2;
    uint32_t bfOffBits;   // Offset to image data (usually 54)
    
    uint32_t biSize;      // Header size (40)
    int32_t  biWidth;
    int32_t  biHeight;
    uint16_t biPlanes;
    uint16_t biBitCount;  // 24 for RGB
    uint32_t biCompression;
    uint32_t biSizeImage;
    int32_t  biXPelsPerMeter;
    int32_t  biYPelsPerMeter;
    uint32_t biClrUsed;
    uint32_t biClrImportant;
} BMPHeader;
#pragma pack(pop)

// Function Prototypes
void hideMessage(const char *sourceFile, const char *destFile, const char *secret);
void revealMessage(const char *sourceFile);

#endif