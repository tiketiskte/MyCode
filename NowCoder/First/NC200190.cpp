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

const int maxn = 15 + 5;
int n, m, k;   
int matrix[maxn][maxn];
ll rowsum[maxn], columnsum[maxn];
bool bit[maxn];
ll ans;
int convert(int x) {
    memset(bit, 0, sizeof(bit));
    int cnt = 0, i = 1;
    while(x) {
        if(x & 1) {
            bit[i] = 1;
            cnt++;
        }
        x >>= 1;
        i++;
    }
    return cnt;
}
int main()
{
   IOS
   cin >> n >> m >> k;
   for(int i = 1; i <= n; i++) {
       for(int j = 1; j <= m; j++) {
           cin >> matrix[i][j];
           rowsum[i] += matrix[i][j];
       }
   }
   if(k > n) {//全选处理
       k = n;
   }
   if(k > m) {
       k = m;
   }
   int tmp = (1 << n) - 1;
   for(int T = 0; T <= tmp; T++) {
       int numrow = convert(T);//行
       int numcolumn = k - numrow;//列
       if(numrow > n || numcolumn > m || numrow < 0 || numcolumn < 0) {
           continue;
       }
       ll sum = 0;//now ans
       for(int i = 1; i <= n; i++) {
           if(bit[i]) {
               sum += rowsum[i];
           }
       }
       memset(columnsum, 0, sizeof(columnsum));
       for(int i = 1; i <= n; i++) {
           for(int j = 1; j <= m; j++) {
               if(!bit[i]) {
                   columnsum[j] += matrix[i][j];
               }
           }
       }
       sort(columnsum + 1, columnsum + 1 + m);
       for(int i = 1, j = m; i <= numcolumn; i++, j--) {
           sum += columnsum[j];
       }
       ans = max(ans, sum);
   }
   cout << ans << endl;
   system("pause");
   return 0;
}
