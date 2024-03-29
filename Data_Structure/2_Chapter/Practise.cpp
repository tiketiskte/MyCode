//线性表中顺序表的操作及实现
/*
1.InitList(&L):初始化表.构造一个空的线性表
2.Length(L):求表长.返回线性表L的长度，即L中数据元素的个数
3.LocateElem(L, e):按值查找操作.在表L中查找具有给定关键字值的元素
4.GetElem(L, i):按位查找操作.获取表L中第i个位置的元素的值
5.ListInsert(&L, i, e):插入操作.在表L中的第i个位置上插入指定元素e
6.ListDelete(&L, i, &e):删除操作.删除表L中第i位置的元素 并用e返回删除元素的值
7.PrintList(L):输出操作.按前后顺序输出线性表L的所有元素值
8.Empty(L):判空操作.若L为空表，则返回true 否则返回false
9.DestroyList(&L):销毁操作.销毁线性表 并释放线性表L所占用的内存空间
*/
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

const int MAXN = 100 + 5;
const int InitSize = 100;
const int error = -1;
int n;
typedef struct node {
    //int data[MAXN];
    int *data;
    int length;
}SqList;
//1.InitList(&L):初始化表.构造一个空的线性表
void InitList(SqList &L) {
    L.data = new int[InitSize];
    L.length = 0;
    for(int i = 0; i < n; i++) {
        L.data[i] = i + 200;
        L.length++;
    }
}
//2.Length(L):求表长.返回线性表L的长度，即L中数据元素的个数 
int Length(SqList L) {
    return L.length;
}
//3.LocateElem(L, e):按值查找操作.在表L中查找具有给定关键子值的元素
int LocateElem(SqList L, int e) {
    for(int i = 0; i < n; i++) {
        if(L.data[i] == e) {
            return i + 1;
        }
    }
    return error;
}
//4.GetElem(L, i):按位查找操作.获取表L中第i个位置的元素的值
int GetElem(SqList L, int i) {
    int cnt = 1;//cnt为元素位置 不是下标
    //令cnt = 1,从第1个位置开始 cnt = i即找到指定元素位置,下标-1即为元素
    while(cnt < i) {
        cnt++;
    }
    return L.data[cnt - 1];
}
//5.ListInsert(&L, i, e):插入操作.在表L中的第i个位置上插入指定元素e
bool ListInsert(SqList &L, int i, int e) {
    if(i <= 0 || i > L.length + 1) {
        return false;
    }
    if(i >= InitSize) {
        return false;
    }
    for(int j = L.length; j >= i; j--) {
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = e, L.length++;
    return true;
}
//6.ListDelete(&L, i, &e):删除操作.删除表L中第i位置的元素 并用e返回删除元素的值
bool ListDelete(SqList &L, int i, int &e) {
    if(i <= 0 || i > L.length) {
        return false;
    }
    e = L.data[i - 1];
    for(int j = i; j < L.length; j++) {
        L.data[j - 1] = L.data[j];
    }
    L.length--;
    return true;
}
//7.PrintList(L):输出操作.按前后顺序输出线性表L的所有元素值
void PrintList(SqList L) {
    cout << "L's element:" << endl;
    for(int i = 0; i < L.length; i++) {
        cout << L.data[i] << " ";
    }
    cout << endl;
}
//8.Empty(L):判空操作.若L为空表，则返回true 否则返回false
bool Empty(SqList L) {
    if(L.length == 0) {
        return true;
    }
    return false;
}
//9.DestroyList(&L):销毁操作.销毁线性表 并释放线性表L所占用的内存空间
void DestroyList(SqList &L) {
    delete L.data;
    L.length = 0;   
}
int main(void) {
    IOS
    SqList L;
    int e1, e2, e3;
    int i_1;
    cout << Empty(L) << endl;
    cin >> n;
    InitList(L);
    cout << "L's length:" << Length(L) << endl;
    PrintList(L);
    cin >> e1 >> i_1;//输出查找给定关键字值的元素以及查找第i个位置的元素
    cout << "L's find locate element:" << LocateElem(L, e1) << endl;
    cout << "L's find key element:" << GetElem(L, i_1) << endl;
    cin >> e2;
    cout << ListInsert(L, 2, e2)<< endl;
    PrintList(L);
    cout << ListDelete(L, 2, e3) << endl;
    cout << e3 << endl;
    PrintList(L);
    DestroyList(L);
    cout << Empty(L) << endl;
    system("pause");
    return 0;
}
/*
input:
20
203 9
999
5
*/
