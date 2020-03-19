/**
* Copyright(c)
* Author : tiketiskte
*/
#include <bits/stdc++.h>
#define IOS {ios::sync_with_stdio(false);cin.tie(0);}
#define INF 0x3f3f3f3f

const int maxn = 1e5 + 5;
using namespace std;
int N, p;
int a[maxn];
int main()
{
   IOS
   cin >> N >> p;
   for(int i = 1; i <= N; i++) {
       cin >> a[i];
   }
   sort(a + 1, a + 1 + N);
   int ans = 0, temp = 0;
   for(int i = 1; i <= N; i++) {
       for(int j = i +  ans; j <= N; j++) {
           if(a[j] < a[i] * p) {
               temp = j - i + 1;
               if(temp > ans) {
                   ans = temp;
               }
           }
           else
           {
               break;
           }
           
       }
   }
   cout << ans << endl;
   system("pause");
   return 0;
}
