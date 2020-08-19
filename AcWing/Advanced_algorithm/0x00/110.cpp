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

const int maxn = 2500 + 5;
struct cow {
    int minSPF, maxSPF;
}a[maxn];
struct SPF {
    int SPF_value, cover;
}b[maxn];
bool cmp1(const cow &a, const cow &b) {
    if(a.minSPF == b.minSPF) {
        return a.maxSPF > b.maxSPF;
    }
    return a.minSPF > b.minSPF;
}
bool cmp2(const SPF &a, const SPF & b) {
    if(a.SPF_value == b.SPF_value) {
        return a.cover > b.cover;
    }
    return a.SPF_value > b.SPF_value;
}
int C,L;
ll ans;
int main(void)
{
    IOS
    cin >> C >> L;
    for(int i = 1; i <= C; i++) {
        cin >> a[i].minSPF >> a[i].maxSPF;
    }
    for(int i = 1; i <= L; i++) {
        cin >> b[i].SPF_value >> b[i].cover;
    }
    sort(a + 1, a + 1 + C, cmp1);
    sort(b + 1, b + 1 + L, cmp2);
    for(int i = 1; i <= C; i++) {
        for(int j = 1; j <= L; j++) {
            if(b[j].SPF_value <= a[i].maxSPF && b[j].SPF_value >= a[i].minSPF && b[j].cover) {
                ans++, b[j].cover--; break;
            }
        }
    }
    cout << ans << endl;
    system("pause");
    return 0;
}
