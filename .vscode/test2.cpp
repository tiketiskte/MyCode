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
vector <int> A, B;
string a, b;
vector <int> add(vector <int>& x, vector <int>& y) {
    vector <int> ans;
    int t = 0;
    for(int i = 0; i < SZ(x) || i <SZ(y); i++) {
        if(i < SZ(x)) {
            t += x[i];
        } 
        if(i < SZ(y)) {
            t += y[i];
        }
        ans.pb(t % 10);
        t /= 10;
    }
    if(t) {
        ans.pb(1);
    }
    return ans;
}
int main(void) {
    IOS
    cin >> a >> b;
    for(int i = SZ(a) - 1; i >= 0; i--) {
        A.pb(a[i] - '0');
    }
    for(int i = SZ(b) - 1; i >= 0; i--) {
        B.pb(b[i] - '0');
    }
    vector <int> c = add(A, B);
    for(int i = SZ(c) - 1; i >= 0; i--) {
        cout << c[i];
    }
    cout << endl;
    system("pause");
    return 0;
}
