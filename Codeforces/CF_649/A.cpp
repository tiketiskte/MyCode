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

const int maxn = 1e5 + 5;
int t, n, x;
int a;
void solve() {
   cin >> n >> x;
   ll sum = 0;
   int l = 0, r = 0;
   for(int i = 1; i <= n; i++) {
       cin >> a;
       sum += a;
       if(a % x) {
           if(l == 0) {
               l = i;
           }
           r = i;
       }
   }
   if(sum % x) {
       cout << n << endl;
   } else if(l == 0) {
       cout << "-1" << endl;
   } else {
       cout << n - min(l, n - r + 1) << endl; 
   }
}
int main()
{
   IOS
   cin >> t;
   while(t--) {
       solve();
   }
   system("pause");
   return 0;
}
