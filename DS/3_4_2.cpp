/**
队列的链式实现 带头结点
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

typedef struct node1 {
    int data;
    struct node1 *next;
}LinkNode;
typedef struct node2 {
    LinkNode *front, *rear;
}LinkQueue;
void InitLinkQueue(LinkQueue &q) {
    q.front = q.rear = (LinkNode*)malloc(sizeof(LinkNode));
    q.front->next = NULL;
}
bool IsEmpty(LinkQueue q) {
    if(q.front -> next == NULL) {
        return true;
    } else {
        return false;
    }
}
void PushLinkQueue(LinkQueue &q, int x) {
    LinkNode *s = (LinkNode*)malloc(sizeof(LinkNode));
    s -> data = x;
    s -> next = NULL;
    q.rear -> next = s;
    q.rear = s;
}
bool PopLinkQueue(LinkQueue &q, int &e) {
    if(IsEmpty(q)) {
        return false;
    }
    LinkNode *s = q.front -> next;
    e = s -> data;
    q.front -> next = s -> next; // front 指针指向的节点的next 更新到 front 指针指向的节点的下一个节点
    if(q.rear == s) {
        q.rear = q.front;
    }
    free(s);
    return true;
}
int main(void) {
    IOS
    int n, e, x;
    LinkQueue Q;
    InitLinkQueue(Q);
    if(IsEmpty(Q)) {
        cout << "The queue is empty!" << endl;
    } else {
        cout << "The queue isn't empty!" << endl;
    }
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> e;
        PushLinkQueue(Q, e);
    }
    if(IsEmpty(Q)) {
        cout << "The queue is empty!" << endl;
    } else {
        cout << "The queue isn't empty!" << endl;
    }
    for(int i = 0; i < n; i++) {
        PopLinkQueue(Q, x);
        cout << i << ": " << x << endl;
    }
    if(IsEmpty(Q)) {
        cout << "The queue is empty!" << endl;
    } else {
        cout << "The queue isn't empty!" << endl;
    }
    system("pause");
    return 0;
}
