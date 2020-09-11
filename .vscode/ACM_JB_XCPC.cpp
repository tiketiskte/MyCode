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

const int maxn = 30 + 5;
int n;
int a[maxn];
void quick_sort(int arr[], int l, int r) {
    int i = l, j = r;
    int k = arr[l];
    while(i < j) {
        while(arr[j] >= k && i < j) {
            j--;
        }
        arr[i] = arr[j];
        a[j] = k;
        while(arr[i] <= k && i < j) {
            i++;
        }
        a[j] = a[i];
        a[i] = k;
    }
    for(int i = l; i < r; i++) {
        cout << arr[i] << " ";
    }
    cout << arr[r] << endl;
    a[i] = l;
    if(i - 1 > l) {
        quick_sort(arr, l, i - 1);
    }
    if(i + 1 < r) {
        quick_sort(arr, i + 1, r);
    } 
}
int main(void)
{
    IOS
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    quick_sort(a, 1, n);
    system("pause");
    return 0;
}
