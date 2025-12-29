/*
 * Project: Run Length Encoding
 * Author: Shahad K
 * 26 Dec 2025
 */
#include "compressor.h"

int main()
{
    long size;
    char str[50];
    printf("Enter the file name to compress: ");
    scanf("%s", str);
    printf("File To Compress is %s\n", str);
    size = getFileSize(str);
    printf("%s file size before compression is %ld\n", str, size);
    viewHexDump(str);
    char filename[50] = "compressed.rle";
    compressFile(str,filename);
    size = getFileSize(filename);
    printf("File Size After Compression is %ld\n", size);
    viewHexDump(filename);
    decompressFile(filename, "test2.txt");
    size = getFileSize("test2.txt");
    printf("File Size After decompression is %ld\n", size);
    viewHexDump("test2.txt");

    return 0;


}
