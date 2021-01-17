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

const int MAXN = 500 + 5;
int n, f[MAXN][MAXN], w[MAXN][MAXN];
void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            cin >> w[i][j];
        }
    }
    for(int i = 1; i < n; i++) {
        f[n][i] = w[n][i];
    }
    for(int i = n - 1; i >= 0; i--) {
        for(int j = 1; j <= i; j++) {
            f[i][j] = max(f[i + 1][j] + w[i][j], f[i + 1][j + 1] + w[i][j]);
        }
    }
    cout << f[1][1] << endl;
}
int main(void) {
    IOS
    solve();
    system("pause");
    return 0;
}
