/**
* Copyright(c)
* Author : tiketiskte
**/
#include <bits/stdc++.h>
#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long
#define PII pair<int, int>
#define PLL pair<ll, ll>
#define PDD pair<double, double>
#define sqr(x) (x) * (x)
#define SZ(X) (int)X.size()
#define INF 0x3f3f3f3f

using namespace std;

int change[4][4];
int get(int x, int y) {
    return x * 4 + y;
}
int main(void)
{
    IOS
    int state = 0;
    for(int i = 0; i < 4; i++) {
        string line;
        cin >> line;
        for(int j = 0; j < 4; j++) {
            if(line[j] == '+') {
                state += 1 << get(i, j);
            }
        }
    }
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            for(int k = 0; k < 4; k++) {
                change[i][j] += 1 << get(i, k);
                change[i][j] += 1 << get(k, j);
            }
            change[i][j] -= 1 << get(i, j);
        }
    }
    vector <PII> res;
    for(int k = 0; k < (1 << 16); k++) {
        int now = state;
        vector <PII> path;
        for(int i = 0; i < 16; i++) {
            if(k >> 1 & i) {
                int x = i / 4, y = i % 4;
                now ^= change[x][y];
                path.push_back(make_pair(x, y));
            }
        }
        if(!now && (res.empty() | res.size() > path.size())) {
            res = path;
        }
    }
    for(auto p : res) {
        cout << p.first + 1 << " " << p.second + 1 << endl;
    }
    system("pause");
    return 0;
}