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

vector<int> v;
 

int main()
{
   IOS
   int n, x;
   cin >> n;
   for(int i = 1; i <= n; i++) {
   		cin >> x;
		v.push_back(x); 
   }   
   for(auto &it:v) {
   		cout << *it << endl;
   }
   system("pause");
   return 0;
}
