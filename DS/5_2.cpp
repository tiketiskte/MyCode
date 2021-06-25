/**
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

const int MAXN = 4;
typedef struct BiTnode {
    char data;
    struct BiTnode *lchild, *rchild;
}BiTNode, *BiTree;
int n;
char ch[MAXN];
void NLR(BiTree T) {
    if(T != NULL) {
        cout << T->data;
    }
    NLR(T->lchild);
    NLR(T->rchild);
}
void BiTBuild() {
    
}
int main(void) {
    IOS
    BiTree bitree;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> ch;
        cout << ch << endl;
    }
    NLR(bitree);
    system("pause");
    return 0;
}
