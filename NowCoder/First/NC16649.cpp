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
const int maxn = 1e4 + 5;
int L, M;
int l, r;
int ans;
int a[maxn];
int main()
{
   IOS
   cin >> L >> M;
   for(int i = 0; i <= L; i++) {
       a[i] = 1;
   }
   for(int i = 1; i <= M; i++) {
       cin >> l >> r;
        for(int j = l; j <= r; j++) {
            a[j] = 0;
        }
   }
   for(int i = 0; i <= L; i++) {
       if(a[i] != 0) {
           ans++;
       }
   }
   cout << ans << endl;
   system("pause");
   return 0;
}
