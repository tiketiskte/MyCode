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

const int MAXN = 200 + 5;
int t, r, c, dist[MAXN][MAXN];
char g[MAXN][MAXN];
int bfs(PII start) {
    queue <PII> q;
    q.push(start);
    memset(dist, -1, sizeof(dist));
    dist[start.first][start.second] = 0;
    int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
    while(!q.empty()) {
        PII t = q.front();
        q.pop();

        for(int i = 0; i < 4; i++) {
            int x = t.first + dx[i], y = t.second + dy[i];
            if(x >= 0 && x < r && y >= 0 && y < c && g[x][y] != '#' && dist[x][y] == -1) {
                dist[x][y] = dist[t.first][t.second] + 1;
                if(g[x][y] == 'E') {
                    return dist[x][y];
                }
                q.push(make_pair(x, y));
            }
        }
    }
    return -1;
}
int main(void) {
    IOS
    cin >> t;
    while(t--) {
        cin >> r >> c;
        PII start;
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                cin >> g[i][j];
                if(g[i][j] == 'S') {
                    start = make_pair(i,j);
                }
            }
        }
        /* for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(g[i][j] == 'S') {
                    start = make_pair(i,j);
                }
            }
        } */
        int ans = bfs(start);
        if(ans == -1) {
            cout << "oop!" << endl;
        } else {
            cout << ans << endl;
        }
    }
    system("pause");
    return 0;
}
