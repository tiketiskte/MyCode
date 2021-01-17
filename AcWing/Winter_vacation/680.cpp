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

const int MAXN = 100000 + 5;
int n, m;
long long a[MAXN];
bool check(double x) {
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        cnt += a[i] / x;
    }
    return cnt >= m;
}
int main(void) {
    IOS
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    double l = 0, r = 1e9;
    while(r - l > 1e-4) {
        double mid = (l + r) / 2;
        if(check(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << setiosflags(ios::fixed) << setprecision(2) << l << endl;
    system("pause");
    return 0;
}