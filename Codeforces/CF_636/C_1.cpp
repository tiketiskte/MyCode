/**
* Copyright(c)
* Author : tiketiskte
*/
#include <bits/stdc++.h>
#define IOS {ios::sync_with_stdio(false);cin.tie(0);}
#define ll long long
#define INF 0x3f3f3f3f

using namespace std;
const int maxn = 2e5 + 5;
pair<int, ll>dp[maxn][2];
//dp[i][0].first表示前i项交错子序列以正数结尾的最长长度
//dp[i][0].second表示前i项交错子序列以正数结尾的最长长度的最大和
//dp[i][1].first表示前i项交错子序列以负数结尾的最长长度
//dp[i][1].second表示前i项交错子序列以负数结尾的最长长度的最大和
int t, n;
int a[maxn];
int main()
{
   IOS
   cin >> t;
   while(t--) {
       cin >> n;
       for(int i = 1; i <= n; i++) {
           cin >> a[i];
           dp[i][0] = make_pair(0, 0);
           dp[i][1] = make_pair(0, 0);
       }
       for(int i = 1; i <= n; i++) {
           dp[i][0] = max(dp[i - 1][0], dp[i][0]);
           dp[i][1] = max(dp[i - 1][1], dp[i][1]);
           if(a[i] > 0) {
               dp[i][0] = max(dp[i - 1][0], make_pair(dp[i - 1][1].first + 1, dp[i - 1][1].second + a[i]));
           } else {
               dp[i][1] = max(dp[i - 1][1], make_pair(dp[i - 1][0].first + 1, dp[i - 1][0].second + a[i]));
           }
        //    cout << endl;
        //    cout << "###1:" << dp[i][0].first << " " << "###2:" << dp[i][0].second << endl;
        //    cout << "$$$1:" << dp[i][1].first << " " << "$$$2:" << dp[i][1].second << endl;
       }
       pair<int, ll>ans;
       ans = max(dp[n][0], dp[n][1]);
       cout << ans.second << endl;
   }
   system("pause");
   return 0;
}
