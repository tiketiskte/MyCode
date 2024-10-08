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
       for(int k = 2; ; k++) {
           if(n % ((1 << k) - 1) == 0) {
               cout << n / ((1 << k) - 1) << endl;
               break;
           }
       }
   }
   system("pause");
   return 0;
}
