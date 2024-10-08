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
int N, tmp;
int a[maxn];
ll ans;
int main()
{
    IOS
    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + N);
    if(N & 1) {
        tmp = a[(N + 1) >> 1];
    } else {
        tmp = (a[N >> 1] + a[(N >> 1) + 1]) / 2;
    }
    for(int i = 1; i <= N; i++) {
        ans += abs(tmp - a[i]);
    }
    cout << ans << endl;
    system("pause");
    return 0;
}
