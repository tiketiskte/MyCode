/**
队列的链式实现 不带头结点
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

typedef struct node1 {
    int data;
    struct node1 *next;
}LinkNode;
typedef struct node2 {
    LinkNode *front, *rear;
}LinkQueue;
void InitQueue(LinkQueue &q) {
    q.front = q.rear = NULL;
}
bool IsEmpty(LinkQueue q) {
    return q.front == NULL;
}
void PushLinkQueue(LinkQueue &q, int x) {
    LinkNode *s = (LinkNode*)malloc(sizeof(LinkNode));
    s -> data = x;
    s -> next = NULL;
    if(q.front == NULL) {
        q.front = s;
        q.rear = s;
    } else {
        q.rear -> next = s;
        q.rear = s;
    }
}
bool PopLinkQueue(LinkQueue &q, int &e) {
    if(IsEmpty(q)) {
        return true;
    }
    LinkNode *s = q.front;
    e = s -> data;
    q.front = s -> next;
    if(q.rear == s) {
        q.front = NULL;
        q.rear = NULL;
    }
    free(s);
    return true;
}
int main(void) {
    IOS
    int n, x, e;
    LinkQueue Q;
    InitQueue(Q);
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
