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
const int maxn1 = 1000 + 10;
const int maxn2 = 1000000 + 10;
int t, k, n, x, cnt, z;
int team[maxn2];
string command;
queue <int> q;
queue <int> everyteam[maxn1];
int main(void) {
    IOS
    while(cin >> t && t) {
        memset(team, 0, sizeof(team));
        k = x = cnt = 0;
        cout << "Scenario #" << k++ << endl;
        for(int i = 0; i < n; i++) {
            cin >> cnt;
            while(cnt--) {
                cin >> x;
                team[x] = i;
            }
        }
        while(cin >> command && command != "STOP") {
            if(command[0] == 'E') {
                cin >> z;
                int ans = team[z];
                if(everyteam[ans].empty()) {
                    q.push(ans);
                }
                everyteam[ans].push(z);
            } else {
                int ans = q.front();
                auto &tmp = everyteam[ans];
                cout << tmp.front() << endl;
                tmp.pop();
                if(tmp.empty()) {
                    q.pop();
                }
            }
        }
        cout << endl;
    }
    system("pause");
    return 0;
}
