#include<stdio.h>
#include <stdlib.h>
int main(void)
{
    int n,x,y;
    scanf("%d %d %d",&n,&x,&y);
    double a = 0;
    a = n - y / x;
    if(a > 0) {
        printf("%.0lf\n",a);
    } else {
        printf("0\n");
    }
    system("pause");
    return 0;
}
