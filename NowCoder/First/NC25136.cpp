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
const int maxn = 32000 + 5;
int N;
struct node
{
    int l, r;
    /* data */
}a[maxn];
bool cmp(node a, node b) {
    if(a.r == b.r) {
        return a.l < b.l;
    }
    return a.r < b.r;
}
int main()
{
   IOS
   cin >> N;
   int x;
   for(int i = 1; i <= N; i++) {
       cin >> a[i].l >> x;
       a[i].r = a[i].l + x;
   }
   sort(a + 1, a + 1 + N, cmp);
   int ans = 0;
   int now = 0;
   for(int i = 1; i <= N; i++) {
       if(a[i].l >= now) {
           ans++;
           now = a[i].r;
       }
   }
   cout << ans << endl;
   system("pause");
   return 0;
}
