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
  
const int maxn = 2e5 + 5;
int T, n, k;
int a[maxn];
ll sum[maxn];
ll l[maxn], r[maxn];
ll ans;
int main()
{
   IOS
   cin >> T;
   while(T--) {
       cin >> n >> k;
       ans = -1e18;
       //要开1e18 不然83%样例 不能-INF
       //memset(a, 0, sizeof(a));
       //memset(sum, 0, sizeof(sum));
       memset(l, -INF, sizeof(l));
       memset(r, -INF, sizeof(r));
       /* for(int i = 1; i <= maxn; i++) {
           l[i] = r[i] = -INF;//玄学问题
       }  */
       for(int i = 1; i <= n; i++) {
           cin >> a[i];
           sum[i] = sum[i - 1] + a[i];
       }
       for(int i = k; i <= n - k; i++) {
           l[i] = max(l[i - 1], sum[i] - sum[i - k]);
       }
       for(int i = n - k + 1; i >= k + 1; i--) {
           r[i] = max(r[i + 1], sum[i + k - 1] - sum[i - 1]);
       }
       for(int i = k; i <= n - k; i++) {
           ans = max(ans, l[i] + r[i + 1]);
       }
       cout << ans << endl;
   }
   system("pause");
   return 0;
}