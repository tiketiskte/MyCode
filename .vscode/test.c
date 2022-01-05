#include<stdio.h>
#include<math.h>
#include<time.h>
clock_t start1, stop1, start2, stop2;
const int MAXN = 1e7;
void f1(int *a, int *b) {
    *b = *a ^ *b;
    *a = *a ^ *b;
    *b = *a ^ *b;
}
void f2(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
int main(void) {
    int x = 100, y = 101;
    start1 = clock();
    for(int i = 0; i < MAXN; i++) {
        f1(&x, &y);
    }
    stop1 = clock();
    double duration1 = (double)(stop1 - start1) / CLK_TCK;
    printf("%f\n", (double)(stop1 - start1));
    printf("%f\n", duration1);
    start2 = clock();
    for(int i = 0; i < MAXN; i++) {
        f2(&x, &y);
    }
    stop2 = clock();
    double duration2 = (double)(stop2 - start2) / CLK_TCK;
    printf("%f\n", (double)(stop2 - start2));
    printf("%f\n", duration2);
    system("pause");
}
