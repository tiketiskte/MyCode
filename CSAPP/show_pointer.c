#include <stdio.h>
#include<string.h>
#include <stdlib.h>
typedef unsigned char *byte_pointer;
void show_bytes(byte_pointer start, size_t len) {
    size_t i;
    for(i = 0; i < len; i++) {
        printf(" %.2x", start[i]);
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
    // 12345 hex:0x00003039
    test_show_bytes(x);
    const char *s = "abcdef";
    show_bytes((byte_pointer) s, strlen(s));
    printf("%d\n",(int)strlen(s));
    printf("The different between two's complement and show_integer:\n");
    short lx= 12345;
    short int mx = -lx;
    show_bytes((byte_pointer) &lx, sizeof(short));
    show_bytes((byte_pointer) &mx, sizeof(short));
    system("pause");
}
/*
This code shows that the same code runs on different platforms to produce different results
*/