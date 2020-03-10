/**
* Copyright(c)
* Author : tiketiskte
*/
#include <bits/stdc++.h>
#define IOS {ios::sync_with_stdio(false);cin.tie(0);}

using namespace std;

int n, row;
char ch;
int main()
{
   IOS
   scanf("%d %c", &n, &ch);
   for(int i = 0; i < n; i++)
   {
       if((2 * i * (i + 2) + 1) > n)
       {
           row = i - 1;
           break;
       } 
   } 
   //cout << row << endl;
   for(int i = row; i >= 1; i--)
   {
       for(int j = row - i; j >= 1; j--)
       {
           printf(" ");
       }
       for(int k = i * 2 + 1; k >= 1; k--)
       {
           printf("%c", ch);
       }
       printf("\n");
   }
   for(int i = 1; i <= row; i++)
   {
       printf(" ");
   }
   printf("%c\n", ch);
   for(int i = 1; i <= row; i++)
   {
       for(int j = row - i; j >= 1; j--)
       {
           printf(" ");
       }
       for(int k = i * 2 + 1; k >= 1; k--)
       {
           printf("%c", ch);
       }
       printf("\n");
   }
   int x = 2 * row * (row + 2) + 1;
   printf("%d\n", n - x);
   //system("pause");
   return 0;
}
