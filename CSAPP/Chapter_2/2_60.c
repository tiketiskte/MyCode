/**
* Copyright(c)
* Author : tiketiskte
**/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef unsigned char *type_pointer;
void show_bytes(type_pointer start, size_t len) {
    size_t i;
    for(i = 0; i < len; i++) {
        printf("0x%.2x\n", start[i]);
        // printf("%p\t0x%.2x\n", start + i, start[i]);
    }
    printf("\n");
}
unsigned replace_byte(unsigned x, int i, unsigned char b) {
    int move = i << 3;
    unsigned mask = (unsigned)0xff << move;
    unsigned pos_byte = (unsigned)b << move;
    return x & (~mask) | pos_byte;
    //根据移动规则,先计算出移动1B 相当于移动8Bit 即move = i << 3(i * 2^3) 
    //然后通过性质:A & 0Xff 保留A的最低有效位两位 掩盖其他位
    //我们的目的是构造0x12005678，即掩盖2位 保留其他位 通常操作是：A & ~0xff [在此之前，先将0xff的两个最低有效位移位到掩盖位置]
    //下面计算一下需要补位的字节位置 即pos_byte = 补位 << move
}
int main(void) {
    unsigned A = 0x12345678;
    unsigned ans1 = replace_byte(A, 2, 0xAB);
    unsigned ans2 = replace_byte(A, 0, 0xAB);
    show_bytes((type_pointer) &ans1, sizeof(unsigned));
    show_bytes((type_pointer) &ans2, sizeof(unsigned));
    assert(ans1 == 0x12AB5678);
    assert(ans2 == 0x123456AB);
    return 0;
}
