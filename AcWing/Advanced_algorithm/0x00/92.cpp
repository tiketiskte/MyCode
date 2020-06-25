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

const int N = 15 + 5;
bool vis[N];
int n;
void dfs(int x) {
    if(x > n) {
        for(int i = 1; i <= n; i++) {
            if(vis[i]) {
                cout << i << " ";
            }
        }
        cout << endl;
        return;
    }
    vis[x] = true;
    dfs(x + 1);
    vis[x] = false;
    dfs(x + 1);
}
int main()
{
   IOS
   cin >> n;
   dfs(1);
   system("pause");
   return 0;
}
