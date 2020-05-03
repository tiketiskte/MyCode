/**
* Copyright(c)
* Author : tiketiskte
*/
#include <bits/stdc++.h>
#define IOS {ios::sync_with_stdio(false);cin.tie(0);}
#define ll long long
#define INF 0x3f3f3f3f

using namespace std;

int t, n;
int a, b, c, d;
void solve() {
    cin >> n >> a >> b >> c >> d;
    int r_min = a - b;
    int r_max = a + b;
    int p_min = c - d;
    int p_max = c + d;
    // cout << r_min << " " << r_max << " " << p_min << " " << p_max << endl;
    if((r_min * n > p_max) || (r_max * n < p_min)) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }
}
int main()
{
   IOS
   cin >> t;
   while(t--) {
       solve();
   }
   system("pause");
   return 0;
}
