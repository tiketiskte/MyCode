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

const int maxn = 5e5 + 5;
struct node {
    int x, y, val;
    bool operator < (const node& a) const{
        if(val > 0 && a.val > 0) {
            return x < a.x;
        }
        if(val < 0 && a.val < 0) {
            return y > a.y;
        }
        return val > a.val;
    }
}stone[maxn];
int T, n, m;
int main()
{
   IOS
   cin >> T;
   while(T--) {
       cin >> n >> m;
       for(int i = 1; i <= n; i++) {
           cin >> stone[i].x >> stone[i].y;
           stone[i].val = stone[i].y - stone[i].x;
       }
       sort(stone + 1, stone + 1 + n);
       ll sum = m;
       bool flag = true;
       for(int i = 1; i <= n; i++) {
           if(stone[i].x > sum) {
               flag = false;
               break;
           }
           sum += stone[i].val;
       }
       if(flag) {
           cout << "Yes" << endl;
       } else {
           cout << "No" << endl;
       }
   }
   system("pause");
   return 0;
}
