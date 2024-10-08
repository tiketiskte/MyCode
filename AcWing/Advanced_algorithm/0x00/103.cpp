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
struct point {
    ll idx;
    ll voice;
    ll subtitle;
}movie[maxn];
int n, m;
map <ll, ll> mp;
bool cmp(point a, point b) {
    if(a.voice == b.voice) {
        return a.subtitle > b.subtitle;
    }
    return a.voice > b.voice;
}
int main()
{
    IOS
    cin >> n;
    ll x;
    for(int i = 1; i <= n; i++) {
        cin >> x;
        mp[x]++;
    }
    cin >> m;
    for(int i = 1; i <= m; i++) {
        ll x1;
        cin >> x1;
        movie[i].idx = i;
        movie[i].voice = mp[x1];
    }
    for(int i = 1; i <= m; i++) {
        ll x2;
        cin >> x2;
        movie[i].subtitle = mp[x2];
    }
    sort(movie + 1, movie + 1 + m, cmp);
    /* for(int i = 1; i <= m; i++) {
        cout << "idx:" << movie[i].idx << endl << "voice:" << movie[i].voice  << endl << "subtitle:" << movie[i].subtitle << endl;
    } */
    cout << movie[1].idx << endl;
    system("pause");
    return 0;
}
