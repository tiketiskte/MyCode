/**
* Copyright(c)
* Author : tiketiskte
*/
#include <bits/stdc++.h>
#define IOS {ios::sync_with_stdio(false);cin.tie(0);}
#define ll long long
#define INF 0x3f3f3f3f

using namespace std;
const int maxn = 200000 + 5;
int t, n;
int a[maxn], vis[maxn], ans[maxn][2];
bool check(int l1, int l2) {
    for(int i = 1; i <= n; i++) {
        vis[i] = 0;
    }
    for(int i = 1; i <= l1; i++) {
        vis[a[i]] = 1;
    }
    for(int i = 1; i <= l1; i++) {
        if(vis[i] == 0) {
            return 0;
        }
    }
    for(int i = 1; i <= n; i++) {
        vis[i] = 0;
    }
    for(int i = l1 + 1; i <= n; i++) {
        vis[a[i]] = 1;
    }
    for(int i = 1; i <= l2; i++) {
        if(vis[i] == 0) {
            return 0;
        }
    }
    return 1;
}
int main()
{
   IOS
   cin >> t;
   while(t--) {
       int ma = -1;
       memset(a, 0, sizeof(a));
       memset(vis, 0, sizeof(vis));
       memset(ans, 0, sizeof(ans));
       cin >> n;
       for(int i = 1; i <= n; i++) {
           cin >> a[i];
           ma = max(ma, a[i]);
       }
       int cnt = 0;
       if(check(ma, n - ma)) {
           cnt++;
           ans[cnt][0] = ma;
           ans[cnt][1] = n - ma;
       }
       if(ma * 2 != n && check(n - ma, ma)) {
           cnt++;
           ans[cnt][0] = n - ma;
           ans[cnt][1] = ma;
       }
       cout << cnt << endl;
       for(int i = 1; i <= cnt; i++) {
           cout << ans[i][0] << " " << ans[i][1] << endl; 
       }
   }
   system("pause");
   return 0;
}
