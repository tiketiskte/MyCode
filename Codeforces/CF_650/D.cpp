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

int t, m;
void solve() {
   string s;
   cin >> s;
   int len = s.length();
   vector <int> cnt(26);
   for(int i = 0; i < len; i++) {
      ++cnt[s[i] - 'a'];
   }
   cin >> m;
   vector <int> b(m);
   for(int i = 0; i < m; i++) {
      cin >> b[i];
   }
   vector <int> flag(m);
   for(int i = 0; i < m; i++) {
      if(b[i] == 0) {
         flag[i] = 1;
      }
   }
   int T = 1;
   while(count(flag.begin(), flag.end(), 0)) {
      T++;
      vector <int> now;
      //vector <int> ::iterator it;
      for(int i = 0; i < m; i++) {
         if(!flag[i]) {
            int tmp = 0;
            for(int j = 0; j < m; j++) {
               if(flag[j]) {
                  tmp += abs(i - j);
               }
            }
            if(tmp == b[i]) {
               now.push_back(i);
            }
         }
      }
      for(auto it : now) {
         flag[it] = T;
      }
      /* for(it = now.begin(); it != now.end(); it++) {
         flag[*it] = T;
      } */
   }
   int p = 25;
   vector <char> ans(m);
   //vector <char> ::iterator it2;
   for(int t = 1; t <= T; t++) {
      int num = 0;
      for(int i = 0; i < m; i++) {
         if(flag[i] == t) {
            num++;
         }
      }
      while(p >= 0 && cnt[p] < num) {
         --p;
      }
      for(int i = 0; i < m; i++) {
         if(flag[i] == t) {
            ans[i] = (p + 'a');
         }
      }
      --p;
   }
  /*  for(it2 = ans.begin(); it2 != ans.end(); it2++) {
      cout << *it2;
   } */
   for(auto it : ans) {
      cout << it;
   }
   cout << endl;
}
int main()
{
   IOS
   cin >> t;
   while(t--) {
      solve();
   }
   system("pause");
   return 0;
}
