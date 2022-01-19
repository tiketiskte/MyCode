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
void show_short(short x) {
    show_bytes((byte_pointer) &x, sizeof(short));
}
void show_long(long x) {
    show_bytes((byte_pointer) &x, sizeof(long));
}
void show_double(double x) {
    show_bytes((byte_pointer) &x, sizeof(double));
}

void test_show_bytes(int val) {
    int ival = val;
    float fval = (float)val;
    int *pval = &ival;
    short sval = (short)val;
    long lval = (long)val;
    double dval = (double)val;
    show_int(val);
    show_float(fval);
    show_pointer(pval);
    show_short(sval);
    show_long(lval);
    show_double(dval);
}
int main(void) {
    int x1 = 12345;
    //Hex:0x003039
    ///int x2 = 1024;
    //Hex:0x000400
    printf("x1:\n");
    test_show_bytes(x1);
    //printf("x2:\n");
    //test_show_bytes(x2);
    // system("pause");
    return 0;
}

/*
*/