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

ll t, n, k;
int main()
{
   IOS
   cin >> t;
   while(t--) {
       ll cnt = 1;
       cin >> n >> k;
       for(ll i = 2; ;) {
           if(i / n == 0) {
               i++;
           } else {
               cnt++;
           }
           i++;
           if(cnt == k) {
               cout << i << endl;
               break;
           }
       }
   }
   system("pause");
   return 0;
}
