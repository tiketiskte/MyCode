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

const int maxn = 1000 + 5;
int n;
char s[maxn][maxn];
void dfs(int n) {
    if(n == 1) {
        s[0][0] = 'X';
        return ;
    }
    dfs(n - 1);
    int len = 1;
    for(int i = 0; i < n - 2; i++) {
        len *= 3;
    }
    int sx[4] = {0, 1, 2, 2}, sy[4] = {2, 1, 0, 2};
    for(int k = 0; k < 4; k++) {
        for(int i = 0; i < len; i++) {
            for(int j = 0; j < len; j++) {
                s[sx[k] * len + i][sy[k] * len + j] = s[i][j];
            }
        }
    }
}
int main(void)
{
    IOS
    dfs(7);
    while(cin >> n && n != -1) {
        int k = 1;
        for(int i = 0; i < n - 1; i++) {
            k *= 3;
        }
        for(int i = 0; i < k; i++) {
            for(int j = 0; j < k; j++) {
                if(s[i][j]) {
                    cout << s[i][j];
                } else {
                    cout << " ";
                }
            }
            cout << endl;
        }
        cout << "-" << endl;
    }
    system("pause");
    return 0;
}
