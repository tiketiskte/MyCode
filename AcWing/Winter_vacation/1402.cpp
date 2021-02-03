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
const double eps = 1e-6;
int w, h, top;
char g[MAXN][MAXN];
PII starry[MAXN * MAXN];
double Hash[26 + 5];
int id;
double get_dist(PII a, PII b) {
    double dx = a.first - b.first;
    double dy = a.second - b.second;
    return sqrt(sqr(dx) + sqr(dy));
}
double get_hash() {
    double sum = 0;
    for(int i = 0; i < top; i++) {
        for(int j = i + 1; j < top; j++) {
            sum += get_dist(starry[i], starry[j]);
        }
    }
    return sum;
}
char get_id(double key) {
    // static double Hash[26 + 5];
    // static int id = 0;
    for(int i = 0; i < id; i++) {
        if(fabs(Hash[i] - key) < eps) {
            return i + 'a';
        }
    }
    Hash[id++] = key;
    return id - 1 + 'a';
}
void dfs(int ux, int uy) {
    starry[top++] = make_pair(ux, uy);
    g[ux][uy] = '0';
    for(int x = ux - 1; x <= ux + 1; x++) {
        for(int y = uy - 1; y <= uy + 1; y++) {
            if(x == ux && y == uy) {
                continue;
            }
            if(x >= 0 && x <= h - 1 && y >= 0 && y <= w - 1 && g[x][y] == '1') {
                dfs(x, y);
            }
        }
    }
}
int main(void) {
    IOS
    cin >> w >> h;
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            cin >> g[i][j];
        }
    }
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            if(g[i][j] == '1') {
                top = 0;
                dfs(i, j);
                char c = get_id(get_hash());
                for(int k = 0; k < top; k++) {
                    g[starry[k].first][starry[k].second] = c;
                }
            }
        }
    }
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            cout << g[i][j];
        }
        cout << endl;
    }
    system("pause");
    return 0;
}
