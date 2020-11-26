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
typedef struct node {
    int data;
    struct node *next;
}Lnode, *LinkList;
//不带头结点的链表初始化
bool InitList1(LinkList &L) {
    L = NULL;
    return true;
}
//不带头结点的链表判空操作
bool EmptyList1(LinkList L) {
    if(L == NULL) {
        return true;
    }
    return false;
}
//带头结点的链表初始化
bool InitList2(LinkList &L) {
    L = (Lnode *)malloc(sizeof(Lnode));
    if(L == NULL) {
        return false;
    }
    L -> next = NULL;
    return true;
}
//带头结点的链表判空操作
bool EmptyList2(LinkList L) {
    if(L -> next == NULL) {
        return true;
    }
    return false;
}
//带头结点的链表插入操作
bool InsertLinkList1(LinkList &L, int pos, int e) {
    if(pos < 1) {
        return false;
    }
    Lnode *p;
    p = L;
    int cnt = 0;
    while(p -> next != NULL && cnt < pos - 1) {
        p = p -> next;
        cnt++;
    }
    if(p == NULL) {
        return false;
    }
    Lnode *s = (Lnode*)malloc(sizeof(Lnode));
    s -> data = e;
    s -> next = p -> next;
    p -> next = s;
    return true;
}
//不带头节点的链表插入操作
bool InsertLinkList2(LinkList &L, int pos, int e) {
    if(pos < 1) {
        return false;
    }
    if(pos == 1) {
        Lnode * s = (Lnode*)malloc(sizeof(Lnode));
        s -> data = e;
        s -> next = L;
        L = s;
        return true;
    }
    Lnode *p;
    int cnt = 1;
    p = L;
    while(p -> next != NULL && cnt < pos - 1) {
        p = p -> next;
        cnt++;
    }
    if(p == NULL) {
        return false;
    }
    Lnode *s = (Lnode*)malloc(sizeof(Lnode));
    s -> data = e;
    s -> next = p -> next;
    p -> next = s;
    return true;
}
int main(void) {
    IOS
    LinkList L;
    InitList2(L);
    cout << EmptyList2(L) << endl;
    system("pause");
    return 0;
}
