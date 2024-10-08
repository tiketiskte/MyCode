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

const int maxn = 1e6 + 5;
ll L, M;
ll l, r;
pair<ll, ll>pr[maxn];
int main()
{
   IOS
   cin >> L >> M;
   for(int i = 1; i <= M; i++) {
      cin >> l >> r;
      pr[i] = make_pair(l, r);
   }
   sort(pr + 1, pr + 1 + M);
   ll sum = 0, end = 0;
   for(int i = 1; i <= M; i++) {
      if(pr[i].first >= end) { //interval_range
         sum += pr[i].second - pr[i].first + 1;
         end = pr[i].second;
      } else if(pr[i].second >= end) {
         sum += pr[i].second - end;
         end = pr[i].second;
      }
   }
   cout << L - sum + 1 << endl;
   system("pause");
   return 0;
}
