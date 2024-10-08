/**
* Copyright(c)
* Author : tiketiskte
*/
#include <bits/stdc++.h>
#define IOS {ios::sync_with_stdio(false);cin.tie(0);}
#define ll long long
#define INF 0x3f3f3f3f
#define SZ(X) (int)X.size()

using namespace std;
const int maxn = 100 + 5;
int t, n, k, x;
set<int>st;
set<int>::iterator it;
int main()
{
   IOS
   cin >> t;
   while(t--) {
       cin >> n >> k;
       for(int i = 1; i <= n; i++) {
           cin >> x;
           st.insert(x);
       }
       //cout << st.size() << "###" << endl;
       if(SZ(st) > k) {
           cout << "-1" << endl;
           st.clear();//......
           continue;//nmd
       }
       cout << n * k << endl;
       for(int i = 1; i <= n; i++) {
          for(it = st.begin(); it != st.end(); it++) {
              cout << *it << " ";
          }
          for(int j = 0; j < k - (int)st.size(); j++) {
              cout << 1 << " ";
          } 
       }
       cout << endl;
       st.clear();
       /* for(it = st.begin(); it != st.end(); it++) {
           cout << *it << endl;
       } */
   }
   system("pause");
   return 0;
}
