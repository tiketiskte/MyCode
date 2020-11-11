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

const int MAXN1 = 1000 + 5;
const int MAXN2 = 1000000 + 5;
int t, a[MAXN2];
int main(void) {
    IOS
    int cnt = 1;
    while(cin >> t && t) {
        queue <int> term[MAXN1];
        queue <int> q;
        cout << "Scenario #" << cnt++ << endl;
        for (int i = 0; i < t; i++) {
            int n;
            cin >> n;
            while(n--) {
                int x;
                cin >> x;
                a[x] = i;
            }
        }
        string command;
        while(cin >> command && command != "STOP") {
            if(command == "ENQUEUE") {
                int z;
                cin >> z;
                int tmp1 = a[z];
                if(term[tmp1].empty()) {
                    q.push(tmp1);
                }
                term[tmp1].push(z);
            } else {
                int tmp2 = q.front();
                auto &ans = term[tmp2];
                cout << ans.front() << endl;
                ans.pop();
                if(ans.empty()) {
                    q.pop();
                }
            }
        }
        cout << endl;
    }
    system("pause");
    return 0;
}
