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

int t, n;
int main()
{
   IOS
   cin >> t;
   while(t--) {
       cin >> n;
       if(n == 3) {
           cout << "NO" << endl;
           continue;
       }
       if(n % 4 == 0) {
           cout << "YES" << endl;
       } else {
           cout << "NO" << endl;
       }
   }
   system("pause");
   return 0;
}
