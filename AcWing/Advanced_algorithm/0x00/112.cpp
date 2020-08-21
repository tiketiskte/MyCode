/**
* Copyright(c)
* Author : tiketiskte
**/
#include <bits/stdc++.h>
#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long
#define PLL pair<ll, ll>
#define PII pair<int, int>
#define PDD pair<double, double>
#define sqr(x) (x) * (x)
#define SZ(X) (int)X.size()
#define INF 0x3f3f3f3f

using namespace std;

const int maxn = 1000 + 5;
const double eps = 1e-6;
int n, d, ans;
double x, y;
bool flag;
PDD radar[maxn];
bool cmp(PDD a, PDD b) {
    if(a.second == b.second) {
        return a.first < b.first;
    }
    return a.second < b.second;
}
int main(void)
{
    IOS
    cin >> n >> d;
    for(int i = 1; i <= n; i++) {
        cin >> x >> y;
        if(y > d) {
            flag = true;
            break;
        }
        double a = sqrt(sqr(d) - sqr(y));
        radar[i] = make_pair(x - a, x + a);
    }
    if(flag) {
        cout << -1 << endl;
        return 0;
    } else {
        sort(radar + 1, radar + 1 + n, cmp);
        double last = -INF;
        for(int i = 1; i <= n; i++) {
            if(radar[i].first > last) {
                ans++;
                last = radar[i].second;
            }
        }
        cout << ans << endl;
    }
    system("pause");
    return 0;
}
