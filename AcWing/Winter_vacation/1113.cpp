/**
* Copyright(c)
* Author : tiketiskte
**/
#include <bits/stdc++.h>
#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define rep(i, a, n) for(int i = a; i < n; i++)
#define per(i, a, n) for(int i = n - 1; i >= a; i--)
#define sqr(x) (x) * (x)
#define SZ(X) (int)X.size()
#define all(x) (x).begin(), (x).end()
#define INF 0x3f3f3f3f

using namespace std;
typedef long long ll;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <double, double> PDD;

ll gcd(ll a, ll b) {return b ? gcd(b, a % b) : a;}

const int MAXN = 20 + 5;
int w, h;
char g[MAXN][MAXN];
int x, y, dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
queue <PII> q;

int bfs(int ux, int uy) {
    q.push(make_pair(ux, uy));
    g[ux][uy] = '#';
    int ans = 0;
    while(!q.empty()) {
        PII t = q.front();
        q.pop();
        ans++;
        for(int i = 0; i < 4; i++) {
            int nx = t.first + dx[i], ny = t.second + dy[i];
            if(nx < 0 || nx >= h || ny < 0 || ny >= w || g[nx][ny] != '.') {
                continue;
            }
            g[nx][ny] = '#';
            q.push(make_pair(nx, ny));
        }
    }
    return ans;
}

int main(void) {
    IOS
    while(cin >> w >> h && (w != 0 && h != 0)) {
        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                cin >> g[i][j];
            }
        }
        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                if(g[i][j] == '@') {
                    x = i, y = j;
                }
            }
        }
        // cout << "qwq" << x << y << endl;
        cout << bfs(x, y) << endl;
    }
    system("pause");
    return 0;
}
