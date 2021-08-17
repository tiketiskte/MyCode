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

const int MAXN = 100 + 5;
typedef struct node {
    int data[MAXN];
    int length;
}SqList;
void PrintList(SqList L) {
    cout << "L's element:" << endl;
    for(int i = 0; i < L.length; i++) {
        cout << L.data[i] << " ";
    }
    cout << endl;
}
void solve(SqList &L, int x) {
    int cnt = 0;
    for(int i = 0; i < L.length; i++) {
        if(L.data[i] == x) {
           cnt++;
        } else {
            L.data[i - cnt] = L.data[i];
        }
    }
    L.length = L.length - cnt;
}
int main(void) {
    IOS
    SqList L;
    int e = 1;
    int temp[9] = {7, 7, 5, 2, 1, 1, 3, 1, 4};
    // L.data = {5, 4, 3, 9, 1, 7, 8, 2, 6, 10};
    memcpy(L.data, temp, 9 * sizeof(int));
    L.length = 9;
    PrintList(L);
    solve(L, e);
    PrintList(L);
    system("pause");
    return 0;
}
