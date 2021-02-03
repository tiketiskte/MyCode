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
int t, r, c, w[MAXN][MAXN], f[MAXN][MAXN];
int main(void) {
    IOS
    cin >> t;
    while(t--) {
        memset(w, 0, sizeof(w));
        memset(f, 0, sizeof(f));
        cin >> r >> c;
        for(int i = 1; i <= r; i++) {
            for(int j = 1; j <= c; j++) {
                cin >> w[i][j];
            }
        }
        for(int i = 1; i <= r; i++) {
            for(int j = 1; j <= c; j++) {
                f[i][j] = max(f[i - 1][j], f[i][j - 1]) + w[i][j];
            }
        }
        cout << f[r][c] << endl;
    }
    system("pause");
    return 0;
}
