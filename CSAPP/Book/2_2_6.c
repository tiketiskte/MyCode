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
int main(void) {
    short sx = -12345; //12345
    unsigned short usx = sx; //53191
    int x = sx; //12345
    unsigned ux = usx; //53191

    printf("size: %d %d %d %d\n", (int)sizeof(short), (int)sizeof(unsigned short), (int)sizeof(int), (int)sizeof(unsigned));
    //size: 2 2 4 4
    printf("sx = %d:\t", sx);
    show_bytes((byte_pointer) &sx, sizeof(short));
    printf("usx = %u:\t", usx);
    show_bytes((byte_pointer) &usx, sizeof(unsigned short));
    printf("x = %d:\t", x);
    show_bytes((byte_pointer) &x, sizeof(int));
    printf("ux = %u:\t", ux);
    show_bytes((byte_pointer) &ux, sizeof(unsigned));
    system("pause");
    return 0;
}