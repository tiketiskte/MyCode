/**
* Copyright(c)
* Author : tiketiskte
**/
#include <bits/stdc++.h>
#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define rep(i, a, n) for(int i = a; i < n; i++)
#define per(i, a, n) for(int i = n - 1; i >= a; i--)
#define ll long long
#define PII pair<int, int>
#define PLL pair<ll, ll>
#define PDD pair<double, double>
#define sqr(x) (x) * (x)
#define SZ(X) (int)X.size()
#define all(x) (x).begin(), (x).end()
#define INF 0x3f3f3f3f

using namespace std;
ll gcd(ll a, ll b) {return b ? gcd(b, a % b) : a;}
const int MAXN = 200 + 5;
PDD local[MAXN];
pair <double, int> ans[MAXN];
int n, x, y;
double dis(double a, double b, double c, double d) {
    return sqr(c - a) + sqr(d - b);
}
void solve() {
    cin >> n >> x >> y;
    for(int i = 0; i < n; i++) {
        cin >> local[i].first >> local[i].second;
    }
    for(int i = 0; i < n; i++) {
        double tmp = dis(local[i].first, local[i].second, x, y);
        ans[i] = make_pair(tmp, i);
    }
    sort(ans, ans + n);
    for(int i = 0; i < 3; i++) {
        cout << ans[i].second + 1 << endl;
    }
}
int main(void) {
    IOS
    solve();
    system("pause");
    return 0;
}
