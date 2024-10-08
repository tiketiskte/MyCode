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
/*
void solve(SqList &L, int m, int n) {
    int x[MAXN], k = 0, flag = 0;
    for(int i = 0; i < m; i++) {
        x[i] = L.data[i];
    }
    for(int i = m; i < m + n; i++) {
        L.data[k++] = L.data[i];
    }
    for(int i = n; i < m + n; i++) {
        L.data[i] = x[flag++];
    }
}
*/
void PrintList(SqList L) {
    cout << "L's element:" << endl;
    if(L.length == 0) {
        cout << "SqList is empty!" << endl;
    }
    for(int i = 0; i < L.length; i++) {
        cout << L.data[i] << " ";
    }
    cout << endl;
}
int main(void) {
    IOS
    SqList L1, L2, L3;
    int temp1[5] = {1, 2, 3, 4, 5};
    memcpy(L1.data, temp1, 5 * sizeof(int));
    L1.length = 5;
    int temp2[7] = {12, 11, 10, 9, 8, 7, 6};
    memcpy(L2.data, temp2, 7 * sizeof(int));
    L2.length = 7;
    int temp3[12] = {1, 2, 3, 4, 5, 12, 11, 10, 9, 8, 7, 6};
    memcpy(L3.data, temp3, 12 * sizeof(int));
    L3.length = 12;
    // solve(L3, 5, 7);
    PrintList(L3);
    system("pause");
    return 0;
}
