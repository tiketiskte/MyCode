/**
* Copyright(c)
* Author : tiketiskte
**/
#include <bits/stdc++.h>
#define IOS {ios::sync_with_stdio(false);cin.tie(0);}
#define ll long long
#define SZ(X) (int)X.size()
#define INF 0x3f3f3f3f

using namespace std;

int m, n;
void dfs(int x, int sum, int state) {//state 二进制表示第i状态
    if(sum + n - x < m) {
        return;
    }
    /* if(x == n) {
        return;
    } */
    if(sum == m) {
        for(int i = 0; i < n; i++) {
            if(state >> i & 1) {
                cout << i + 1 << " ";
            }
        }
        cout << endl;
        return;
    }
    dfs(x + 1, sum + 1, state | 1 << x);
    dfs(x + 1, sum, state);
}
int main()
{
   IOS
   cin >> n >> m;
   dfs(0, 0, 0);
   system("pause");
   return 0;
}
