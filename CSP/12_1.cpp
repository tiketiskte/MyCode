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
const int  MAXN = 1E5 + 5;    
int w[MAXN], score[MAXN];
int n;
void solve() {
    cin >> n;
    int flag = 0, ans = 0;
    for(int i = 0; i < n; i++) {
        cin >> w[i] >> score[i];
    }
    ll sum = 0;
    for(int i = 0; i < n; i++) {
        sum += w[i] * score[i];
    }
    if(sum > flag) {
        ans = sum;
    } else {
        ans = 0;
    }
    cout << ans << endl;
}
int main(void) {
    IOS
    solve();
    system("pause");
    return 0;
}
