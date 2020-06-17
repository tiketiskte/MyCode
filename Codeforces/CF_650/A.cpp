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

int t;
void solve() {
    string a, b;
    cin >> b;
    int len = b.length();
    cout << b[0];
    for(int i = 1; i < len - 1; i +=2) {
        cout << b[i];
    }
    cout << b[len - 1] << endl;
}
int main()
{
   IOS
   cin >> t;
   while(t--) {
       solve();
   }
//    system("pause");
   return 0;
}
