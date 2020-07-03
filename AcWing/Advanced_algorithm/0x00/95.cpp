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

int T;
int n;
char Map[6][6];
int ans = INF;
bool check() {
    for(int i = 1; i <= 5; i++) {
        for(int j = 1; j <= 5; j++) {
            if(Map[i][j] == '0') {
                return false;
            }
        }
    }
    return true;
}
void flip(int x, int y) {
    if(Map[x][y] == '1') {
        Map[x][y] = '0';
    } else if(Map[x][y] == '0') {
        Map[x][y] = '1';
    }
    if(Map[x - 1][y] == '1') {
        Map[x - 1][y] = '0';
    } else if(Map[x - 1][y] == '0') {
        Map[x - 1][y] = '1';
    }
    if(Map[x + 1][y] == '1') {
        Map[x + 1][y] = '0';
    } else if(Map[x + 1][y] == '0') {
        Map[x + 1][y] = '1';
    }
    if(Map[x][y - 1] == '1') {
        Map[x][y - 1] = '0';
    } else if(Map[x][y - 1] == '0') {
        Map[x][y - 1] = '1';
    }
    if(Map[x][y + 1] == '1') {
        Map[x][y + 1] = '0';
    } else if(Map[x][y + 1] == '0') {
        Map[x][y + 1] = '1';
    }
}
void dfs(int x, int y, int step) {
    if(check()) {
        if(step < ans) {
            ans = step;
        }
        return;
    }
    if(x == 6 || y == 6) {
        return;
    }
    flip(x, y);
    if(y == 5) {
        dfs(x + 1, 1, step + 1);
    } else {
        dfs(x, y + 1, step + 1);
    }
    flip(x, y);//回溯
    if(y == 5) {
        dfs(x + 1, 1, step);
    } else {
        dfs(x, y + 1, step);
    }
}
int main()
{
   IOS
   cin >> n;
   while(n--) {
       ans = INF;
       for(int i = 1; i <= 5; i++) {
           for(int j = 1; j <= 5; j++) {
               cin >> Map[i][j];
           }
       }
       dfs(1, 1, 0);
       if(ans != INF && ans <= 6) {
           cout << ans << endl;
       } else {
           cout << -1 << endl;
       }
   }
   system("pause");
   return 0;
}
