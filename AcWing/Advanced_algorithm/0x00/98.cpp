/**
* Copyright(c)
* Author : tiketiskte
**/
#include <bits/stdc++.h>
#define IOS {ios::sync_with_stdio(false);cin.tie(0);}
#define ll long long
#define PLL pair <ll, ll>
#define SZ(X) (int)X.size()
#define INF 0x3f3f3f3f

using namespace std;

int n, N;
ll A, B;
PLL calc(ll n, ll m) {
    if(n == 0) {
        return make_pair(0, 0);
    }
    ll len = (ll)1 << (n - 1);
    ll cnt = (ll)1 << (n * 2 - 2); //点的数量
    auto pos = calc(n - 1, m % cnt);
    auto x = pos.first;
    auto y = pos.second;
    auto z = m / cnt;
    if(z == 0) {
        return make_pair(y, x);   
    }
    if(z == 1) {
        return make_pair(x, y + len);
    }
    if(z == 2) {
        return  make_pair(x + len, y + len);
    }
    return make_pair(2 * len - 1 - y, len - x - 1);
}
int main()
{
   IOS
   cin >> n;
   while(n--) {
       cin >> N >> A >> B;
       auto dis_a = calc(N, A - 1);
       auto dis_b = calc(N, B - 1);
    //    cout << fixed << setprecision(2) <<  "dis_a.x:" << dis_a.first << " " << "dis_a.y:"<< dis_a.second << endl;
       double x = dis_a.first - dis_b.first;
       double y = dis_a.second - dis_b.second;
       double ans = sqrt(x * x + y * y) * 10.0;
       cout << fixed << setprecision(0) << ans << endl;
   }
   system("pause");
   return 0;
}
