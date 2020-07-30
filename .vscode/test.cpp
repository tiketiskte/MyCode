/**
* Copyright(c)
* Author : tiketiskte
**/
#include <bits/stdc++.h>
#define IOS {ios::sync_with_stdio(false);cin.tie(0);}
#define ll long long
#define PLL pair<ll, ll>
#define SZ(X) (int)X.size()
#define INF 0x3f3f3f3f

using namespace std;

const int maxn = 1e4 +5;
int n;
ll a[maxn], ans[maxn];
stack <ll> s;

int main()
{
    IOS
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 2 * n; i >= 0; i--) {
        while(!s.empty() && s.top() <= a[i % n]) {
            s.pop();
        }
        ans[i % n] = s.empty() ? 0 : s.top();
        s.push(a[i % n]);
    }
    for(int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}
