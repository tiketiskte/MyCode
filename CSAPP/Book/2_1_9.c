#include <stdio.h>
#include <stdlib.h>
int main(void) {
    /*int x1 = 149;
    unsigned int x2 = 149;
    printf("%d\n", x1 >> 4);
    printf("%d\n", x2 >> 4);
    int lval = 0xFEDCBA98 << 32;
    int aval = 0xFEDCBA98 >> 36;
    unsigned uval = 0xFEDCBA98u >> 40;
    printf("lval:%x\n", lval);
    printf("aval:%x\n", aval);
    printf("uval:%x\n", uval);*/
    int ans1 = 1 << 2 + 3 << 4;
    int ans2 = (1 << 2) + (3 << 4);
    int ans3 = (1 << (2 + 3)) << 4;
    printf("%d %d %d\n", ans1, ans2, ans3);
    system("pause");  
    return 0;
}