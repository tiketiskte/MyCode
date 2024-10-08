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

const int maxn = 5e4 + 5;
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
int N, ans, now;
int main()
{
   IOS
   cin >> N;
   now = -1;
   ans = 0;
   for(int i = 1; i <= N; i++) {
      cin >> a[i].l >> a[i].r;
   }
   sort(a + 1, a + 1 + N, cmp);
   for(int i = 1; i <= N; i++) {
      if(a[i].l >= now) {
         now = a[i].r;
         ans++;
      }
   }
   cout << ans << endl;
   system("pause");
   return 0;
}
