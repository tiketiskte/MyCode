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

const int maxn = 26 + 5;
struct Matrix{
    int row, column;
};
int n, a, b;
int main(void) {
    while(cin >> n) {
        char name;
        string ss;
        Matrix qwq[maxn];
        while(n--) {
            cin >> name >> a >> b;
            qwq[name - 'A'].row = a;
            qwq[name - 'A'].column = b;
        }
        getchar();
        getline(cin, ss);
        ll sum = 0;
        deque <char> dq;
        for(int i = 0; i < SZ(ss); i++) {
            if(ss[i] != ')') {
                dq.push_back(ss[i]);
            } else {
                string s;
                while(dq.back() != '(') {
                    s += dq.back();
                    dq.pop_back();
                }
                dq.pop_back();
                for(int j = SZ(s) - 1; j > 0; j--) {
                    int m1 = s[j] - 'A';  
                    int m2 = s[j - 1] - 'A'; 
                    if(qwq[m1].column != qwq[m2].row) {
                        sum = -1;
                        break;
                    }
                    sum += qwq[m1].row * qwq[m1].column * qwq[m2].column;
                    qwq[m2].row = qwq[m1].row;
                }
                dq.push_back(s[0]);
                if(sum == -1) {
                    break;
                }
            }
        }
        if(sum != -1) {
            string s;
            while(dq.size()) {
                s += dq.front();
                dq.pop_front();
            }
            for(int j = 0; j < SZ(s) - 1; j++) {
                int m1 = s[j] - 'A';
                int m2 = s[j + 1] - 'A';
                if(qwq[m1].column != qwq[m2].row) {
                    sum = -1;
                    break;
                }
                sum += qwq[m1].row * qwq[m1].column * qwq[m2].column;
                qwq[m2].row = qwq[m1].row;
            }
            if(sum != -1) {
                cout << sum << endl;
                continue;
            }
        }
        cout << "error" << endl;
    }
    system("pause");
    return 0;
}