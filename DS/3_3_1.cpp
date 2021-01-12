/**
用不带头链表实现栈 主要参考链表代码的头插法 
是一种只在头部操作的数据结构
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

typedef struct node {
    int data;
    struct node *next;
} LinkStackNode, *LinkStack;

void InitLinkStack(LinkStack &s) {
    s = NULL;
}
bool Isempty(LinkStack s) {
    if(s == NULL) {
        return true;
    } else {
        return false;
    }
}
bool Pushstack(LinkStack &s, int e) {
    LinkStackNode *tmp = (LinkStackNode*)malloc(sizeof(LinkStackNode));
    if(tmp == NULL) {
        return false;
    }
    tmp -> data = e;
    tmp -> next = s -> next;
    s -> next = tmp;
    return true;
}
int main(void) {
    IOS
    system("pause");
    return 0;
}
