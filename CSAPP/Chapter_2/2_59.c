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
size_t function(size_t a, size_t b) {
    return (a & 0xff) | (b & ~0xff);
    //注意到，对于我们想要利用位运算来构成0x765432EF,因此我们采用0x89ABCDEF & 0xff 屏蔽掉前6位 即得到0x000000EF
    //同时我们既然想将0x000000EF 变成 0x765432EF 应该采用 0x000000EF | 0x76543200
    //于是工作变为通过0x76543210 构造 0x76543200 我们采用0x76543210 & 0x1111111100  即0x76543210 & ~0xff[~0x (xx)[任意数 只要不是0x00即可]]
    //因此表达式为 (a & 0xff) | (b & ~0xff)
}
int main(void) {
    size_t x = 0x89ABCDEF;
    size_t y = 0x76543210;
    size_t ans = function(x, y);
    show_bytes((byte_pointer) &ans, sizeof(size_t));
    assert(ans = 0x765432EF);
    return 0;
}
