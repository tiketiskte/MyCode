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
ll gcd(ll a, ll b) {return b ? gcd(b, a % b) : a;}

const int MAXN = 100;
typedef struct Lnode {
    int data;
    struct Lnode *next;
}Lnode, *Linklist;

typedef struct node {
    int a[MAXN];
    int top[2];
}stk;
stk s;
//1.判断合法序列
bool f1(string s) {
    int cnt = 0, i = 0, j = 0;
    while(s[cnt] != '\0') {
        if(s[cnt] == 'I') {
            i++;
        } else {
            j++;
        }
        cnt++;
        if(i < j) {
            return false;
        }
    }
    if(i != j) {
        return false;
    } else {
        return true;
    }
}
//2.是否中心对称
bool f2(Linklist L, int n) {
    int i;
    char s[n / 2];
    Lnode *p = L -> next;
    for(i = 0; i < n / 2; i++) {
        s[i] = p -> data;
        p = p -> next;
    }
    i--;
    if(n % 2 == 1) {
        p = p -> next;
    }
    while(p != NULL && p -> data == s[i]) {
        i--;
        p = p -> next;
    }
    if(i == -1) {
        return true;
    } else {
        return false;
    }
} 
//3.共享栈
void f3_Init(stk s) {
    memset(s.a, 0, sizeof(s.a));
    s.top[0] = -1, s.top[1] = MAXN; 
}
bool f3_push(int flag, int x) {
    if(flag < 0 || flag > 1) {
        cout << "stk error" << endl;
        return false;
    }
    if(s.top[1] - s.top[0] == 1) {
        cout << "stk is full" << endl;
        return false;
    }
    switch(flag) {
        case 0: s.a[++s.top[0]] = x; return true; break;
        case 1: s.a[--s.top[1]] = x; return true;
    }
    return true;
}
bool f3_pop(int flag, int &e) {
    if(flag < 0 || flag > 1) {
        cout << "stk error" << endl;
        return false;
    }
    switch(flag) {
        case 0:
            if(s.top[0] == -1) {
                cout << "stk is empty" << endl;
                return false; 
            } else {
                e = s.a[s.top[0]--];
                return true;
            }
            break;
        case 1:
            if(s.top[1] == MAXN) {
                cout << "stk is empty" << endl;
                return false; 
            } else {
                e = s.a[s.top[1]++];
                return true;
            }
            break;
    }
    return true;
}
int main(void) {  
    IOS
    f3_Init(s);
    int e;
    for(int i = 0; i < 5; i++) {
        f3_push(0, i);
    }
    for(int i = 0; i < 5; i++) {
        f3_push(1, 100 + i);
    }
    for(int i = 0; i < 5; i++) {
        f3_pop(0, e);
        cout << "answer1:" << e << endl;
    }
    for(int i = 0; i < 5; i++) {
        f3_pop(1, e);
        cout << "answer2:" << e << endl;
    }    
    system("pause");
    return 0;
}
