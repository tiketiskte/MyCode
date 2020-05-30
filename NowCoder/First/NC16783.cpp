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

const int maxn = 20 + 5;
int n;
string s[maxn];
bool cmp(string a, string b) {
   return a + b < b + a;
}
int main()
{
   IOS
   cin >> n;
   for(int i = 1; i <= n; i++) {
      cin >> s[i];
   }
   sort(s + 1, s + 1 + n, cmp);
   for(int i = n; i >= 1; i--) {
      cout << s[i];
   }
   cout << endl;
   system("pause");
   return 0;
}
