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

const int maxn = 5000 + 5;
bool a[maxn];
int n, m;
int main(void) {
    IOS
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        a[i] = true;
    }
    for(int i = 1; i <= m; i++) {
        for(int j = i; j <= n; j += i) {
            if(a[j]) {
                a[j] = false;
            } else {
                a[j] = true;
            }
        }
    }
    bool flag = true;
    for(int i = 1; i <= n; i++) {
        if(!a[i]) {
            if(flag) {
                cout << i;
                flag = false;
            } else {
                cout << "," << i;
            }
        }
    }
    cout << endl;
    system("pause");
    return 0;
}
