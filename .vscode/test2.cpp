#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn = 505 * 505;
int a[maxn], b[maxn], c[maxn];
int n;
ll ans;
void f2(int arr[], int l, int mid, int r) {
    int p1 = l, p2 = mid + 1;
    for(int i = l; i <= r; i++) {
        if((p2 > r) || (p1 <= mid && a[p1] <= a[p2])) {
            c[i] = arr[p1++];
        } else {
            c[i] = arr[p2++];
            ans += mid - p1 + 1;
        }
    }
    for(int i = l; i <= r; i++) {
        arr[i] = c[i]; 
    }
}
void f1(int arr[], int l, int r) {
    int mid = (l + r) >> 1;
    if(l < r) {
        f1(arr, l, mid);
        f1(arr, mid + 1, r);
    }
    f2(arr, l, mid, r);
}
int main(void) {
    while(cin >> n) {
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        int flag = 0, x = 0;
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
        f1(a, 1, n * n);
        cnt1 = ans;
        cnt2 = 0, ans = 0;
        memset(c, 0, sizeof(c));
        f1(b, 1, n * n);
        cnt2 = ans;
        if((cnt1 & 1) == (cnt2 & 1)) {
            cout << "TAK" << endl;
        } else {
            cout << "NIE" << endl;
        }
    }
    return 0;
}