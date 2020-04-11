/**
* Copyright(c)
* Author : tiketiskte
*/
#include <bits/stdc++.h>
#define IOS {ios::sync_with_stdio(false);cin.tie(0);}
#define INF 0x3f3f3f3f

using namespace std;
const int maxn = 100 + 5;
int main()
{
   IOS
   int t;
   int a[maxn];
   cin >> t;
   while(t--){
       int n, x, k = 0, s = 0, ans = 0;
       cin >> n >> x;
       map<int , int>mp;
       for(int i = 1; i <= n; i++){
           cin >> k;
           mp[k]++;
       }
       for(int i = 1; ; i++){
           if(ans == x){
               break;
           }
           if(mp[i] == 0){
               ans++;
               s = i;
           }
       }
       int temp = s; 
       for(int i = s + 1; i < 300; i++){
           if(mp[i] > 0){
               temp = i;
           }
           else{
               break;
           }
       }
       cout << temp << endl;
   }
   //system("pause");
   return 0;
}
