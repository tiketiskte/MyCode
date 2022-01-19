/**
* Copyright(c)
* Author : tiketiskte
**/
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    unsigned w = 11;
    int tw = 11;
    // printf("%d\n", w << 1);
    printf("%u %u %d %d\n", w * 14, (w << 3) + (w << 2) + (w << 1), tw * 14, (tw << 3) + (tw << 2) + (tw << 1));
    system("pause");
    return 0;
}
