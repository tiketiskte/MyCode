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

const int MAXN = 1e5 + 5; 
int n, k;
int w[MAXN], h[MAXN];
bool check(int mid) {
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        ans += (ll)h[i] / mid * (w[i] / mid);
    }
    return ans >= k;
}
int main(void) {
    IOS
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> w[i] >> h[i];
    }
    int l = 1, r = 1e5;
    while(l < r) {
        int mid = (l + r + 1) >> 1;
        if(check(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    cout << l << endl;
    system("pause");
    return 0;
}
