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
    int coef, expn;
    struct node *next;
}PolyNode, *Polynomial;
Polynomial read() {
    Polynomial L;
    PolyNode *s, *r;
    int n, c, e;
    L = NULL;
    r = L;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d%d", &c, &e);
        s = (PolyNode*)malloc(sizeof(PolyNode));
        s -> coef = c;
        s -> expn = e;
        if(L == NULL) {
            L = s;
            r = s;
            continue;
        }
        r -> next = s;
        r = s;
        printf("%d ### %d\n", r -> coef, r -> expn);
    }
    r -> next = NULL;
    return L;
}
Polynomial AddPolynomial(Polynomial p1, Polynomial p2) {
    Polynomial p3;
    PolyNode *tmp1, *tmp2, *r;
    if(!p1) {
        return p2;
    }
    if(!p2) {
        return p1;
    }
    p3 = NULL;
    tmp1 = p1;
    tmp2 = p2;
    r = p3;
    while(tmp1 && tmp2) {
        if(tmp1 -> expn > tmp2 -> expn) {
            
        }
    }

}
void Print(Polynomial L) {
    PolyNode *s = (PolyNode*)malloc(sizeof(PolyNode));
    s = L;
    while(s) {
        
        printf("coef:%d    expn:%d\n", s -> coef, s -> expn);

        s = s -> next;

    }
}
int main(void) {
    IOS
    Polynomial p, q;
    p = read();
    q = read();
    cout << "First:" << endl;
    Print(p);
    cout << "Second:" << endl;
    Print(q);
    system("pause");
    return 0;
}