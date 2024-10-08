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

int n;
void solve() {
    int cnt = 0;
    scanf("%d", &n);
    while(n != 1) {
        if(n % 2 == 1) {
            n = (3 * n + 1) / 2;
            // printf("#%d ",n);
            cnt++;
        } else {
            n = n / 2;
            // printf("*%d ",n);
            cnt++;
        }
    }
    printf("%d\n", cnt);
}
int main(void) {
    // IOS
    solve();
    system("pause");
    return 0;
}
