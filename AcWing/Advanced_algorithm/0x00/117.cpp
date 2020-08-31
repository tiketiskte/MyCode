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

const int maxn = 14;
vector <int> card[maxn];
vector <int> up(maxn);

int ans;
int get(char s) {
    if(s == 'A') {
        return 1;
    }
    if(s >= '2' && s <= '9') {
        return s - '0';
    }
    if(s == '0') {
        return 10;
    }
    if(s == 'J') {
        return 11;
    }
    if(s == 'Q') {
        return 12;
    }
    return 13;
}
int main(void)
{
    IOS
    for(int i = 1; i <= 13; i++) {
        for(int j = 0; j < 4; j++) {
            char s[2];
            cin >> s;
            card[i].push_back(get(s[0]));
        }
    }
    for(int i = 0; i < 4; i++) {
        int t = card[13][i];
        while(t != 13) {
            up[t]++;
            int tmp = card[t].back();
            card[t].pop_back();
            t = tmp;
        }
    }
    for(int i = 1; i <= 12; i++) {
        ans += (up[i] >= 4);
    }
    cout << ans << endl;
    system("pause");
    return 0;
}
