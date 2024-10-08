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

const int maxn = 1000 + 5;
int T, N, S, a[maxn];
int ans;
ll sum;
int main()
{
   IOS
   cin >> T;
   while(T--) {
       cin >> N >> S;
       for(int i = 1; i <= N; i++) {
           cin >> a[i];
       }
       int l = 1, r = 1;
       sum = 0, ans = INF;
       while(l <= N) {
           while(r <= N && sum < S) {
               sum += a[r];
               r++;
           }
           if(sum >= S) {
               ans = min(ans, r - l);// get min
           }
           sum -= a[l];
           l++;
       }
       if(ans != INF) {
           cout << ans << endl;
       } else {
           cout << "0" << endl;
       }
   }
   system("pause");
   return 0;
}
