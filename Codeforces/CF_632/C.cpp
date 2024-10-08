/**
* Copyright(c)
* Author : tiketiskte
*/
#include <bits/stdc++.h>
#define IOS {ios::sync_with_stdio(false);cin.tie(0);}
#define ll long long
#define INF 0x3f3f3f3f
#define endl "\n"
using namespace std;
const int maxn = 2e5 + 5;
ll a[maxn];
ll ans;
map<ll, ll>mp;//每一个前缀和出现的下标
int main()
{
   IOS
   int n;
   cin >> n;
   for(int i = 1; i <= n; i++) {
       cin >> a[i];
   }
   ll sum = 0;
   mp[0] = 0;
   ll temp = -1;//当前位置 区间
   for(int i = 1; i <= n; i++) {
       sum += a[i];
       if(mp.count(sum)) {
           temp = max(temp, mp[sum]);
       }
       mp[sum] = i;//更新
       ans += i - (temp + 1);
   }
   cout << ans << endl;
   system("pause");
   return 0;
}
