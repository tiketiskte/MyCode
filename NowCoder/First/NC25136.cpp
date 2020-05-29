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

const int maxn = 32000 + 5;
int n, len;
pair<int, int> pr[maxn];

bool cmp(const pair<int, int>& a,const pair<int, int>& b) {
    if(a.second == b.second) {
        return a.first < b.first;
    }
    return a.second < b.second;
}
int main()
{
   IOS
   cin >> n;
   for(int i = 1; i <= n; i++) {
       cin >> pr[i].first >> len; 
       pr[i].second = pr[i].first + len;
   }
   sort(pr + 1, pr + 1 + n, cmp);
   int ans = 0, now = -1;
   for(int i = 1; i <= n; i++) {
       if(now <= pr[i].first) {
           ans++;
           now = pr[i].second;
       }
   }
   cout << ans << endl;
   system("pause");
   return 0;
}
