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

int t[13], f[13];
int main()
{
   IOS
   t[1] = 1;
   for(int i = 2; i <= 12; i++) {
       t[i] = 2 * t[i- 1] + 1;
   }
   memset(f, INF, sizeof(f));
   f[0] = 0;
   f[1] = 1;
   for(int i = 1; i <= 12; i++) {
       for(int j = 0; j < i; j++) {
           f[i] = min(f[i], f[j] * 2 + t[i -j]);
       }
   }
   for(int i = 1; i <= 12; i++) {
       cout <<"t" << i << ":" <<  t[i] << endl; 
   }
   for(int i = 1; i <= 12; i++) {
       cout <<"f" << i << ":" <<  f[i] << endl; 
   }
   system("pause");
   return 0;
}