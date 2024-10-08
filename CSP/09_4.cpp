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

const int MAXN1 = 100 + 5;
const int MAXN2 = 2000 + 5;
int n, m, r;
int O[MAXN1];
int Coordinate[MAXN2][MAXN1];
double Co_Co[MAXN2][MAXN2]; // co -> co travel dis
double Co_Codis[MAXN2][MAXN2]; // co -> co dis
double Co_O[MAXN2]; //co -> O dis
void solve() {
    cin >> n >> m;
    cin >> r;
    for(int i = 0; i < n; i++) {
        Co_O[i] = 0;
        for(int j = 0;)
    }
    
}
int main(void) {
    IOS
    solve();
    system("pause");
    return 0;
}
