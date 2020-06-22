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

const int maxn = 20;
const int m = 1 << maxn;
int n;
int f[m][maxn];
int weight[maxn][maxn];
int main()
{
   IOS
   cin >> n;
   for(int i = 0; i < n; i++) {
       for(int j = 0; j < n; j++) {
           cin >> weight[i][j];
       }
   }
   memset(f, INF, sizeof(f));
   f[1][0] = 0;
   for(int i = 1; i < (1 << n); i++) {
       for(int j = 0; j < n; j++) {
           if(i >> j & 1) {
               for(int k = 0; k < n; k++) {
                   if(i - (1 << j) >> k & 1) {
                       f[i][j] = min(f[i][j], f[i - (1 << j)][k] + weight[k][j]);
                   }
               }
           }
       }
   }
   cout << f[(1 << n) - 1][n - 1] << endl;
   system("pause");
   return 0;
}
