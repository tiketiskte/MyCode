/**
* Copyright(c)
* Author : tiketiskte
*/
#include <bits/stdc++.h>
#define IOS {ios::sync_with_stdio(false);cin.tie(0);}
#define ll long long
#define INF 0x3f3f3f3f

using namespace std;
const int maxn = 1e5 + 5;
int t;
ll d, m;
ll dp[maxn], cnt[maxn];//cnt表述最高位为i的数字的个数
int main()
{
   IOS
   cin >> t;
   while(t--) {
       cin >> d >> m;
       memset(dp, 0, sizeof(dp));
       memset(cnt, 0, sizeof(cnt));
       ll cal = d, cur = 1, index = 1;
       while(cal) {
           cnt[index++] = min(d - (cur - 1), cur);
           cal >>= 1;
           cur <<= 1;
       }
       for(int i = 1; i < index; i++) {
           dp[i] = (dp[i - 1] * cnt[i] % m + cnt[i] % m + dp[i - 1]) % m; 
           //dp[i] = dp[i - 1] * cnt[i] % m;
       }
       cout << dp[index - 1] << endl;
   }   
   //system("pause");
   return 0;
}
