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

#define ElemType char
ll gcd(ll a, ll b) {return b ? gcd(b, a % b) : a;}

const int MAXN = 4;
typedef struct BiTnode {
    ElemType data;
    struct BiTnode *lchild, *rchild;
}BiTNode, *BiTree;
int n;
void Visit(BiTree T) {
    cout << T -> data << " ";
}
void PreOrderBuildBiTree(BiTree &T) {
    char ch;
    cin >> ch;
    if(ch == '#') {
        T = NULL;
        return ;
    } else {
        T = (BiTree)malloc(sizeof(BiTNode));
        T -> data = ch;
        // cout << "###:" << ch << endl;
        PreOrderBuildBiTree(T->lchild);
        PreOrderBuildBiTree(T->rchild);
    }
    return ;
}
void NLR(BiTree T) {
    if(T) {
        Visit(T);
        NLR(T->lchild);
        NLR(T->rchild);
    }
}
void LNR(BiTree T) {
    if(T) {
        LNR(T->lchild);
        Visit(T);
        LNR(T->rchild);
    }
}
void LRN(BiTree T) {
    if(T) {
        LRN(T->lchild);
        LRN(T->rchild);
        Visit(T);
    }
}
int main(void) {
    IOS
    BiTree bitree;
    PreOrderBuildBiTree(bitree);
    cout << "The PreOrder is:" << endl;
    NLR(bitree);
    cout << endl;
    cout << "The InOrder is:" << endl;
    LNR(bitree);
    cout << endl;
    cout << "The PostOrder is:" << endl;
    LRN(bitree);
    cout << endl;
    system("pause");
    return 0;
}
/*
Input:
AB#C##DE##FG#H##I## 
PreOrder_Build
BiTree:
            A
        B       D
            C   E   F
                   G   I
                     H 

OutPut:
PreOrder:ABCDEFGHI
InOrder:BCAEDGHFI
PostOrder:CBEHGIFDA
*/