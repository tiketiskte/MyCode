/**
* Copyright(c)
* Author : tiketiskte
**/
#include <bits/stdc++.h>
#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long
#define PII pair<int, int>
#define PLL pair<ll, ll>
#define PDD pair<double, double>
#define sqr(x) (x) * (x)
#define SZ(X) (int)X.size()
#define INF 0x3f3f3f3f

using namespace std;

const int maxn = 60000 + 5;
int n;
int cal(int n) {
    vector <ll> v(n + 1, 0);
    v[0] = v[1] = 1;
    for(int i = 2; i <= n; i++) {
        for(int j = 0; j < i; j++) {
            v[i] += v[j] * v[i - j - 1];
        }
    }
    return v[n];
}
int main(void) {
    IOS
    cin >> n;
    cout << cal(n) << endl;
    system("pause");
    return 0;
}
