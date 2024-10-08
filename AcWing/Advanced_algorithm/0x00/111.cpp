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

const int maxn = 50000 + 5;
pair <PII, int> cows[maxn];
priority_queue <PII, vector<PII>, greater<PII> > q;
int n, id[maxn];
int main(void)
{
    IOS
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> cows[i].first.first >> cows[i].first.second;
        cows[i].second = i;
    }
    sort(cows + 1, cows + 1 + n);
    for(int i = 1; i <= n; i++) {
        PII cow = cows[i];
        if(q.empty() || cow.first > q.top().first) {
            PII tmp = make_pair(cow.second, q.size() + 1);
            id[cow.s]
        }
    }
    system("pause");
    return 0;
}
