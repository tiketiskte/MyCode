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
int n, a[MAXN][MAXN];
int main(void) {
    IOS
    while(cin >> n && n) {
        memset(a, 0, sizeof(a));
        rep(i, 0, n) {
            a[i][0] = i + 1, a[0][i] = i + 1;
        }
        rep(i, 1, n) {
            rep(j, 1, n) {
                a[i][j] = a[i - 1][j - 1];
            }
        }
        rep(i, 0, n) {
            rep(j, 0, n) {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    system("pause");
    return 0;
}
