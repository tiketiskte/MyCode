/**
* Copyright(c)
* Author : tiketiskte
*/
#include <bits/stdc++.h>
#define IOS {ios::sync_with_stdio(false);cin.tie(0);}
#define ll long long
#define INF 0x3f3f3f3f

using namespace std;
const int maxn = 2e5 + 5;
int t, n;
ll a[maxn];
int sgn(int x) {
    if(x > 0)
        return 1;
    else
        return -1;
}
int main()
{
   IOS
   cin >> t;
   while(t--) {
       cin >> n;
       for(int i = 1; i <= n; i++) {
           cin >> a[i];
       }
       ll ans = 0;
       for(int i = 1; i <= n; i++) {
           ll now = a[i];
           int j = i;
           while(j <= n && sgn(a[i]) == sgn(a[j])) {
               now = max(now, a[j]);
               j++;
           }
           i  = j - 1;
           ans += now;
       }
       cout << ans << endl;
   }
   system("pause");
   return 0;
}
