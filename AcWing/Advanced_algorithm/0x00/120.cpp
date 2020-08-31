/**
* Copyright(c)
* Author : tiketiskte
**/
#include <bits/stdc++.h>
#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long
#define PII pair<int, int>
#define PLL pair<ll, ll>
#define PDD pair<double, double>
#define sqr(x) (x) * (x)
#define SZ(X) (int)X.size()
#define INF 0x3f3f3f3f

using namespace std;

int t, n;
const int maxn = 2e5 + 5;
struct node {
    int s, e, d;
}a[maxn];
ll get_sum(int x) {
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        if(a[i].s <= x) {
            ans += (min(a[i].e, x) - a[i].s) / a[i].d + 1;
        } 
    }
    return ans;
}
int main(void)
{
    IOS
    cin >> t;
    while(t--) {
        cin >> n;
        int l = 0, r = 0;
        for(int i = 0; i < n; i++) {
            cin >> a[i].s >> a[i].e >> a[i].d;
            r = max(r, a[i].e);
        }
        while(l < r) {
            int mid = (l + r) >> 1;
            if(get_sum(mid) & 1) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        ll sum = get_sum(r) - get_sum(r - 1);
        if(sum & 1) {
            cout << r << " " << sum << endl;
        } else {
            cout << "There's no weakness." << endl;
        }
    }
    system("pause");
    return 0;
}
