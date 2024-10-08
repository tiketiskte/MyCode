/**
* Copyright(c)
* Author : tiketiskte
*/
#include <bits/stdc++.h>
#define IOS {ios::sync_with_stdio(false);cin.tie(0);}
#define ll long long
#define INF 0x3f3f3f3f

using namespace std;
int t, n;
int main()
{
   IOS
   cin >> t;
   while(t--) {
       cin >> n;
       if(n <= 2) {
           cout << "0" << endl;
       } else {
           cout << (n - 1) / 2 << endl;
       }
   }
   system("pause");
   return 0;
}
