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

const int maxn = 505 * 505;
int n, a[maxn], b[maxn], c[maxn];
ll ans;
void merge(int arr[], int l, int mid, int r) {
    int p1 = l, p2 = mid + 1;
    for(int i = l; i <= r; i++) {
        if((p2 > r) || (p1 <= mid && arr[p1] <= arr[p2])) {
            c[i] = arr[p1];
            p1++;
        } else {
            ans += mid - p1 + 1;
            c[i] = arr[p2];
            p2++;
        }
    }
    for(int i = l; i <= r; i++) {
        arr[i] = c[i];
    }
}
void merge_sort(int arr[], int l, int r) {
    int mid = (l + r) >> 1;
    if(l < r) {
        merge_sort(arr, l, mid);
        merge_sort(arr, mid + 1, r);
    }
    merge(arr, l, mid, r);
}
int main()
{
    IOS
    while(cin >> n) {
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        int x, flag = 0;
        for(int i = 1; i <= n * n; i++) {
            cin >> x;
            if(x) {
                a[i - flag] = x;
            } else {
                flag = 1;
            }
        }
        flag = 0;
        for(int i = 1; i <= n * n; i++) {
            cin >> x;
            if(x) {
                b[i - flag] = x;
            } else {
                flag = 1;
            }
        }
        ll cnt1, cnt2;
        cnt1 = 0, ans = 0;
        memset(c, 0, sizeof(c));
        merge_sort(a, 1, n * n);
        cnt1 = ans;
        cnt2 = 0, ans = 0;
        memset(c, 0, sizeof(c));
        merge_sort(b, 1, n * n);
        cnt2 = ans;
        if((cnt1 & 1) == (cnt2 & 1)) {
            cout << "TAK" << endl;
        } else {
            cout << "NIE" << endl;
        }
    }
    // system("pause");
    return 0;
}