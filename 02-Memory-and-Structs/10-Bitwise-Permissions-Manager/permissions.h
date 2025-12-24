#ifndef PERMISSIONS_H 
#define PERMISSIONS_H

#include <stdio.h>
#include <stdint.h>

#define PERM_READ  0x01     // 0000 0001
#define PERM_WRITE 0x02     // 0000 0010
#define PERM_EXEC  0x04     // 0000 0100
#define PERM_ADMIN 0x08     // 0000 1000

void printStatusBits(uint8_t *user);
void addPermission(uint8_t *user);
void removePermission(uint8_t *user);
void checkPermission(uint8_t user);
void togglingPermission(uint8_t *user);

#endif