// 静态布局
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
    L.length = 0; // Init_length 
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
void Delete(sqlist &L, int pos, int &x) {
    if(pos < 1 || pos > L.length) {
        cout << "Illegal location!" << endl;
        return ;
    }
    x = L.arr[pos - 1];
    for(int i = pos; i < L.length; i++) {
        L.arr[i - 1] = L.arr[i];
    }
    L.length--;
}
bool Find(sqlist L, int x, int &pos) {
    if(L.length == 0) {
        return false;
    }
    pos = -1;
    for(int i = 0; i < L.length; i++) {
        if(L.arr[i] == x) {
            pos = i + 1;
            break;
        }
    }
    if(pos == -1) {
        return false;
    } else {
        return true;
    }
}
int main(void) {
    IOS
    sqlist L;
    int ans1, ans2;
    Init(L);
    print(L);
    Insert(L, 2, 521);
    print(L);
    Delete(L, 3, ans1);
    cout << "Delete's answer:" << ans1 << endl;
    print(L);
    Find(L, 105, ans2);
    cout << "Find's answer:" << ans2 << endl;
    system("pause");
    return 0;
}