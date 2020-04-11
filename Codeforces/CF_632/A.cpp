/**
* Copyright(c)
* Author : tiketiskte
*/
#include <bits/stdc++.h>
#define IOS {ios::sync_with_stdio(false);cin.tie(0);}
#define ll long long
#define INF 0x3f3f3f3f

using namespace std;
int t, n, m;
int main()
{
   IOS
   cin >> t;
   while(t--) {
       cin >> n >> m;
       for(int i = 1; i <= n; i++) {
           for(int j = 1; j <= m; j++) {
               if(i == 1 && j == 1) {
                   cout <<'W';
               } else {
                   cout <<'B';
               }
           }
           cout << endl;
       }
   }
   //system("pause");
   return 0;
}