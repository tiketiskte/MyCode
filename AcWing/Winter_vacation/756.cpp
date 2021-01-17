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
int mp[MAXN][MAXN], n, m;
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
void solve() {
    cin >> n >> m;
    int x = 0, y = 0, d = 1;
    for(int i = 1; i <= n * m; i++) {
        mp[x][y] = i;
        int nx = x + dx[d], ny = y + dy[d];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m || mp[nx][ny]) {
            d = (d + 1) % 4;
            nx = x + dx[d], ny = y + dy[d];
        }
        x = nx, y = ny;
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << mp[i][j] << " ";
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
