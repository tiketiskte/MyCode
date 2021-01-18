/**
* Copyright(c)
* Author : tiketiskte
队列的顺序实现
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
const int MAXN = 100 + 5;
typedef struct node {
    int data[MAXN];
    int front, rear;
}sqQueue;
void InitSqQueue(sqQueue &q) {
    memset(q.data, 0, sizeof(q.data));
    q.front = q.rear = 0;
}
bool Isempty(sqQueue q) {
    if(q.rear == q.front) {
        return true;
    } else {
        return false;
    }
}
bool Isfull(sqQueue q) {
    if((q.rear + 1) % MAXN == q.front) {
        return true;
    } else {
        return false;
    }
}
bool PushSqQueue(sqQueue &q, int e) {
    if(Isfull(q)) {
        return false;
    }
    q.data[q.rear] = e;
    q.rear = (q.rear + 1) % MAXN;
    return true;
}
bool PopSqQueue(sqQueue &q, int &e) {
    if(Isempty(q)) {
        return false;
    }
    e = q.data[q.front];
    q.front = (q.front + 1) % MAXN;
    return true;
}

int main(void) {
    IOS
    int n, e, x;
    sqQueue q;
    InitSqQueue(q);
    if(Isempty(q)) {
        cout << "The queue is empty!" << endl;
    } else {
        cout << "The queue isn't empty!" << endl;
    }
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> x;
        PushSqQueue(q, x);
    }
    if(Isempty(q)) {
        cout << "The queue is empty!" << endl;
    } else {
        cout << "The queue isn't empty!" << endl;
    }
    for(int i = 0; i < n; i++) {
        PopSqQueue(q, e);
        cout << i << ":" << e << endl;
    }
    if(Isempty(q)) {
        cout << "The queue is empty!" << endl;
    } else {
        cout << "The queue isn't empty!" << endl;
    }
    cout << endl;
    system("pause");
    return 0;
}
