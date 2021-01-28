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

const int MAXN = 1000 + 5;
int n, a[MAXN];
int main(void) {
    IOS
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = 1e18;
    for(int i = 0; i + 17 <= 100; i++) {
        int cost = 0;
        int l = i, r = i + 17;
        for(int j = 0; j < n; j++) {
            if(a[j] < l) {
                cost += sqr(l - a[j]);
            } else if(a[j] > r) {
                cost += sqr(a[j] - r);
            }
        }
        ans = min(ans, cost);
    }
    cout << ans << endl;
    system("pause");
    return 0;
}
