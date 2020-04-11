/**
* Copyright(c)
* Author : tiketiskte
*/
#include <bits/stdc++.h>
#define IOS {ios::sync_with_stdio(false);cin.tie(0);}
#define ll long long
#define INF 0x3f3f3f3f

using namespace std;
int t, n, x;
vector<int>a,b;
bool solve() {
    
}
int main()
{
   IOS
   cin >> t;
   while(t--) {
       cin >> n;
       for(int i = 1; i <= n; i++) {
           cin >> a[i];
       }
       for(int i = 1; i <= n; i++) {
           cin >> b[i];
       }
       if(solve()) {
           cout << "YES" << endl;
       } else {
           cout << "NO" << endl;
       }
   }
   system("pause");
   return 0;
}
