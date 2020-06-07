/**
* Copyright(c)
* Author : tiketiskte
**/
#include <bits/stdc++.h>
#define IOS {ios::sync_with_stdio(false);cin.tie(0);}
#define ll long long
#define SZ(X) (int)X.size()
#define INF 0x3f3f3f3f
 
using namespace std;
 
const int maxn = 5e6 + 5;
struct node {
   int id;
   int value;
}sweet[maxn];
int T;
int n, m;
int c[maxn], d[maxn];
int main()
{
   IOS
   cin >> T;
   while(T--) {
      memset(d, 0, sizeof(d));
      cin >> n >> m;
      for(int i = 1; i <= n; i++) {
         cin >> sweet[i].id >> sweet[i].value;
      }
      for(int i = 1; i <= m; i++) {
         cin >> c[i];
         d[1]++;
         d[c[i] + 1]--;
      }
      ll sum = 0;
      for(int i = 1; i <= n; i++) {
         sum += d[i];
         sweet[i].value += sum;
         /* d[i] = d[i - 1] + d[i];
         sweet[i].value += d[i]; */
      }
      ll max1 = -INF, max2 = -INF;//强制类型转换
      ll ans = 0;
      for(int i = n; i > 0; i--) {
         if(sweet[i].id) {
            max1 = max(max1, (ll)sweet[i].value);
            if(sweet[i].value >= max2) {
               ans++;
            }
         } else {
            max2 = max(max2, (ll)sweet[i].value);
            if(sweet[i].value >= max1) {
               ans++;
            }
         }
      }
      cout << ans << endl;
   }
   system("pause");
   return 0;
}