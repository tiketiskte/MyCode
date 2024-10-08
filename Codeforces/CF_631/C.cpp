/**
* Copyright(c)
* Author : tiketiskte
*/
#include <bits/stdc++.h>
#define IOS {ios::sync_with_stdio(false);cin.tie(0);}
#define ll long long
#define INF 0x3f3f3f3f

using namespace std;
const int maxn = 100000 + 5;
int n, m, pos;
ll sum;//注意爆数据范围！！！
int a[maxn], ans[maxn];
bool flag;
int main()
{
   IOS
   cin >> n >> m;
   for(int i = 1; i <= m; i++) {
      cin >> a[i];
      sum += a[i];
   }
   if(sum < n) {
      cout << "-1" << endl;
      return 0;
   }
   pos = 1;
   sum -= n;
   flag = false;
   for(int i = 1; i <= m; i++) {
      if(a[i] + pos - 1 > n) {
         flag = 1;
         break;
      }
      if(sum >= a[i]) {
         sum -= a[i] - 1;
         a[i] = 1;
      } else {
         a[i] -= sum;
         sum = 0;
      }
      ans[i] = pos;
      pos += a[i];
   }
   if(flag) {
      cout << "-1" << endl;
   } else {
      for(int i = 1; i < m; i++) {
         cout << ans[i] << " ";
      }
      cout << ans[m] << endl;
   }
   //system("pause");
   return 0;
}
