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
int n;
int a[maxn], ans;
int main(void)
{
    IOS
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n, greater<int>());
    for(int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    sort(a + 1, a + 1 + n, less<int>());
    for(int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}
