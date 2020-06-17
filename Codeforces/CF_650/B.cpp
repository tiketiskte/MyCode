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

const int maxn = 40 + 5;
int t;
int n, a[maxn];
void solve() {
    int cnt1 = 0, cnt2 = 0;
    for(int i = 0; i < n; i++) {
        if(i % 2 == 0 && a[i] % 2 != 0) {
            cnt1++;
        } else if(i % 2 != 0 && a[i] % 2 == 0) {
            cnt2++;
        }
    }
    if(cnt1 == cnt2) {
        cout << cnt1 << endl;
    } else {
        cout << "-1" << endl;
    }
}
int main()
{
   IOS
   cin >> t;
   while(t--) {
       memset(a, 0, sizeof(a));
       cin >> n;
       for(int i = 0; i < n; i++) {
           cin >> a[i];
       }
       solve();
   }
   system("pause");
   return 0;
}
