#include <iostream>
#define IOS {ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);}
using namespace std;
typedef struct Lnode {
    int data;
    struct Lnode *next;
}Lnode, *Linklist;
Linklist Createlinklist1(Linklist &L) {
    Lnode *s;
    int x;
    L = (Linklist)malloc(sizeof(Lnode));
    L->next = NULL;
    cout << "Please input your element:" << endl;
    for(int i = 1; i <= 5; i++) {
        cin >> x;
        s = (Lnode *)malloc(sizeof(Lnode));
        s -> data = x;
        s -> next = L -> next;
        L -> next = s;
    }
    return L;
}
Linklist Createlinklist2(Linklist &L) {
    Lnode *s, *last;
    int x;
    L = (Linklist)malloc(sizeof(Lnode));
    L -> next = NULL;
    last = L;
    for(int i = 1; i <= 5; i++) {
        s = (Lnode*)malloc(sizeof(Lnode));
        cin >> x;
        s -> data = x;
        last -> next = s;
        last = s;
    }
    last -> next = NULL;
    return L;   
}
void Find1(Linklist L, int pos, int &ans) {
    Lnode *tmp = L -> next;
    int j = 1;
    while(tmp && j < pos) {
        tmp = tmp -> next;
        j++;
    }
    ans = tmp -> data;
}
void Find2(Linklist L, int ans, int &pos) {
    Lnode *tmp = L -> next;
    pos = 1;
    while(tmp && tmp -> data != ans) {
        tmp = tmp ->next;
        pos++;
    }
}
void PrintLinklist(Linklist L) {
    cout << "This Linklist element is:" << endl;
    Lnode *tmp = L -> next;
    while(tmp != NULL) {
        cout << tmp -> data << " ";
        tmp = tmp -> next;
    } 
    cout << endl;
}
int main(void) {
    IOS
    Linklist L;
    int x;
    // Createlinklist1(L);
    Createlinklist2(L);
    PrintLinklist(L);
    Find1(L, 2, x);
    cout << "Find1 ans:" << x << endl;
    Find2(L, 14, x);
    cout << "Find2 pos:" << x << endl;
    system("pause");
    return 0;
}