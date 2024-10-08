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
    return xright == -1;
    //若为算术右移，则xright应为1111 .... 1111的串，因此为-1
    //若为逻辑右移，则xright应为0000 .... 0001的串，应为1
    //判断一下是否为-1即可
}
int main(void) {
    int ans = int_shifts_are_arithmetic();
    printf("%d\n", ans);
    return 0;
}
