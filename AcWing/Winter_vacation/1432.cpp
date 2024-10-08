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

const int MAXN = 13 + 5;
bool col[MAXN], dg[MAXN * 2], udg[MAXN * 2];
int n, path[MAXN], ans;
void dfs(int x) { // x 行 y 列 依次枚举
    if(x > n) {
        ans++;
        if(ans <= 3) {
            for(int i = 1; i <= n; i++) {
                cout << path[i] << " ";
            }
            cout << endl;
        }
        return ;
    }
    for(int y = 1; y <= n; y++) {
        if(!col[y] && !dg[y - x + n] && !udg[x + y]) {
            path[x] = y;
            col[y] = dg[y - x + n] = udg[x + y] = true;
            dfs(x + 1);
            col[y] = dg[y - x + n] = udg[x + y] = false;
            path[x] = 0;
        }
    }
}
int main(void) {
    IOS
    cin >> n;
    dfs(1);
    cout << ans << endl;
    system("pause");
    return 0;
}
