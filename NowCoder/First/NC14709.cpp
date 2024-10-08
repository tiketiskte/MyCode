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
int T, n;

void solve() {
    int ans = 1;
    for(int i = 1; i * i < n; i++) {
        if(n % i == 0) {
            ans++;
            n /= i;
        }
    }
    cout << ans << endl;
}
int main()
{
   IOS
   cin >> T;
   while(T--) {
       cin >> n;
       solve();
   }
   system("pause");
   return 0;
}
