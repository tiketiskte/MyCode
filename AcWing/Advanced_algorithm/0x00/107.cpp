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

const int maxn = 500000 + 5;
int n;
ll a[maxn], b[maxn], ans;
void merge(int l, int mid, int r) {
    int p1 = l, p2 = mid + 1;
    for(int i = l; i <= r; i++) {
        if((p2 > r) || (p1 <= mid && a[p1] <= a[p2])) {
            b[i] = a[p1];
            p1++;
        } else {
            ans += mid - p1 + 1;
            b[i] = a[p2];
            p2++;
        }
    }
    for(int i = l; i <= r; i++) {
        a[i] = b[i];
    }
}
void merge_sort(int l, int r) {
    int mid = (l + r) >> 1;
    if(l < r) {
        merge_sort(l, mid);
        merge_sort(mid + 1, r);
    }
    merge(l, mid, r);
}
int main()
{
    IOS
    while(cin >> n && n) {
        ans = 0;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        merge_sort(1, n);
        cout << ans << endl;
    }
    system("pause");
    return 0;
}
