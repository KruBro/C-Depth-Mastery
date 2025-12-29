/*
 * Project: Hex Dump Viewer
 * Author: Shahad K
 * 30 Dec 2025
 */
#include "hexvr.h"

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    viewHex(argv[1]);
    return 0;
}
