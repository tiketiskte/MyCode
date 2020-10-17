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
int n, flag = 20;
stack <int> s;
vector <int> ans;
void dfs(int x) {
    if(!flag) {
        return;
    }
    if(ans.size() == n) {
        flag--;
        for(auto it : ans) {
            cout << it;
        }
        cout << endl;
        return ;
    }
    if(s.empty()) {
        ans.push_back(s.top());
        s.pop();
        dfs(x);
        s.push(ans.back());
        ans.pop_back();
    }
    if(x <= n) {
        s.push(x);
        dfs(x + 1);
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
