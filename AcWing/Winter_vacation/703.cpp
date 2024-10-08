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

const int MAXN = 36 + 5;
int t, n, m, w[MAXN][MAXN];
bool st[MAXN];
bool check_row() {
    for(int i = 0; i < m; i++) {
        memset(st, 0, sizeof(st));
        for(int j = 0; j < m; j++) {
            int t = w[i][j];
            if(t < 1 || t > m) {
                return false;
            }
            if(st[t]) {
                return false;
            }
            st[t] = true;
        }
    }
    return true;
}
bool check_col() {
    for(int i = 0; i < m; i++) {
        memset(st, 0, sizeof(st));
        for(int j = 0; j < m; j++) {
            int t = w[j][i];
            if(t < 1 || t > m) {
                return false;
            }
            if(st[t]) {
                return false;
            }
            st[t] = true;
        }
    }
    return true;
}
bool check_cell() {
    for(int x = 0; x < m; x += n) {
        for(int y = 0; y < m; y += n) {
            memset(st, 0, sizeof(st));
            for(int dx = 0; dx < n; dx++) {
                for(int dy = 0; dy < n; dy++) {
                    int t = w[x + dx][y + dy];
                    if(t < 1 || t > m) {
                        return false;
                    }
                    if(st[t]) {
                        return false;
                    }
                    st[t] = true;
                }
            }
        }
    }
    return true;
}
int main(void) {
    IOS
    cin >> t;
    for(int cnt = 1; cnt <= t; cnt++) {
        cin >> n;
        m = n * n;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < m; j++) {
                cin >> w[i][j];
            }
        }
        if(check_row() && check_col() && check_cell()) {
            cout << "Case #" << cnt << ": " << "Yes" << endl; 
        } else {
            cout << "Case #" << cnt << ": " << "No" << endl; 
        }
    }
    system("pause");
    return 0;
}
