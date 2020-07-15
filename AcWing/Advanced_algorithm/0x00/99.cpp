#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn = 5000 + 5;
int sum[maxn][maxn];
int main(void) {
    int n, r;
    cin >> n >> r;
    int max_x = r, max_y = r;
    for(int i = 1; i <= n; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        x++, y++;
        sum[x][y] = w;
        max_x = max(max_x, x);
        max_y = max(max_y, y);
    }
    for(int i = 1; i <= max_x; i++) {
        for(int j = 1; j <= max_y; j++) {
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + sum[i][j];
        }
    }
    ll ans = 0;
    for(int i = r; i <= max_x; i++) {
        for(int j = r; j <= max_y; j++) {
            ans = max(ans, (ll)sum[i][j] - sum[i - r][j] - sum[i][j - r] + sum[i - r][j - r]);
        }
    }
    cout << ans << endl;
    return 0;
}