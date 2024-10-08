#include <bits/stdc++.h>
#define IOS {ios::sync_with_stdio(false);cin.tie(0);}
#define INF 0x3f3f3f3f
using namespace std;

int dx[5] = {0, -1, 0, 1, 0};
int dy[5] = {0, 0, 1, 0, -1};
char Map[5][5];

void flip(int x, int y) {
    for(int i = 0; i < 5; i++) {
        int a = x + dx[i];
        int b = y + dy[i];
        if(a >= 0 && a < 5 && b >= 0 && b < 5) {
            Map[a][b] = '0' + !(Map[a][b] - '0');
        }
    }
}
int solve() {
    int ans = INF;
    // int now = 0;
    for(int k = 0; k < (1 << 5); k++) {
        int now = 0;//要在内循环 一行有2^5种状态每个状态从0开始计算 然后更新now和ans
        char tmp[5][5];
        memcpy(tmp, Map, sizeof(Map));
        for(int j = 0; j < 5; j++) {
            if(k >> j & 1) {
                now++;
                flip(0, j);
            }
        }
        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 5; j++) {
                if(Map[i][j] == '0') {
                    now++;
                    flip(i + 1, j);
                }
            }
        }
        bool answer = true;
        for(int i = 0; i < 5; i++) {
            if(Map[4][i] == '0') {
                answer = false;
                break;
            }
        }
        if(answer) {
            ans = min(ans, now);
        }
        memcpy(Map, tmp, sizeof(tmp));
        // cout << k << "###" << ans << endl;
    }
    if(ans > 6) {
        return -1;
    } else {
        return ans;
    }
}
int main(void) {
    IOS
    int n;
    cin >> n;
    while(n--) {
        for(int i = 0; i < 5; i++) {
            cin >> Map[i];
        }
        cout << solve() << endl;
    }
    system("pause");
}