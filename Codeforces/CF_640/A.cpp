/**
* Copyright(c)
* Author : tiketiskte
*/
#include <bits/stdc++.h>
#define IOS {ios::sync_with_stdio(false);cin.tie(0);}
#define ll long long
#define SZ(X) (int)X.size()
#define INF 0x3f3f3f3f

using namespace std;

int t, n, cnt;
int a[6];//保存答案
int main()
{
   IOS
   cin >> t;
   while(t--) {
      cnt = 0;
      int d = 1;
      cin >> n;
      while(n) {
         if(n % 10) {
            a[cnt++] = n % 10 * d;
         }
         d *= 10;
         n /= 10;
      }
      cout << cnt << endl;
      for(int i = 0; i < cnt; i++) {
         cout << a[i] << " ";
      }
      cout << endl;
      /* while(n) {
         cout << "###" << n % 10 << endl;
         cout << "$$$" << n / 10 << endl;
         n /= 10;
         cout << "The answer about n:" << n << endl;
      } */ 
   }
   system("pause");
   return 0;
}
