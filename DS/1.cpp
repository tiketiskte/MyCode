// 顺序表静态分配
#include <iostream>
#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
using namespace std;
const int SIZE = 10;
const int MAXSIZE = 20;
typedef struct node {
    int arr[MAXSIZE];
    int length;
}sqlist;
void Init(sqlist& L) {
    L.length = 0; // 初始化length 或者定义L为全局变量
    for(int i = 0; i < SIZE; i++) {
        L.arr[i] = i + 100; 
        L.length++;
    }
}
void print(sqlist L) {
    for(int i = 0; i < L.length; i++) {
        cout << L.arr[i] << " ";
    }
    cout << endl;
}
bool Insert(sqlist &L, int pos, int x) {
    if(pos < 1 || pos > L.length + 1) {
        //In the sequence table, ensure that the sequence table arrangement relationship does not allow empty elements between two elements
        //L.length + 1 Insert in the last element
        return false;
    }
    if(L.length >= MAXSIZE) {
        return false;
    }
    for(int i = L.length; i >= pos; i--) {
        L.arr[i] = L.arr[i - 1];
    }
    L.arr[pos - 1] = x;
    L.length++;
    return true;
}
int main(void) {
    IOS
    sqlist L;
    Init(L);
    print(L);
    Insert(L, 2, 521);
    print(L);
    system("pause");
    return 0;
}