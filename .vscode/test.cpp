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

int a, b;
void Swap(int &a, int &b){
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}
int main()
{
   IOS
   cin >> a >> b;
   Swap(a, b);
   cout << a << "qwq" << b << endl; 
   system("pause");
   return 0;
}
