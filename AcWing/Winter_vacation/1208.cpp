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

string a, b;
int ans;
void turn(int pos) {
    if(a[pos] == '*') {
        a[pos] = 'o';
    } else {
        a[pos] = '*';
    }
}
int main(void) {
    IOS
    cin >> a >> b;
    for(int i = 0; i < SZ(a) - 1; i++) {
        if(a[i] != b[i]) {
            ans++;
            turn(i), turn(i + 1);
        }
    }
    cout << ans << endl;
    system("pause");
    return 0;
}
