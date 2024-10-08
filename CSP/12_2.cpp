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

const int MAXN = 1e5 + 5;
int m, y[MAXN], result[MAXN], ans[MAXN];
void solve() {
    cin >> m;
    for(int i = 0; i < m; i++) {
        cin >> y[i] >> result[i];
    }
    int maxn = 0, ANS = 0;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < m; j++) {
            if(y[j] >= y[i]) {
                if(result[j] == 1) {
                    ans[i]++;
                }
            } else {
                if(result[j] == 0) {
                    ans[i]++;
                }
            }
        }
        if(ans[i] > maxn) {
            maxn = ans[i];
            if(ANS < y[i]) {
                ANS = y[i];
            }
        }
    }
    cout << ANS << endl;
}
int main(void) {
    IOS
    solve();
    system("pause");
    return 0;
}
