#ifndef COMPRESSOR_H
#define COMPRESSOR_H
#include <stdio.h>
#include <ctype.h>
#include <string.h>

long getFileSize(const char *filename);
void compressFile(const char *inputFile, const char *outputFile);
void decompressFile(const char *inputFile, const char *outputFile);
void viewHexDump(const char *filename);

#endif