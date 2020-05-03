/**
* Copyright(c)
* Author : tiketiskte
*/
#include <bits/stdc++.h>
#define IOS {ios::sync_with_stdio(false);cin.tie(0);}
#define ll long long
#define INF 0x3f3f3f3f

using namespace std;
const int maxn = 100 + 5;
int n, a[maxn];
 int cnt = 0;
void quicksort(int a[], int p, int r) {
    if(p < r) {
        cnt++;
        cout << cnt << endl;
        //cout << "!!!" << endl;
        int i = p;
        int j = r;
        int ans = a[p];
        while(i < j) {
            while(i < j && a[j] >= ans) {
                j--;
            }
            if(i < j) {
                a[i] = a[j];
            }
            while(i < j && a[i] < ans) {
                i++;
            }
            if(i < j) {
                a[j] = a[i];
            }
        }
        a[i] = ans;
        quicksort(a, p, i - 1);
        quicksort(a, i + 1, r); 
    }
} 
int main()
{
   IOS
   int a[12]={13, 19, 9, 5, 12, 8, 7, 4, 11, 2, 6, 14};
   quicksort(a, 0, 11);
   //cout << "xxx" << endl;
   for(int i = 0; i < 12; i++) {
       printf("%d ", a[i]);
   }
   cout << endl;
   system("pause");
   return 0;
}