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

char Map[5][5];
int ans = INF;//get_min set_max
bool check() {
    char temp = Map[1][1];
    for(int i = 1; i <= 4; i++) {
        for(int j = 1; j <= 4; j++) {
            if(Map[i][j] != temp) {
                return false;
            }
        }
    }
    return true;
}
// vertical is x and horizontal is y
void flip(int x, int y) {
    if(Map[x][y] == 'w') {//flip self
        Map[x][y] = 'b';
    } else if(Map[x][y] == 'b'){
        Map[x][y] = 'w';
    }
    if(Map[x - 1][y] == 'w') {//flip up
        Map[x - 1][y] = 'b';
    } else if(Map[x - 1][y] == 'b') {
        Map[x - 1][y] = 'w';
    }
    if(Map[x + 1][y] == 'w') {//flip down
        Map[x + 1][y] = 'b';
    } else if(Map[x + 1][y] == 'b') {
        Map[x + 1][y] = 'w';
    }
    if(Map[x][y - 1] == 'w') {//flip left
        Map[x][y - 1] = 'b';
    } else if(Map[x][y - 1] == 'b') {
        Map[x][y - 1] = 'w';
    }
    if(Map[x][y + 1] == 'w') {//flip right
        Map[x][y + 1] = 'b';
    } else if(Map[x][y + 1] == 'b') {
        Map[x][y + 1] = 'w';
    }
}
void DFS(int x, int y, int cnt) {
    if(check()) {
        if(cnt < ans) {//min_step
            ans = cnt;
        }
        return;
    }
    if(x == 5 || y == 5) {
        return;
    }
    flip(x, y);//flip
    if(y == 4) {
        DFS(x + 1, 1, cnt + 1);
    } else {
        DFS(x, y + 1, cnt + 1);
    }
    flip(x, y);//flip_back
    //not flip
    if(y == 4) {
        DFS(x + 1, 1, cnt);
    } else {
        DFS(x, y + 1, cnt);
    }
}
int main()
{
   IOS
   for(int i = 1; i <= 4; i++) {
       for(int j = 1; j <= 4; j++) {
           cin >> Map[i][j];
       }
   }
   DFS(1, 1, 0);
   //cout << "ans:" << ans << endl;
   if(ans != INF) {
       cout << ans << endl;
   } else {
       cout << "Impossible" << endl;
   }
   //system("pause");
   return 0;
}
