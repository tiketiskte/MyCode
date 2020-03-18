/**
* Copyright(c)
* Author : tiketiskte
*/
#include <bits/stdc++.h>
#define IOS {ios::sync_with_stdio(false);cin.tie(0);}
#define INF 0x3f3f3f3f

using namespace std;

int main()
{
   IOS
   string s1, s2;
   cin >> s1 >> s2;
   string ans;
   int l1 = s1.length(), l2 = s2.length();
   for(int i = 0; i <= l1; i++) {
       if(s2.find(s1[i]) == string::npos && ans.find(toupper(s1[i])) == string::npos) {
           ans += toupper(s1[i]);
       }
   }
   cout << ans << endl;
   //system("pause");
   return 0;
}
