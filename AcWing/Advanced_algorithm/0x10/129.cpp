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

stack <int> s;
vector <int> v;
int n, flag = 20;
void dfs(int u) {
    if(!flag) {
        return ;
    }
    if(SZ(v) == n) {
        flag--;
        for(auto it : v) {
            cout << it;
        }
        cout << endl;
    }
    if(s.size()) {
        v.push_back(s.top());
        s.pop();
        dfs(u);
        s.push(v.back());
        v.pop_back();
    }
    if(u <= n) {
        s.push(u);
        dfs(u + 1);
        s.pop();
    }
}
int main(void) {
    IOS
    cin >> n;
    dfs(1);
    system("pause");
    return 0;
}
