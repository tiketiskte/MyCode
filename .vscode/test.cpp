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

const int maxn = 2e5 + 5;
struct node {
    ll idx;
    ll voice;
    ll subtitle;
}moive[maxn];
int n, m;
unordered_map <ll, ll> mp;
bool cmp(node& a, node& b) {
    if(a.voice == b.voice) {
        return a.subtitle > b.subtitle;
    }
    return a.voice > b.voice;
}
int main()
{
    IOS
    cin >> n;
    for(int i = 1; i <= n; i++) {
        ll x;
        cin >> x;
        mp[x]++;
    }
    cin >> m;
    for(int i = 1; i <= m; i++) {
        ll x1;
        cin >> x1;
        moive[i].idx = i;
        moive[i].voice = mp[x1];
    }
    for(int i = 1; i <= m; i++) {
        ll x2;
        cin >> x2;
        moive[i].subtitle = mp[x2]; 
    }
    sort(moive + 1, moive + 1 + m, cmp);
    cout << moive[1].idx << endl;
    system("pause");
    return 0;
}
