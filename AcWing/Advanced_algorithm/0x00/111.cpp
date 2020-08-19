/**
* Copyright(c)
* Author : tiketiskte
**/
#include <bits/stdc++.h>
#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long
#define PII pair<int, int>
#define PLL pair<ll, ll>
#define SZ(X) (int)X.size()
#define INF 0x3f3f3f3f

using namespace std;

const int maxn = 5e4 + 5;
pair <PII, int> cows[maxn];
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
    priority_queue <PII, vector<PII>, greater<PII> > q;
    for(int i = 1; i <= n; i++) {
        PII cow = cows[i].first;
        if(q.empty() || cow.first <= q.top().first) {
            PII tmp = make_pair(cow.second, q.size() + 1);
            q.push(tmp);
            id[cows[i].second] = tmp.second;
        } else {
            PII tmp = q.top();
            q.pop();
            tmp.first = cow.second;
            id[cows[i].second] = tmp.second;
            q.push(tmp);
        }
    }
    cout << q.size() << endl;
    for(int i = 1; i <= n; i++) {
        cout << id[i] << endl;
    }
    system("pause");
    return 0;
}
