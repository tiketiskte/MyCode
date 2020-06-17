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

const int maxn = 2e5 + 5;

int t, n, k;
int ans;
char s[maxn];
void solve() {
    cin >> n >> k;
    cin >> s;
    ans = 0;
    int l = 0, r = n - 1;
    for(;s[l] != '1' && l < n; l++);
    for(;s[r] != '1' && r >= 0; r--);
    //cout << l << " " << r << endl;
    if(l == n) {
        cout << (n + k) / (k + 1) << endl;
        return;
    }
    ans += l / (k + 1);
    ans += (n - r - 1) / (k + 1);
    int cnt = 0;
    for(int i = l; i <= r; i++) {
        if(s[i] == '1') {
            ans += (cnt - 2 * k + k) / (k + 1);
            cnt = 0;
        } else {
            cnt++;
        }
    }
    cout << ans << endl;
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
