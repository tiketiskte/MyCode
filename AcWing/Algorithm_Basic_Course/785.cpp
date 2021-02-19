/**
* Copyright(c)
* Author : tiketiskte
**/
#include <bits/stdc++.h>
using namespace std;
#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define rep(i, a, n) for(int i = a; i < n; i++)
#define per(i, a, n) for(int i = n - 1; i >= a; i--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sqr(x) (x) * (x)
#define SZ(X) (int)X.size()
#define all(x) (x).begin(), (x).end()
#define INF 0x3f3f3f3f
typedef long long ll;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <double, double> PDD;

ll gcd(ll a, ll b) {return b ? gcd(b, a % b) : a;}

const int MAXN = 100000 + 5;
int n;
vector <int> v(MAXN);
void quick_sort(vector <int>& a, int l, int r) {
    if(l >= r) {
        return ;
    }
    int x = a[(l + r) >> 1], i = l - 1, j = r + 1;
    while(i < j) {
        do {i++;} while(a[i] < x);
        do {j--;} while(a[j] > x);
        if(i < j) {
            swap(a[i], a[j]);
        }
    }
    quick_sort(a, l, j);
    quick_sort(a, j + 1, r);
}
int main(void) {
    IOS
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    quick_sort(v, 0, n - 1);
    for(int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}
