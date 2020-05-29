/**
* Copyright(c)
* Author : tiketiskte
**/
#include <bits/stdc++.h>
#define IOS {ios::sync_with_stdio(false);cin.tie(0);}
#define ll long long
#define SZ(X) (int)X.size()
#define INF 0x3f3f3f3f
//#define endl '\n'

using namespace std;

const int maxn = 30000 + 5;
int a[maxn];
int w, n;
int ans;
int main()
{
   IOS
   cin >> w >> n;
   for(int i = 1; i <= n; i++) {
       cin >> a[i];
   }
   sort(a + 1, a + 1 + n);
   int l = 1, r = n;
   while(l <= r) {
       if(a[l] + a[r] <= w) {
           ans++, l++,r--;
       } else {
           ans++;
           r--;
       }
   }
   cout << ans << endl;
   system("pause");
   return 0;
}
