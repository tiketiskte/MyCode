/**
* Copyright(c)
* Author : tiketiskte
**/
#include <bits/stdc++.h>
#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long
#define PLL pair<ll, ll>
#define SZ(X) (int)X.size()
#define INF 0x3f3f3f3f

using namespace std;

const int maxn = 100000 + 5;
int a[maxn], b[maxn], f[maxn]; // row column
int N, M, T;
ll calc(int arr[], int x) {
    ll ans = 0;
    for(int i = 1; i <= x; i++) {
        arr[i] -= arr[0] / x;
        f[i] = f[i - 1] + arr[i];
    }
    sort(f + 1, f + 1 + x);
    for(int i = 1; i <= x; i++) {
        ans += abs(f[i] - f[(x + 1) >> 1]);
    }
    return ans;
}
int main()
{
    IOS
    cin >> N >> M >> T;
    for(int i = 1; i <= T; i++) {
        int x, y;
        cin >> x >> y;
        a[x]++, b[y]++;
    }
    for(int i = 1; i <= N; i++) {
        a[0] += a[i];
    }
    for(int i = 1; i <= M; i++) {
        b[0] += b[i];
    }
    if(a[0] % N == 0 && b[0] % M == 0) {
        cout << "both " << calc(a, N) + calc(b, M) << endl;
    } else if(a[0] % N == 0) {
        cout << "row " << calc(a,N) << endl;
    } else if(b[0] % M == 0) {
        cout << "column " << calc(b, M) << endl;
    } else {
        cout << "impossible" << endl;
    }
    system("pause");
    return 0;
}
