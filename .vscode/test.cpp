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

int f(unsigned int x) {
    int cnt = 0, c = 0;
    cout << x << endl;
    while(x) {
        c++, cnt++;
        cout << cnt << ":" << x << endl;
        x = x & (x - 1);
    }
    return c;
}
int main(void) {
    IOS
    int x = 2, y, z;
    x *= (y = z = 5);
    cout << x << endl;
    z = 3;
    x == (y = z);
    cout << x << endl;
    x = (y == z);
    cout << x << endl;
    x = (y & z);
    cout << x << endl;
    system("pause");
    return 0;
}
