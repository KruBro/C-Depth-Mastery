#include <stdio.h>
#include <string.h>
#include "bitmap.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage:\n");
        printf("  %s hide <source.bmp> <dest.bmp> <\"secret\">\n", argv[0]);
        printf("  %s reveal <source.bmp>\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "hide") == 0) {
        if (argc != 5) {
            printf("Error: Missing arguments for 'hide'.\n");
            return 1;
        }
        // argv[2]=source, argv[3]=dest, argv[4]=message
        hideMessage(argv[2], argv[3], argv[4]);

    } else if (strcmp(argv[1], "reveal") == 0) {
        if (argc != 3) {
            printf("Error: Missing arguments for 'reveal'.\n");
            return 1;
        }
        // argv[2]=source
        revealMessage(argv[2]);

    } else {
        printf("Unknown command: %s\n", argv[1]);
    }

    return 0;
}