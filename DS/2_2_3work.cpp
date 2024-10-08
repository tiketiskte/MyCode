/**
* Copyright(c)
* Author : tiketiskte
**/
#include <bits/stdc++.h>
#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define rep(i, a, n) for(int i = a; i < n; i++)
#define per(i, a, n) for(int i = n - 1; i >= a; i--)
#define ll long long
#define PII pair<int, int>
#define PLL pair<ll, ll>
#define PDD pair<double, double>
#define sqr(x) (x) * (x)
#define SZ(X) (int)X.size()
#define all(x) (x).begin(), (x).end()
#define INF 0x3f3f3f3f

using namespace std;
const int MAXSIZE = 20;
ll gcd(ll a, ll b) {return b ? gcd(b, a % b) : a;}
typedef struct node {
    int arr[MAXSIZE];
    int length;
}sqlist;
//1.
bool f1(sqlist &L, int &e) {
    if(L.length < 1) {
        return false;
    }
    int pos = 0;
    e = L.arr[0];
    for(int i = 0; i < L.length; i++) {
        if(L.arr[i] < e) {
            e = L.arr[i];
            pos = i;
        }
    }
    L.arr[pos] = L.arr[L.length - 1];
    L.length--;
    return true;
} 
//2.
bool f2(sqlist &L) {
    if(L.length < 1) {
        return false;
    }
    for(int i = 0; i < L.length / 2; i++) { // 折半
        int tmp = L.arr[i];
        L.arr[i] = L.arr[L.length - 1 - i];
        L.arr[L.length - 1 - i] = tmp;
    }
    return true;
}
//3. 统计不等于k的
bool f3(sqlist &L, int k) {
    if(L.length < 1) {
        return false;
    }
    int cnt = 0;
    for(int i = 0; i < L.length; i++) {
        if(L.arr[i] != k) {
            L.arr[cnt] = L.arr[i];
            cnt++;
        }
    }
    L.length = cnt;
    return true;
}
//3.统计等于k的 然后移动
bool f3_2(sqlist &L, int k) {
    if(L.length < 1) {
        return false;
    }
    int cnt = 0;
    for(int i = 0; i < L.length; i++) {
        if(L.arr[i] == k) {
            cnt++;
        } else {
            L.arr[i - cnt] = L.arr[i];
        }
    }
    L.length = L.length - cnt;
    return true;
}
int main(void) {
    IOS
    system("pause");
    return 0;
}