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

const int maxn = 1000 + 5;
int t, n;
int main()
{
   IOS
   cin >> t;
   while(t--) {
       int cnt = 1;
       int ans = 1;
       cin >> n;
       while(cnt <= n) {
           cout << ans << " ";
           cnt += 1; 
           ans += 2;
       }
       cout << endl;
   }
   system("pause");
   return 0;
}
