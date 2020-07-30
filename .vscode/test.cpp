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

const int maxn = 100 + 5;
int a[maxn];
int n, avg, ans;
ll sum;
int main()
{
    IOS
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    avg = sum / n;
    for(int i = 1; i <= n; i++) {
        if(a[i] != avg) {
            a[i + 1] += a[i] - avg;
            ans++;
        }
    }
    cout << ans << endl;
    system("pause");
    return 0;
}
