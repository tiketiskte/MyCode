//practice 2.36
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
int tmult_ok(int x, int y) {
    int64_t ans = (int64_t) x * y;
    return ans == (int)ans; 
}
int main(void) {
    int test1 = tmult_ok(pow(2, 31) - 1, pow(2, 31) - 1);
    int test2 = tmult_ok(2, pow(2, 30) - 1);
    printf("%d %d\n", test1, test2);
    system("pause");
    return 0;
}