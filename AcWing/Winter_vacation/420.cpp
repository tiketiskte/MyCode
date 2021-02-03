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

const int MAXN = 10000 + 5;
int n, m, a[MAXN];
int main(void) {
    IOS
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    while(m--) {
        int k = n;
        while(a[k - 1] > a[k]) {
            k--;
        }
        int t = k;
        while(a[t + 1] > a[k - 1]) {
            t++;
        }
        swap(a[k - 1], a[t]);
        reverse(a + k, a + n + 1);
    }
    for(int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}
