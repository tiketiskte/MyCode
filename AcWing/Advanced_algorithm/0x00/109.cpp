/**
* Copyright(c)
* Author : tiketiskte
**/
#include <bits/stdc++.h>
#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long
#define PLL pair<ll, ll>
#define SZ(X) (int)X.size()
#define sqr(x) (x) * (x)
#define INF 0x3f3f3f3f

using namespace std;

const int maxn = 500000 + 5;
int k, n, m;
ll t, ans, rec[maxn], a[maxn], b[maxn];
ll check(int l, int mid, int r) {
    for(int i = mid; i < r; i++) {
        a[i] = rec[i];
    }
    sort(a + mid, a + r);
    int i = l, j = mid, cnt = 0;
    while(i != mid && j != r) {
        if(a[i] < a[j]) {
            b[cnt++] = a[i++];
        } else {
            b[cnt++] = a[j++];
        }
    }
    while(i != mid) {
        b[cnt++] = a[i++];
    }
    while(j != r) {
        b[cnt++] = a[j++];
    }
    ll SPD = 0;
    for(int i = 0; i < m && i < cnt; i++, cnt--) {
        SPD += sqr(b[i] - b[cnt - 1]);
    }
    return SPD;
}
void solve() {
    int start = 0, end = 0;
    while(end < n) {
        int len = 1;
        while(len) {
            if(end + len <= n && check(start, end, end + len) <= t) {
                end += len;
                len <<= 1;
                if(end >= n) {
                    break;
                }
                for(int i = start; i < end; i++) {
                    a[i] = b[i - start];
                }
            } else {
                len >>= 1;
            }
        }
        start = end;
        ans++;
    }
}
int main(void)
{
    IOS
    cin >> k;
    while(k--) {
        ans = 0;
        memset(rec, 0, sizeof(rec));
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        cin >> n >> m >> t;
        for(int i = 0; i < n; i++) {
            cin >> rec[i];
        }
        solve();
        cout << ans << endl;
    }
    system("pause");
    return 0;
}
