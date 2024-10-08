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

const int maxn = 1e4 + 5;

int n;
int a[maxn], b[maxn], g[maxn], k[maxn];
int x, y;
int flag = 0;
int main()
{
   IOS
   cin >> n;
   for(int i = 1; i <= n; i++) {
       cin >> a[i] >> b[i] >> g[i] >> k[i];
   }
   cin >> x >> y;
   for(int i = n; i > 0; i--) {
       if(x >= a[i] && x <= a[i] + g[i]) {
           if(y >= b[i] && y <= b[i] + k[i]) {
               cout << i << endl;
               flag = 1;
               return 0;
           }
       }
   }
   if(flag) {
       return 0;
   } else {
       cout << "-1" << endl;
   }
   system("pause");
   return 0;
}
