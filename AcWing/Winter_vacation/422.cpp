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

const int MAXN = 10000 + 5;

bool st[MAXN];
int l, m, a, b;

int main(void) {
    IOS
    cin >> l >> m;
    for(int i = 0; i <= l; i++) {
        st[i] = true;
    }
    for(int i = 1; i <= m; i++) {
        cin >> a >> b;
        for(int i = a; i <= b; i++) {
            st[i] = false;
        }
    }
    int ans = 0;
    for(int i = 0; i <= l; i++) {
        ans += (int)st[i];
    }
    cout << ans << endl;
    system("pause");
    return 0;
}
