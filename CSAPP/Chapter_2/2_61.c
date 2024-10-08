/**
* Copyright(c)
* Author : tiketiskte
**/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
int A(int x) {
    return !~x;
    //对于全1的x 取反后全为0 再!判一下即为1 对于不全1的x 取反后不等于0 再!判一下即为0 符合要求
}
int B(int x) {
    return !x;
    //对于全为0的x !判一下即为1 对于不全为0的x !判一下即为0
}
int C(int x) {
    return A(x | ~0xff);
    //承接A选项的整体 判断x的最低有效字节位
    //对于x的最低有效字节如果全为1 x | ~0xff得到的是0x1111[前面字节个数不定]11 既全为1 从而回到了A的情况
    //对于x的最低有效字节如果全为0 x | ~0xff得到的是0x1111[前面字节个数不定]00 即不全为1 也是A的情况
    //从而判断最低有效字节位
}
int D(int x) {
    return B((x >> (sizeof(int) - 1) << 3) & 0xff);
    //承接A选项的整体 判断x的最高有效字节位
    //问题关键在于 构造出x的最高有效字节位
    //采用技巧: x >> (sizeof(int) - 1) << 3 即可得到x的最高有效字节位[但放在最低有效字节位] 其余高位均为0
    //然后我们 & 0xff 即可得到对应的0x0000[最高有效字节位] 从而转变成B情况的判断[最高有效字节位全为0/不全为0]
}
int main(void) {
    int all_bit_one = ~0;
    int all_bit_zero = 0;
    assert(A(all_bit_one) == 1);
    assert(!A(all_bit_one) == 1); //assert断言
    assert(B(all_bit_zero) == 1);
    assert(!B(all_bit_zero) == 1); //assert断言
    assert(C(0x1234) == 0);
    assert(!C(0x1234) == 0); //assert断言
    assert(C(0x1234ff) == 1);
    assert(!C(0x1234ff) == 1); //assert断言
    return 0;
}
