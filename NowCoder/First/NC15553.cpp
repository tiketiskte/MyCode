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

const int maxn = 2e5 + 5;
ll T, n, k;
ll ans;
ll w[maxn], sum[maxn], a[maxn], b[maxn];
int main()
{
   IOS
   cin >> T;
   while(T--) {
       ans = -INF;
       for(int i = 1; i <= maxn; i++) {
           a[i] = -INF;
           b[i] = -INF;
       }
       cin >> n >> k;
       for(int i = 1; i <= n; i++) {
           cin >> w[i];
           sum[i] = sum[i - 1] + w[i]; 
       }
       for(int i = k; i <= n - k; i++) {
           a[i] = max(sum[i] - sum[i - k], a[i - 1]);
       }
       for(int i = n - k + 1; i >= k + 1; --i) {
           b[i] = max(sum[i + k - 1] - sum[i - 1], b[i + 1]);
       }
       for(int i = k; i <= n - k; i++) {
           ans = max(ans, a[i] + b[i + 1]);
       }
       cout << ans << endl;
   }
   //system("pause");
   return 0;
}
