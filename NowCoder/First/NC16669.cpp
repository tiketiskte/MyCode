/**
* Copyright(c)
* Author : tiketiskte
*/
#include <bits/stdc++.h>
#define IOS {ios::sync_with_stdio(false);cin.tie(0);}
#define ll long long
#define SZ(X) (int)X.size()
#define INF 0x3f3f3f3f

using namespace std;

int N, x;
set<int>s;
set<int>::iterator it;
int main()
{
   IOS
   cin >> N;
   for(int i = 1; i <= N; i++) {
      cin >> x;
      s.insert(x);
   }
   cout << s.size() << endl;
   for(it = s.begin(); it != s.end(); it++) {
      cout << *it << " ";
      //printf("%d ", *it);
   }
   //system("pause");
   return 0;
}