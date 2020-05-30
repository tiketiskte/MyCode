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
int main()
{
   IOS
   cin >> T;
   while(T--) {
       for(int i = 1; i <= maxn; i++) {
           a[i] = sum[i] = 0;
       }
       cin >> n >> k;
       for(int i = 1; i <= n; i++) {
           cin >> a[i];
           sum[i] = sum[i - 1] + a[i];
       }
       ll m1 = -1e18, ans = -1e18;
       for(int i = k; i + k <= n; i++) {
           m1 = max(m1, sum[i] - sum[i - k]);
           ans = max(ans, m1 + sum[i + k] - sum[i]);
       }
       cout << ans << endl;
   }
   system("pause");
   return 0;
}
