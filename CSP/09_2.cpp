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

const int MAXN = 1e3 + 5;
int n, k, t, xl, yd, xr, yu;
int x_t, y_t, tmp, ans1, ans2;
int a[MAXN];
int findcount(int arr[], int n) {
    int qwq = 0, count = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] == 1) {
            count++;
        } else {
            count = 0;
        }
        if(qwq < count) {
            qwq = count;
        }
    }
    return qwq;
}
void solve() {
    cin >> n >> k >> t >> xl >> yd >> xr >> yu;
    for(int i = 0; i < n; i++) {
        memset(a, 0, sizeof(a));
        for(int j = 0; j < t; j++) {
            cin >> x_t >> y_t;
            if(x_t <= xr && x_t >= xl && y_t <= yu && y_t >= yd) {
                a[j] = 1; 
            } else {
                a[j] = 0;
            }
        }
        tmp = findcount(a, t);
        if(tmp > 0) { //in
            ans1++;
        }
        if(tmp >= k) { //>= k
            ans2++;
        }
    }
    cout << ans1 << endl << ans2 << endl;
}
int main(void) {
    IOS
    solve();
    system("pause");
    return 0;
}
