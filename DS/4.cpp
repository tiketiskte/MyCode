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
//带头结点的链表初始化
bool InitList2(LinkList &L) {
    L = (Lnode *)malloc(sizeof(Lnode));
    if(L == NULL) {
        return false;
    }
    L -> next = NULL;
    return true;
}
//不带头结点的链表判空操作
bool EmptyList1(LinkList L) {
    if(L == NULL) {
        return true;
    }
    return false;
}
//带头结点的链表判空操作
bool EmptyList2(LinkList L) {
    if(L -> next == NULL) {
        return true;
    }
    return false;
}
//不带头节点的链表创建操作(头插法)
LinkList CreateLinklistHead1(LinkList &L) {
    Lnode *s;
    L = NULL;
    for(int  i = 1; i <= 10; i++) {
        s = (Lnode*)malloc(sizeof(Lnode));
        s -> data = i;
        s -> next = L;
        L = s;
    }
    return L;
}
//不带头节点的链表创建操作(尾插法)
LinkList CreateLinklistTail1(LinkList &L) {
    Lnode *s, *r;
    L = NULL;
    r = L;//尾结点
    for(int i = 1; i <= 10; i++) {
        s = (Lnode*)malloc(sizeof(Lnode));
        s -> data = i;
        if(L == NULL) {
            L = s;
            r = s;
            continue;
        }
        r -> next = s;
        r = s;
    }
    if(r != NULL) {
        r -> next = NULL;
    } 
    return L;
}
//带头结点的链表创建操作(头插法)
LinkList CreateLinklistHead2(LinkList &L) {
    Lnode *s;
    L = (Lnode*)malloc(sizeof(Lnode));
    L -> next = NULL;
    for(int i = 1; i <= 10; i++) {
        s = (Lnode*)malloc(sizeof(Lnode));
        s -> data = i;
        s -> next = L -> next;
        L -> next = s;
    }
    return L;
}
//带头结点的链表创建操作(尾插法)
LinkList CreateLinklistTail2(LinkList &L) {
    Lnode *s, *r;
    L = (Lnode*)malloc(sizeof(Lnode));
    r = L;
    for(int i = 1; i <= 10; i++) {
        s = (Lnode*)malloc(sizeof(Lnode));
        s -> data = i;
        r -> next = s;
        r = s;
    }
    if(r != NULL) {
        r -> next = NULL;
    }
    return L;
}
//不带头结点的链表打印
void Display1(LinkList L) {
    cout << "Linklist:" << endl;
    Lnode *s = L;
    while(s != NULL) {
        cout << s -> data << " ";
        s = s -> next;
    }
    cout << endl;
}
//带头结点的链表打印
void Display2(LinkList L) {
    cout << "Linklist:" << endl;
    Lnode *s  = L -> next;
    while(s != NULL) {
        cout << s ->data << " ";
        s = s -> next;
    } 
    cout << endl;
}
//不带头节点的链表插入操作
bool InsertLinkList1(LinkList &L, int pos, int e) {
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
//带头结点的链表插入操作
bool InsertLinkList2(LinkList &L, int pos, int e) {
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
//不带头结点的链表查找指定位置元素
int LinklistFind1(LinkList L, int pos) {
    Lnode *s = L;
    int cnt = 1;
    if(pos < 0) {
        cout << "Illegal location" << endl;
        return -1;
    }
    while(s != NULL && cnt < pos) {
        cnt++;
        s = s -> next;
    }
    if(s) {
        return s -> data;
    } else {
        return -2;
    }
}
//带头结点的链表查找指定位置元素
int LinklistFind2(LinkList L, int pos) {
    Lnode *s = L -> next;//指向头节点
    int cnt = 1;
    if(pos < 1) {
        cout << "Illegal location" << endl;
        return -1;
    }
    while(s != NULL && cnt < pos) {
        cnt++;
        s = s -> next;
    }
    if(s) {
        return s -> data;
    } else {
        return -2;
    }
}
//不带头结点链表查找指定元素位置
int LinklistFindPos1(LinkList L, int e) {
    Lnode * s = L;
    int cnt = 1;
    while(s != NULL && s -> data != e) {
        cnt++;
        s = s -> next;
    }
    if(s) {
        return cnt;
    } else {
        return -2;
    }
}
//带头节点链表查找指定元素位置
int LinklistFindPos2(LinkList L, int e) {
    Lnode *s = L -> next;
    int cnt = 1;
    while(s != NULL && s -> data != e) {
        cnt++;
        s = s -> next;
    }
    if(s) {
        return cnt;
    } else {
        return -2;
    }
}
//求不带头结点链表长度
int LinklistLength1(LinkList L) {
    int cnt = 0;
    Lnode *s = L;
    if(L == NULL) {
        return 0;
    }
    while(s) {
        cnt++;
        s = s -> next;
    }
    return cnt;
}
//求带头结点链表长度
int LinklistLength2(LinkList L) {
    int cnt = 0;
    Lnode *s = L;
    while(s -> next != NULL) {
        cnt++;
        s = s -> next;
    }
    return cnt;
}
int main(void) {
    IOS
    LinkList L;
    InitList2(L);
    CreateLinklistTail2(L);
    Display2(L);
    cout << LinklistFindPos2(L, 7) << endl;
    // system("pause");
    return 0;
}
