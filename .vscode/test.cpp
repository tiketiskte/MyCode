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
int n, a[maxn]; 
void print(int a[], int size) {
    for(int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }
    cout << a[size] << endl;
}
void quicksort(int arr[], int l, int r) {
    if(l >= r) {
        return;
    }
    int key = arr[l];
    int i = l, j = r;
    while(i < j) {
        while(i < j && a[j] > key) {
            j--;
        }
        if(i < j) {
            arr[i] = arr[j];
        }
        while(i < j && a[i] <= key) {
            i++;
        }
        if(i < j) {
            arr[j] = arr[i];
        }
    }
    arr[i] = key;
    print(arr, n - 1);
    quicksort(arr, l, i - 1);
    quicksort(arr, i + 1, r);
}
int main(void)
{
    IOS
    int x;
    while(cin >> x) {
        a[n++] = x;
        if(cin.get() == '\n') {
            break;
        }
    }
    quicksort(a, 0, n - 1);
    system("pause");
    return 0;
}