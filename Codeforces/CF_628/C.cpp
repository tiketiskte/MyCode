/**
* Copyright(c)
* Author : tiketiskte
*/
#include <bits/stdc++.h>
#define IOS {ios::sync_with_stdio(false);cin.tie(0);}
#define INF 0x3f3f3f3f

using namespace std;
const int maxn = 1e5 + 5;
vector<int>edge[maxn];
int ans[maxn];
int n, u, v;
int main()
{
   IOS
   cin >> n;
   for(int i = 1; i < n; i++) {
      cin >> u >> v;
      edge[u].push_back(i);
      edge[v].push_back(i);
   }
   for()
   system("pause");
   return 0;
}
