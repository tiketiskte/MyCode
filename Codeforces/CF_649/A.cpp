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
int t;
int a[maxn];
void solve() {
    int n, x;
    int ans = 0, tmp;
    ll sum = 0, now = 0;
    cin >> n >> x;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    if(sum % x == 0) {
        tmp = n;
        now = sum;
        for(int i = 1; i <= n; i++) {
            now -= a[i];
            tmp--;
            if(now % x) {
                ans = max(ans, tmp);
                break;
            }
        }
        tmp = n;
        now = sum;
        for(int i = n; i >= 1; i--) {
            now -= a[i];
            tmp--;
            if(now % x) {
                ans = max(ans, tmp);
                break;
            }
        }
        if(ans == 0) {
            cout << "-1" << endl;
        } else {
            cout << ans << endl;
        }
    } else {
        cout << n << endl;
    }
}
int main()
{
   IOS
   cin >> t;
   while(t--) {
       solve();
   }
//    system("pause");
   return 0;
}
