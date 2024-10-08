/**
* Copyright(c)
* Author : tiketiskte
**/
#include <bits/stdc++.h>
#define IOS {ios::sync_with_stdio(false);cin.tie(0);}
#define ll long long
#define PLL pair<ll, ll>
#define SZ(X) (int)X.size()
#define INF 0x3f3f3f3f

using namespace std;

const int maxn = 1e5 + 5;
int n, a[maxn], b[maxn]; // b 差分数组
int sum[maxn];
int main()
{
   IOS
   cin >> n;
   for(int i = 1; i <= n; i++) {
       cin >> a[i];
   }
   b[1] = a[1];
   for(int i = 2; i <= n; i++) {
       b[i] = a[i] - a[i - 1];
   }
   /* int c = 10;// [3, 7] += c c = 10
   b[3] += c, b[8] -= c;
   sum[1] = b[1];
   for(int i = 2; i <= n; i++) {
       sum[i] = sum[i - 1] + b[i];
   }
   for(int i = 1; i <= n; i++) {
       cout << sum[i] << " ";
   } */ 
   ll pos = 0, neg = 0;
   for(int i = 2; i <= n; i++) {
       if(b[i] > 0) {
           pos += b[i];
       } else {
           neg -= b[i];
       }
   }
   ll ans = min(pos, neg) + abs(pos - neg);
   cout << ans << endl << abs(pos - neg) + 1 << endl;
   system("pause");
   return 0;
}