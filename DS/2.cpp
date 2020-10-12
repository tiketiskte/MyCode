// 顺序表动态分配
#include <iostream>
#include <cstdlib>
#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
using namespace std;

const int MAXSIZE = 10;
typedef struct List {
    int *arr;
    int maxsize;
    int length;
}sqlist;
void Init(sqlist &L) {
    L.arr = (int*)malloc(sizeof(int) * MAXSIZE);
    L.maxsize = MAXSIZE;
    L.length = 0;
    for(int i = 0; i < 10; i++) {
        L.arr[i] = i + 100;
        L.length++;
    }
}
void IncreaseLength(sqlist &L, int inc_length) {
    int *p = L.arr;
    L.arr = (int*)malloc(sizeof(int) * (MAXSIZE + inc_length));
    L.maxsize = MAXSIZE + inc_length;
    for(int i = 0; i < L.length; i++) {
        L.arr[i] = p[i];
    }
    free(p);
}
void IncreaseElem(sqlist &L) {
    for(int i = L.length; i < L.maxsize; i++) {
        L.arr[i] = 2020;
        L.length++;
    }
}
void print(sqlist L) {
    for(int i = 0; i < L.maxsize; i++) {
        cout << L.arr[i] << " ";
    }
    cout << endl;
}
int main(void) {
    IOS
    sqlist L;
    Init(L);
    IncreaseLength(L, 10); 
    cout << L.maxsize << endl;
    IncreaseElem(L);
    print(L);
    system("pause");
    return 0;
}