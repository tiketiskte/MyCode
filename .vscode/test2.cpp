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
 
const int maxn = 1e4 + 5;
int n, k;
ll a[maxn];
ll solve(ll arr[], int l, int r, int k) {
    if(l >= r) {
        return arr[l];
    }
    int i = l, j = r + 1;
    ll key = arr[l];
    while(true) {
        /* do {
            i++;
        }while(arr[i] < key);
        do {
            j--;
        }while(arr[j] > key); */
        while(a[++i] < key);
        while(a[--j] > key);
        if(i >= j) {
            break;
        }
        swap(arr[i], arr[j]);
    }
    if(j - l + 1 == k) {
        return key;
    }
    arr[l] = arr[j];
    arr[j] = key;
    if(j - l + 1 < k) { 
        return solve(arr, j + 1, r, k - j + l - 1);
    } else {
        return solve(arr, l, j - 1, k);
    }
}
int main(void) {
    IOS
    while(cin >> n >> k) {
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        cout << solve(a + 1, 0, n - 1, k) << endl;
    }
    // system("pause");
    return 0;
}