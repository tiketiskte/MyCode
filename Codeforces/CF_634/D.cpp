/**
* Copyright(c)
* Author : tiketiskte
*/
#include <bits/stdc++.h>
#define IOS {ios::sync_with_stdio(false);cin.tie(0);}
#define ll long long
#define INF 0x3f3f3f3f

using namespace std;

int t;
vector<string> v;
string temp;
int main()
{
   IOS
   cin >> t;
   while(t--) {
       for(int i = 0; i < 9; i++) {
           cin >> temp;
           v.push_back(temp);
       }
       for(auto i: v) {
          for(auto j: i) {
              if(v[i][j] == '2') {

              }
          }
       }
       for(int i = 0; i < 9; i++) {
           cout << v[i] << endl;
       }
       v.clear();
   }
//    system("pause");
   return 0;
}
