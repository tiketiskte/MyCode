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

const int N = 1e5 + 5;
ll n, m;
pair <string, ll>pr[N];
int calculate(int bit, int tmp) {
    for(int i = 0; i < n; i++) {
        int x = pr[i].second >> bit & 1;
        if(pr[i].first[0] == 'O') {
            tmp |= x;
        } else if(pr[i].first[0] == 'X') {
            tmp ^= x;
        } else {
            tmp &= x;
        }
    }
    return tmp;
}
int main()
{
   IOS
   cin >> n >> m;
   for(int i = 0; i < n; i++) {
       cin >> pr[i].first >> pr[i].second;
   }
   ll ans = 0, v = 0;
   for(int i = 29; ~i; i--){
       int x1 = calculate(i, 0);
       int x2 = calculate(i, 1);
       if(v + (1 << i) <= m && x2 > x1) {
           v +=(1 << i);
           ans += x2 << i;
       } else {
           ans += x1 << i;
       }
   }
   cout << ans << endl;
   system("pause");
   return 0;
}