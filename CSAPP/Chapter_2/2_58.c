/**
* Copyright(c)
* Author : tiketiskte
**/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef unsigned char *byte_pointer;
void show_bytes(byte_pointer start, size_t len) {
    size_t i;
    for(i = 0; i < len; i++) {
        printf("%p\t0x%.2x\n", start + i, start[i]);
    }
    printf("\n");
}
int is_little_endian() {
    int test = 0xff;
    //Hex: 0x000000ff
    byte_pointer byte_start = (byte_pointer) &test;
    // show_bytes(byte_start, sizeof(int));
    if(byte_start[0] == 0xff) {
        return 1;
        // 小端序机器排列应该为ff 00 00 00 并返回1 
    } else {
        return 0;
        // 大端序机器排列应该为00 00 00 ff 并返回0
    }
}
int main(void) {
    assert(is_little_endian);
    // is_little_endian();
    // system("pause");
    return 0;
}
