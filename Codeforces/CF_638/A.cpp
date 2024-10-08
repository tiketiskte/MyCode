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
       ll sum1 = 0, sum2 = 0, ans = 0;
       for(int i = 1; i <= n; i++) {
           sum1 += 1 << i;
       }
       /* for(int i = 1; i <= n; i++) {
           cout << (1 << i) << " ";
       }
       cout << endl; */
       sum2 = 1 << n;
       //cout << "###" << sum2 << endl;
       int cnt = 1;
       for(int i = 1; i <= n; i++) {
           if(cnt == n / 2) {
               break;
           }
           sum2 += 1 << i;
           //cout << "###" << sum2 << endl; 
           cnt++;
       }
       ans = sum1 - sum2  - sum2;//剩余部分 - 原来部分 = 差
       //cout << sum1 <<" ###" << sum2 << endl;
       if(ans >= 0) {
           cout << ans << endl;
       } else {
           cout << fabs(ans) << endl;
       }
       //cout << "AC!!!" << endl;
   }
   system("pause");
   return 0;
}
