/**
* Copyright(c)
* Author : tiketiskte
*/
#include <bits/stdc++.h>
#define IOS {ios::sync_with_stdio(false);cin.tie(0);}
#define ll long long
#define INF 0x3f3f3f3f

using namespace std;
const int maxn = 3000000 + 50;
int n, k;
char s[3005];
ll mink = 0, maxk = 0;
vector<int>v[maxn];
//vector<int>v;
void check(int x) {
   for(int i = 1; i < n;) {
      if(s[i] == 'R' && s[i + 1] == 'L') {
         s[i] = 'L';
         s[i + 1] = 'R';
         v[x].push_back(i);//表示该处有可翻转pair
         i += 2;
      } else {
         i += 1; 
      }
   }
}
void solve() {
   int p1 = 0, p2 = 0, temp = mink;
   while(temp < k) {
      cout << "1 " << v[p1][p2] << endl;
      p2++;
      if(p2 == v[p1].size()) {
         p2 = 0;
         p1++;
      } else {
         temp++;
      }
   }
   cout << v[p1].size() - p2;
   for(int i = p2; i < v[p1].size(); i++) {
      cout << " " << v[p1][i];
   }
   cout << endl;
   p1++;
   while(p1 < mink) {
      cout << v[p1].size();
      for(int i = 0; i < v[p1].size(); i++) {
         cout << " " << v[p1][i];
      }
      cout << endl;
      p1++;
   }
}
int main()
{
   IOS
   cin >> n >> k;
   cin >> s + 1;
   check(0);
   while(v[mink].size() && mink <= k) {
      maxk += v[mink].size();
      mink++;
      check(mink);//扩展 产生了新的0/1对 可交换 然后更新
   }
   if(mink <= k && k <= maxk) {
      solve();
   } else {
      cout << "-1" << endl;
   }
   system("pause");
   return 0;
}
//5.03GB 3.74GB