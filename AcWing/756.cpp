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

const int MAXN = 100 + 5;
int a[MAXN][MAXN], n, m;

void solve() {
    cin >> n >> m;
    int left = 0, right = m - 1, top = 0, bottom = n - 1;
    int cnt = 1;
    while(left <= right && top <= bottom) {
        for(int i = left; i <= right; i++) {
            a[top][i] = cnt++;
        }
        for(int i = top + 1; i <= bottom; i++) {
            a[i][right] = cnt++;
        }
        for(int i = right - 1; i >= left && top < bottom; i--) {
            a[bottom][i] = cnt++;
        }
        for(int i = bottom - 1; i > top && left < right; i--) {
            a[i][left] = cnt++;
        }
        left++, right--, top++, bottom--;
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}
int main(void) {
    IOS
    solve();
    system("pause");
    return 0;
}
