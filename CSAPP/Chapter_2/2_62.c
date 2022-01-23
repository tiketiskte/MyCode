/**
* Copyright(c)
* Author : tiketiskte
**/
#include <stdio.h>
#include <stdlib.h>
typedef unsigned char *byte_pointer;
void show_bytes(byte_pointer start, size_t len) {
    size_t i;
    for(i = 0; i < len; i++) {
        printf(" %.2x", start[i]);
    }
    printf("\n");
}
int int_shifts_are_arithmetic() {
    int int_size = (sizeof(int) << 3) - 1;
    int xright = -1 >> int_size;
    show_bytes((byte_pointer) &xright, sizeof(int));
}
int main(void) {
    int_shifts_are_arithmetic();
    return 0;
}
