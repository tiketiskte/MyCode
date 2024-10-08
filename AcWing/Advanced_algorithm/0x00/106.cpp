/**
* Copyright(c)
* Author : tiketiskte
**/
#include <bits/stdc++.h>
#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long
#define PLL pair<ll, ll>
#define SZ(X) (int)X.size()
#define INF 0x3f3f3f3f

using namespace std;

const int maxn = 9999 + 5;
struct node {
    ll x;
    int y;
}a[maxn];
bool cmp(node a, node b) {
    return a.x < b.x;
}
int P;
int main()
{
    IOS
    cin >> P;
    for(int cas = 1; cas <= P; cas++) {
        int n, M;
        vector <ll> ans;
        cin >> n >> M;
        for(int i = 0; i < M; i++) {
            cin >> a[i].x;
            a[i].y = i + 1;
        }
        sort(a, a + M, cmp);
        for(int i = 0; i < M; i += 2) {
            int flag = 0;
            for(int j = 0; j < M; j++) {
                if(a[j].y <= i + 1) {
                    flag++;
                }
                if(flag == (i + 2) / 2) {
                    ans.push_back(a[j].x);
                    break;
                }
            }
        }
        cout << cas << " " << ans.size();
        for(int i = 0; i < (int)ans.size(); i++) {
            if(i % 10 == 0) {
                cout << endl;
            }
            if(i % 10 == 0) {
                cout << ans[i];
            } else {
                cout << " " << ans[i];
            }
        }
        cout << endl;
    }
    system("pause");
    return 0;
}
