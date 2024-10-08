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
const int maxn = 2e5 + 5;
struct point
{
    double x, y;
    int flag;// 1 station 0 agent
    /* bool operator < (const point& b) {
        if(x != b.x) {
            return x < b.x;
        }
        return y < b.y;
    } */
}p[maxn];

int T;
int n;
double ANS;
bool cmp_x(const point& a, const point& b) {
    return a.x == b.x ? a.y < b.y : a.x < b.x;
}
bool cmp_y(const point& a, const point& b) {
    return a.y == b.y ? a.x < b.x : a.y < b.y;
}
double dis(const point& a, const point& b) {
    return sqrt((double)(a.x - b.x) * (a.x - b.x) + (a.y -b.y) * (a.y - b.y));
}
double solve(int l, int r) {
    if(l == r) {
        return INF;
    }
    ll mid = (l + r) >> 1;
    double ans = INF;
    ans = min(ans, min(solve(l, mid), solve(mid + 1, r)));
    for(int i = mid; i >= l; i--) {
        if(p[mid].x - p[i].x > ans) {
            break;
        }
        for(int j = mid; j <= r; j++) {
            if(p[j].x - p[i].x > ans) {
                break;
            }
            if(p[j].flag != p[i].flag) {
                ans = min(ans, dis(p[i], p[j]));
            }
        }
    }
    return ans;
}

int main()
{
   IOS
   cin >> T;
   while(T--) {
       cin >> n;
       for(int i = 1; i <= n; i++) {
           cin >> p[i].x >> p[i].y;
           p[i].flag = 1;
       }
       for(int i = n + 1; i <= 2 * n; i++) {
           cin >> p[i].x >> p[i].y;
           p[i].flag = 0;
       }
       sort(p + 1, p + 1 + 2 * n, cmp_x);
       ANS = solve(1, 2 * n);
       //printf("%.3f", ANS);
       cout << setiosflags(ios::fixed) << setprecision(3) << ANS << endl;
   }
   system("pause");
   return 0;
}
