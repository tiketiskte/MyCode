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
void solve(SqList L1, SqList L2, SqList &L3) {
    int i = 0, j = 0, k = 0;
    while(i < L1.length && j < L2.length) {
        if(L1.data[i] <= L2.data[j]) {
            L3.data[k++] = L1.data[i++];
        } else {
            L3.data[k++] = L2.data[j++];
        }
    }
    while(i < L1.length) {
        L3.data[k++] = L1.data[i++];
    }
    while(j < L2.length) {
        L3.data[k++] = L2.data[j++];        
    }
    L3.length = L1.length + L2.length;
}
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
    int temp1[5] = {2, 2, 3, 3, 3};
    memcpy(L1.data, temp1, 5 * sizeof(int));
    L1.length = 5;
    int temp2[5] = {5, 6, 6, 6, 7};
    memcpy(L2.data, temp2, 5 * sizeof(int));
    L2.length = 5;
    PrintList(L1);
    PrintList(L2);
    solve(L1, L2, L3);
    PrintList(L3);
    system("pause");
    return 0;
}
