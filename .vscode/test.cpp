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

ll l, r, sum;   
bool check(int x) {
    while(x) {
        int i = x % 10;
        if(i == 4 || i == 7) {
            return false;
        }
    }
    return true;
}
ll get(int x) {
    // cout << "Funtion 2:" << x + 1 << endl;
    return x;
}
int main(void) {
    IOS
    cin >> l >> r;
    for(ll i = l; i <= r; i++) {
        if(!check(get(i))) {
            sum += get(i) + 1;
            cout << sum << endl;
        }
    }
    cout << sum << endl;
    system("pause");
    return 0;
}
