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
const int maxn = 5000 + 5;
int n, r;
int ans;
int sum[maxn][maxn];
int main()
{
   IOS
   cin >> n >> r;
   int m_x = r, m_y = r;//设置边界值为r 缩小求前缀和范围
   int x, y, w;
   for(int i = 1; i <= n; i++) {
       cin >> x >> y >> w;
       x++, y++;
       sum[x][y] = w;
       m_x = max(x, m_x);
       m_y = max(y, m_y);
   }
   for(int i = 1; i <= m_x; i++) {
       for(int j = 1; j <= m_y; j++) {
           sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + sum[i][j]; 
       }
   }
   for(int i = r; i <= m_x; i++) {
       for(int j = r; j <= m_y; j++) {
           ans = max(ans, sum[i][j] - sum[i - r][j] - sum[i][j - r] + sum[i - r][j - r]);
       }
   }
   cout << ans << endl;
   system("pause");
   return 0;
}
