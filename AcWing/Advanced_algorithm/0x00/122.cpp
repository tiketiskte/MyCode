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

const int maxn = 1000000 + 5;

int n;
ll a[maxn], ans, Sum, sum[maxn];
int main(void)
{
    IOS
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        Sum += a[i];
    }
    ll avg = (ll)Sum / n;
    for(int i = 1; i <= n; i++) {
        sum[i] = a[i] - avg + sum[i - 1];
    }
    sort(sum + 1, sum + 1 + n);
    for(int i = 1; i <= n; i++) {
        ans += abs(sum[i] - sum[(n + 1) / 2]);
    }
    cout << ans << endl;
    system("pause");
    return 0;
}
