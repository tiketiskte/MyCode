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

const int maxn = 5000 + 5;
int n;
struct node {
    int h, m, s;
}a[maxn];
bool cmp(node &a, node&b) {
    /* if(a.h == b.h) {
        if(a.m == b.m) {
            return a.s < b.s;
        } else {
            return a.m < b.m;
        }
    } else {
        return a.h < b.h;
    } */
    if(a.h != b.h) {
        return a.h < b.h;
    }
    if(a.m != b.m) {
        return a.m < b.m;
    }
    if(a.s != b.s) {
        return a.s < b.s;
    }
}
int main()
{
   IOS
   cin >> n;
   for(int i =1; i <= n; i++) {
       cin >> a[i].h >> a[i].m >> a[i].s;
   }
   sort(a + 1, a + 1 + n, cmp);
   for(int i = 1; i <= n; i++) {
       cout << a[i].h << " " << a[i].m << " " << a[i].s << endl;
   }
   system("pause");
   return 0;
}
