/**
* Copyright(c)
* Author : tiketiskte
**/
#include <bits/stdc++.h>
#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long
#define PLL pair<ll, ll>
#define SZ(X) (int)X.size()
#define INF 0x3f3f3f3f
#define sqr(a) (a) * (a)

using namespace std;

const int maxn = 5e5 + 5;
int k, n, m;
ll t, ans;
ll rec[maxn], a[maxn], b[maxn]; // 原序列 排序后序列 
void merge(int l, int mid, int r) {
    int p1 = l, p2 = mid + 1;
    for(int i = l; i <= r; i++) {
        if((p2 > r) || (p1 <= mid && a[p1] <= a[p2])) {
            b[i] = a[p1++];
        } else {
            b[i] = a[p2++];
        }
    }
}
bool check(int l, int mid, int r) {
    for(int i = mid; i <= r; i++) {
        a[i] = rec[i];
    }
    sort(a + mid, a + r + 1);
    merge(l, mid - 1, r);
    ll sum = 0;
    for(int i = 1; i <= ((r - l + 1) >> 1) && i <= m; i++) {
        sum += sqr(b[r - i + 1] - b[l + i - 1]);
    }
    if(sum <= t) {
        for(int i = l; i <= r; i++) {
            a[i] = b[i];
        }
        return true; 
    } else {
        return false;
    }
}
void work() {
    int p = 1, l = 1, r = 1;
    a[l] = rec[l];
    while(r <= n) {
        if(!p) {
            ans++;
            l = ++r;
            a[l] = rec[l];
            p = 1;
        } else if(r + p <= n && check(l, r + 1, r + p)) {
            r = r + p;
            p <<= 1;
        } else {
            p >>= 1;
        }
    }
}
int main(void)
{
    IOS
    cin >> k;
    while(k--) {
        memset(rec, 0, sizeof(rec));
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        cin >> n >> m >> t;
        for(int i = 1; i <= n; i++) {
            cin >> rec[i];
        }
        ans = 0;
        work();
        cout << ans << endl;
    }
    system("pause");
    return 0;
}
