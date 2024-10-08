/**
用顺序表实现栈 栈顶指针设置为0的情形
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
ll gcd(ll a, ll b) {return b ? gcd(b, a % b) : a;}

const int MAXNSIZE = 10;
typedef struct node {
    int data[MAXNSIZE];
    int top;
}sqstack;
void Initsqstack(sqstack &s) {
    s.top = 0;
}
bool Isempty(sqstack s) {
    if(s.top == 0) {
        return true;
    } else {
        return false;
    }
}
bool Isfull(sqstack s) {
    if(s.top == MAXNSIZE) {
        return true;
    } else {
        return false;
    }
}
void Pushstack(sqstack &s, int e) {
    if(Isfull(s)) {
        cout << "This stack is full" << endl;
        return ;
    } else {
        s.data[s.top++] = e;
    }
} 
void Popstack(sqstack &s, int &e) {
    if(Isempty(s)) {
        cout << "The stack is empty" << endl;
    } else {
        e = s.data[--s.top];
    }
}
int main(void) {
    IOS
    sqstack s;
    int n, x, e;
    Initsqstack(s);
    if(Isempty(s)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> x;
        Pushstack(s, x);
    }
    if(Isempty(s)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    for(int i = 0; i < n; i++) {
        Popstack(s, e);
        cout << i << ":" << e << endl;
    }
    if(Isempty(s)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    system("pause");
    return 0;
}
