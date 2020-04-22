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
map<int, int>mp;
int main()
{
   IOS
   cin >> t;
   while(t--) {
       cin >> n;
       for(int i = 1; i <= n; i++) {
           cin >> x;
           mp[x]++;
       }
       int cnt = 0, k = 0;//cnt:多少种数 k:一样人数的统计
       for(int i = 1; i<= n; i++) {
           if(mp[i]) {
               cnt++;
           }
           k = max(mp[i], k);
        }
        //cout << cnt << endl;
        //cout << k << endl;
        if(cnt > k) {
            cout << k << endl;
        } else {
            cout << min(k - 1, cnt) << endl;
        }
        mp.clear();
   }
   system("pause");
   return 0;
}
