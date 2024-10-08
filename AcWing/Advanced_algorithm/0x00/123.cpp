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

const int maxn = 10000 + 5;
int n;
PII soldier[maxn];
bool cmp1(PII a, PII b) {
    
}
int main(void)
{
    IOS
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> soldier[i].first >> soldier[i].second;
    }

    system("pause");
    return 0;
}
