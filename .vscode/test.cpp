/**
* Copyright(c)
* Author : tiketiskte
*/
#include <stdio.h>
#include <stdlib.h>
//#define IOS {ios::sync_with_stdio(false);cin.tie(0);}

//using namespace std;
void f(int arr[], int n)
{
    int i, j;
    for(i = 1; i <= n; i++)
    {
        int temp = arr[i];
        for(j = i; arr[j - 1] > temp; j-- )
        {
            arr[j] = arr[j - 1];
        }
        arr[j] = temp;
    }
}
int main()
{
   int n, a[100];
   printf("please input n:\n");
   scanf("%d", &n);
   for(int i = 1; i <= n; i++)
   {
       scanf("%d", &a[i]);
   }
   f(a, n);
   for(int i = 1; i <= n; i++)
   {
       printf("%d", a[i]);
   }
   system("pause");
   return 0;
}