/**
* Copyright(c)
* Author : tiketiskte
**/
/* #include <bits/stdc++.h>
#define IOS {ios::sync_with_stdio(false);cin.tie(0);}
#define ll long long
#define SZ(X) (int)X.size()
#define INF 0x3f3f3f3f

using namespace std;

int n;
vector <int> v;//记录当前有哪些数
void dfs(int x, int state) {
   if(x == n) {
      for(auto it : v) {
         cout << it << " ";
      }
      cout << endl;
      return;
   }
   for(int i = 0; i < n; i++) {
      if(!(state >> i & 1)) {
         v.push_back(i + 1);//从0开始 便于state位运算
         dfs(x + 1, state | (1 << i));
         v.pop_back();//回溯
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
} */
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
int v[10];
int main()
{
   IOS
   cin >> n;
   for(int i = 1; i <= n; i++) {
      v[i] = i;
   }
   do {
      for(int i = 1; i <= n; i++) {
         cout << v[i] << " ";
      }
      cout << endl;
   }while(next_permutation(v + 1, v + 1 + n));
   system("pause");
   return 0;
}
