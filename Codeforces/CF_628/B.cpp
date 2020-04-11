/**
* Copyright(c)
* Author : tiketiskte
*/
#include <bits/stdc++.h>
#define IOS {ios::sync_with_stdio(false);cin.tie(0);}
#define INF 0x3f3f3f3f

using namespace std;
const int maxn = 1e5 + 5;
int t, n;
vector<int>v;
vector<int>::iterator it;
int main()
{
   IOS
   cin >> t;
   while (t--)
   {
       /* code */
       int x;
       cin >> n;
       for(int i = 0; i < n; i++) {
           cin >> x;
           v.push_back(x);
       }
       sort(v.begin(), v.end());
       /* for(it = v.begin(); it != v.end(); it++) {
           cout << *it << endl;
       } */
       v.erase(unique(v.begin(), v.end()), v.end());
       /* for(it = v.begin(); it != v.end(); it++) {
           cout << *it << endl;
       } */
       cout << v.size() << endl;
       v.clear();
   }
   //system("pause");
   return 0;
}
