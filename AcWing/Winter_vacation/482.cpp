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
int n, ans, h[MAXN], f[MAXN], g[MAXN];
int main(void) {
    IOS
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> h[i];
    }
    for(int i = 0; i < n; i++) {
        f[1] = 1;
        for(int j = 1; j < i; j++) {
            if(h[j] < h[i]) {
                f[i] = max(f[i], f[j] + 1);
            }
        }
    }
    for(int i = n; i > 0; i--) {
        g[1] = 1;
        for(int j = n; j > i; j--) {
            if(h[j] < h[i]) {
                g[i] = max(g[i], g[j] + 1);
            }
        }
    }
    for(int k = 0; k < n; k++) {
        ans = max(ans, f[k] + g[k] - 1);
    }
    cout << n - ans << endl;
    system("pause");
    return 0;
}
