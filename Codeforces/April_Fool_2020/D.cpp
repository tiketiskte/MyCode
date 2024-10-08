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
   string s;
   cin >> s;
   if(s[6] % 2 == 1){
       cout << "1" << endl;  
   }
   else if(s[6] % 2 == 0){ 
       cout << "0" << endl;
   }
   //system("pause");
   return 0;
}

