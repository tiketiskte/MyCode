/**
* Copyright(c)
* Author : tiketiskte
*/
#include <bits/stdc++.h>
#define IOS {ios::sync_with_stdio(false);cin.tie(0);}
#define ll long long
#define INF 0x3f3f3f3f

using namespace std;
const int maxn = 2e5 + 6;
int t, n;
ll a[maxn];
int main()
{
   IOS
   cin >> t;
   while(t--) {
       memset(a, 0, sizeof(a));
       ll ans = 0;
       cin >> n;
       for(int i = 1; i <= n; i++) {
           cin >> a[i];
       }
       for(int i = 1; i <= n; i++) {
           int j = i;
           ll now = a[i];
           while(j + 1 <= n && ((a[i] > 0 && a[j + 1] > 0) || (a[i] < 0 && a[j + 1] < 0))) {
               j++;
               now = max(now, a[j]);
           }
           i = j;
           ans += now;
       }
       cout << ans << endl;
   }
//    system("pause");
   return 0;
}
