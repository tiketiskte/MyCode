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

const int maxn = 1e5 + 5;
int cows[maxn];
double sum[maxn];
int N, F;
bool check(double avg) {
    for(int i = 1; i <= N; i++) {
        sum[i] = sum[i - 1] + cows[i] - avg;
    }
    double min_avg = 0;
    for(int i = 0, j = F; j <= N; i++, j++) {
        min_avg = min(min_avg, sum[i]);
        if(sum[j] >= min_avg) {
            return true;
        }
    }
    return false;
}
int main()
{
//    IOS
   cin >> N >> F;
   for(int i = 1; i <= N; i++) {
       cin >> cows[i];
   }
   double l = 0, r = 2000;
   while(r - l > 1e-5) {
       double mid = (l + r) / 2;
       if(check(mid)) {
           l = mid;
       } else {
           r = mid;
       }
   }
   cout << (int)(r * 1000) << endl;
   system("pause");
   return 0;
}
