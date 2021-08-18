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
void solve(SqList &L, int s, int t) {
    if(s > t) {
        cout <<"error:Illegal Sequence" << endl;
        return ;
    }
    if(L.length == 0) {
        cout <<"error: SqList is empty!" << endl;
        return ;
    }
    int cnt = 0;
    for(int i = 0; i < L.length; i++) {
        if(L.data[i] >= s && L.data[i] <= t) {
            cnt++;
        } else {
            L.data[i - cnt] = L.data[i]; 
        }
    }
    L.length -= cnt;
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
    SqList L;
    int s, t;
    int temp[12] = {1, 2, 3, 4, 5, 5, 5, 6, 7, 8, 9, 10};
    memcpy(L.data, temp, 12 * sizeof(int));
    L.length = 12;
    PrintList(L);
    cin >> s >> t;
    solve(L, s, t);
    PrintList(L);
    system("pause");
    return 0;
}
