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

const int maxn = 1e5 + 5;
int a[maxn], b[maxn], vis[maxn];
int n;
void solve() {
    memset(b, -1, sizeof(b));
    bool flag = false;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        vis[a[i]] = 1;
        if(a[i] > i) {
            flag = true;
        }
    }
    if(flag) {
        cout << "-1" << endl;
    } else {
        for(int i = 2; i <= n; i++) {
            if(a[i] != a[i - 1]) {
                b[i] = a[i - 1];
            }
        }
        int x = 0;
        for(int i = 1; i <= n; i++) {
            while(vis[x]) {
                x++;
            }
            if(b[i] == -1) {
                b[i] = x;
                vis[x] = 1;
            }
        }
        for(int i = 1; i <= n; i++) {
            cout << b[i] << " "; 
        }
        cout << endl;
    }
}
int main()
{
   IOS
   solve();
//    system("pause");
   return 0;
}
