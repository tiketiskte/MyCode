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
       int ans1 = 0, ans2 = 0;
       cin >> n;
       n /= 2;
       if(n % 2 == 1) {
           cout << "NO" << endl;
           continue;
       }
       cout << "YES" << endl;
       for(int i = 1; i <= n; i++) {
           cout << 2 * i << " ";
           ans1 += i * 2;
       }
       for(int i = 1; i < n; i++) {
           cout << 2 * i - 1 << " ";
           ans2 += 2 * i - 1;
       }
       cout << 2 * n - 1 + n <<endl;
    //    cout << endl;
    //    cout << "###1:" << ans1  << " " << "###2:" << ans2 << endl;
   }
    system("pause");
   return 0;
}
