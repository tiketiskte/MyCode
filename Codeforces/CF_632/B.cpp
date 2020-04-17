/**
* Copyright(c)
* Author : tiketiskte
*/
#include <bits/stdc++.h>
#define IOS {ios::sync_with_stdio(false);cin.tie(0);}
#define ll long long
#define INF 0x3f3f3f3f

using namespace std;
int t, n, x;
//vector<int>a,b;
const int maxn = 1e5 + 5;
int a[maxn], b[maxn];
bool solve() {
    bool flag = false, x1 = false, x2 = false;
    for(int i = 1; i <= n; i++) {
        if(a[i] < b[i] && !x1) {
            flag = true;
            break;
        } else if(a[i] > b[i] && !x2) {
            flag = true;
            break;
        }
        if(a[i] == 1) {
            x1 = true;
        } else if(a[i] == -1) {
            x2 = true;
        }
    }
    return flag;
}
int main()
{
   IOS
   cin >> t;
   while(t--) {
       //int x;
       memset(a, 0, sizeof(a));
       memset(b, 0, sizeof(b));
       cin >> n;
       for(int i = 1; i <= n; i++) {
          /*  cin >> x;
           a.push_back(x); */
           cin >> a[i]; 
       }
       for(int i = 1; i <= n; i++) {
          /*  cin >> x;
           b.push_back(x); */
           cin >> b[i]; 
       }
       /* for(int x : a) {
           cout << x << " ";
       }
       for(int x : b) {
           cout << x << " ";
       } */
       if(solve()) {
           puts("NO");
       } else {
           puts("YES");
       }
   }
   system("pause");
   return 0;
}
