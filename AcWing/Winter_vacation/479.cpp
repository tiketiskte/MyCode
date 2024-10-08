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

const int MAXN = 30 + 5;
int n, w[MAXN], f[MAXN][MAXN], g[MAXN][MAXN];
void dfs(int l, int r) {
    if(l > r) {
        return;
    }
    int ans = g[l][r];
    cout << ans << " ";
    dfs(l, ans - 1);
    dfs(ans + 1, r);
}
int main(void) {
    IOS
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> w[i];
    }
    for(int len = 1; len <= n; len++) {
        for(int i = 1; i + len - 1 <= n; i++) {
            int j = i + len - 1;
            if(len == 1) {
                f[i][j] = w[i];
                g[i][j] = i;
            } else {
                for(int k = i; k <= j; k++) {
                    int left = k == i ? 1 : f[i][k - 1];
                    int right = k == j ? 1 : f[k + 1][j];
                    int score = left * right + w[k];
                    if(score > f[i][j]) {
                        f[i][j] = score;
                        g[i][j] = k;
                    }
                }
            }
        }
    }
    cout << f[1][n] << endl;
    dfs(1, n);
    system("pause");
    return 0;
}
