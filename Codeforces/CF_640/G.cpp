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

int t, n;
int main()
{
   IOS
   cin >> t;
   while(t--) {
       cin >> n;
       if(n < 4) {
           puts("-1");
           continue;
       }
       for(int i = n; i >= 1; i--) {
           if(i % 2 == 1) {
               cout << i << " ";
           }
       }
       cout << "4 2 ";
       for(int i = 6; i <= n; i += 2) {
           cout << i << " ";
       }
       cout << endl; 
   }
   system("pause");
   return 0;
}
