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

unordered_set <int> Hash;
int n, m, v1 = INF, v2;

int main(void) {
    IOS
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a;
        b = m - a;
        if(Hash.count(b)) {
            Hash.insert(a);
            if(a > b) {
                swap(a, b);
            }
            if(a < v1) {
                v1 = a, v2 = b;
            }
        } else {
            Hash.insert(a);
        }
    }
    if(v1 == INF) {
        cout << "No Solution" << endl;
    } else {
        cout << v1 << " " << v2 << endl;
    }
    system("pause");
    return 0;
}
