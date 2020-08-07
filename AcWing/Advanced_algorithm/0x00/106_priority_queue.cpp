/**
* Copyright(c)
* Author : tiketiskte
**/
#include <bits/stdc++.h>
#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long
#define PLL pair<ll, ll>
#define SZ(X) (int)X.size()
#define INF 0x3f3f3f3f

using namespace std;

int P;
int main()
{
    IOS
    cin >> P;
    while(P--) {
        int n, m, x, cnt = 0;
        cin >> n >> m;
        cout << n << " " << (m + 1) / 2 << endl;
        priority_queue <int, vector <int>, less<int> > q;
        priority_queue <int, vector <int>, greater<int> > p;
        for(int i = 1; i <= m; i++) {
            cin >> x;
            p.push(x);
            if(q.size() && q.top() > p.top()) {
                int a = p.top(), b = q.top();
                p.pop(), q.pop();
                p.push(b), q.push(a);
            }
            if(p.size() > q.size() + 1) {
                q.push(p.top());
                p.pop();
            }
            if(i & 1) {
                cout << p.top() << (++cnt % 10 == 0 ? '\n' : ' ');
                //printf("%d%c", p.top(), ++cnt % 10 == 0 ? '\n' : ' ');
            }
        }
        if(cnt % 10) {
            cout << endl;
        }
    }
    system("pause");
    return 0;
}
