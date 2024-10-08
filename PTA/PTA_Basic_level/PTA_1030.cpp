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

const int maxn = 1e5 + 5;
int n;
ll p, a[maxn];
void solve() {
    cin >> n >> p;
    rep(i, 0, n) {
        cin >> a[i];
    }
    sort(a, a + n);
    int ans = 0, tmp = 0;
    rep(i, 0, n) {
        rep(j, i + ans, n) {
            if(a[j] <= a[i] * p) {
                tmp = j - i + 1;
                if(ans < tmp) {
                    ans = tmp;
                }
            } else {
                break;
            }
        }
    }
    cout << ans << endl;
}
int main(void) {
    IOS
    solve();
    system("pause");
    return 0;
}
