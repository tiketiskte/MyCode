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

ll a, b, p;
void solve() {
    ll ans = 1 % p;//可能进不去while循环情况要特判%1情况
    while(b) {
        if(b & 1) {
            ans = ans * a % p; 
        }
        a = a * a % p;
        b >>= 1;
    }
    cout << ans << endl;
}
int main()
{
   IOS
   cin >> a >> b >> p;
   solve();
   system("pause");
   return 0;
}
