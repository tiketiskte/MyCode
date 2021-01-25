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

const int MAXN1 = 25 + 5, MAXN2 = 10000 + 5;
ll f[MAXN1][MAXN2];
int v, n, v_i;
int main(void) {
    IOS
    cin >> v >> n;
    f[0][0] = 1;
    for(int i = 1; i <= v; i++) {
        cin >> v_i;
        for(int j = 0; j <= n; j++) {
            f[i][j] = f[i - 1][j];
            if(j >= v_i) {
                f[i][j] += f[i][j - v_i];
            }
        }
    }
    cout << f[v][n] << endl;
    system("pause");
    return 0;
}
