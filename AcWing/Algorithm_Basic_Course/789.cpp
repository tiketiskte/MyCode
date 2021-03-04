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
int n, q, x, a[MAXN];
bool check1(int qwq) {
    if(a[qwq] >= x) {
        return true;
    } else {
        return false;
    }
}
bool check2(int qaq) {
    if(a[qaq] <= x) {
        return true;
    } else {
        return false;
    }
}
int main(void) {
    IOS
    cin >> n >> q;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    while(q--) {
        cin >> x;
        int l = 0, r = n - 1;
        while(l < r) {
            int mid = (l + r) >> 1;
            if(check1(mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        if(a[l] != x) {
            cout << "-1 -1" << endl;
        } else {
            cout << l << " ";
            int l = 0, r = n - 1;
            while(l < r) {
                int mid = (l + r + 1) >> 1; 
                if(check2(mid)) {
                    l = mid;
                } else {
                    r = mid - 1;
                }
            }
            cout << l << endl;
        }
    }
    system("pause");
    return 0;
}
