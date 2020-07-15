/**
* Copyright(c)
* Author : tiketiskte
**/
#include <bits/stdc++.h>
#define IOS {ios::sync_with_stdio(false);cin.tie(0);}
#define ll long long
#define PLL pair<ll, ll>
#define SZ(X) (int)X.size()
#define INF 0x3f3f3f3f

using namespace std;

const int maxn = 1e4 + 5;
int N;
ll P, H, M;
int A, B;
map <ll, ll> mp;
ll d[maxn], ans[maxn];
int main()
{
   IOS
   cin >> N >> P >> H >> M;
   for(int i = 1; i <= M; i++) {
       cin >> A >> B;
       if(A > B) {
           swap(A, B);
       }
       if(mp[A] != B) {
           mp[A] = B, d[A + 1]--, d[B]++;
       }
   }
   for(int i = 1; i <= N; i++) {
       ans[i] = ans[i - 1] + d[i];
   }
   for(int i = 1; i <= N; i++) {
       cout << ans[i] + H << endl;
   }
   system("pause");
   return 0;
}
