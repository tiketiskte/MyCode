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


int n;
int main(void) {
    IOS
    cin >> n;
    int ans = 1, d2 = 0, d5 = 0;
    for(int i = 1; i <= n; i++) {
        int x = i;
        while(x % 2 == 0) {
            x /= 2;
            d2++;
        }
        while(x % 5 == 0) {
            x /= 5;
            d5++;
        }
        ans = ans * x % 10;
    }
    int k = min(d2, d5);
    for(int i = 0; i < d2 - k; i++) {
        ans = ans * 2 % 10;
    }
    for(int i = 0; i < d5 - k; i++) {
        ans = ans * 5  % 10;
    }
    cout << ans << endl;
    system("pause");
    return 0;
}
