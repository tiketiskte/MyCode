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

int n;
vector <int> path;
void dfs(int x, int state) {
   if(x == n) {
      for(auto it : path) {
         cout << it << " ";
      }
      cout << endl;
      return;
   }
   for(int i = 0; i < n; i++) {
      if(!(state >> i & 1)) {
         path.push_back(i + 1);
         dfs(x + 1, state | (1 << i));
         path.pop_back();
      }
   }
}
int main()
{
   IOS
   cin >> n;
   dfs(0, 0);
   system("pause");
   return 0;
}
