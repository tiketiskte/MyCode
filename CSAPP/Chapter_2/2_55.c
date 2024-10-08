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
        printf("%p\t0x%.2x\n", start + i, start[i]);
    }
    printf("\n");
}

void show_int(int x) {
    show_bytes((byte_pointer) &x, sizeof(int));
}
void show_float(float x) {
    show_bytes((byte_pointer) &x, sizeof(float));
}
void show_pointer(void *x) {
    show_bytes((byte_pointer) &x, sizeof(void *));
}

void test_show_bytes(int val) {
    int ival = val;
    float fval = (float)val;
    int *pval = &ival;
    show_int(val);
    show_float(fval);
    show_pointer(pval);
}
int main(void) {
    int x = 12345;
    test_show_bytes(x);
    system("pause");
    return 0;
}

/*
结论:在Windows11电脑上 采用gcc编译 得到该电脑属于小端序电脑
并且对于每一个类型查看其字节序列表示时 point地址不发生改变(类似覆盖？) [也可能发生改变 如占用字节数发生改变时]
*/