/**
* Copyright(c)
* Author : tiketiskte
*/
#include <bits/stdc++.h>
#define IOS {ios::sync_with_stdio(false);cin.tie(0);}
#define ll long long
#define INF 0x3f3f3f3f

using namespace std;
const int maxn = 2000 + 5;
int t, n, a, b;
// string s;
int main()
{
   IOS
   cin >> t;
   while(t--) {
       cin >> n >> a >> b;
       for(int i = 0; i < n; i++) {
           cout << char(i % b + 'a');
       }
       cout << endl;
   }
   system("pause");
}