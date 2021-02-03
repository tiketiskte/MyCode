/**
* Copyright(c)
* Author : tiketiskte
**/
#include <bits/stdc++.h>
using namespace std;
#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define rep(i, a, n) for(int i = a; i < n; i++)
#define per(i, a, n) for(int i = n - 1; i >= a; i--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sqr(x) (x) * (x)
#define SZ(X) (int)X.size()
#define all(x) (x).begin(), (x).end()
#define INF 0x3f3f3f3f
typedef long long ll;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <double, double> PDD;

ll gcd(ll a, ll b) {return b ? gcd(b, a % b) : a;}

const int MAXN = 100 + 5;
int n, x, s[MAXN][MAXN];
void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> x;
            s[i][j] = s[i - 1][j] + x; 
        }
    }
    int res = -128;
    for(int i = 1; i <= n; i++) {
        for(int j = i; j <= n; j++) {
            int f = 0;
            for(int k = 1; k <= n; k++) {
                int w = s[j][k] - s[i - 1][k];
                f = max(f, 0) + w;
                res = max(res, f);
            }
        }
    }
    cout << res << endl;
}
int main(void) {
    IOS
    solve();
    system("pause");
    return 0;
}
