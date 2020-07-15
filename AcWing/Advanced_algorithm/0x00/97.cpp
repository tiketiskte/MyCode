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

const int mod = 9901;
ll quick_power(ll a, ll b) {
    ll res = 1 % mod;
    cout << "###" << a << endl;
    while(b) {
        if(b & 1) {
            res = res * a % mod;
        }
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
ll sum(int p, int k) {
    if(k == 0) {
        return 1;
    }
    if(k % 2 == 0) {
        return (quick_power(p, k) + sum(p, k - 1)) % mod;
        // return (1 + quick_power(p, k / 2)) % mod * sum(p, k / 2 - 1) % mod + quick_power(p, k) % mod;
    }
    return (1 + quick_power(p, k / 2 + 1)) % mod * sum(p, k / 2) % mod;
}
int main()
{
   IOS
   int A, B;
   cin >> A >> B;
   int ans = 1;
   for(int i = 2; i <= A; i++) {
       int cnt = 0;
       while(A % i == 0) {
           cnt++;
           A /= i;
       }
       if(cnt) {
           ans = ans * sum(i, cnt * B) % mod;
       }
   }
   if(!A) {
       cout << 0 << endl;
   } else {
       cout << ans << endl;
   }
   system("pause");
   return 0;
}