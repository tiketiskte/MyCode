/**
* Copyright(c)
* Author : tiketiskte
**/
#include <bits/stdc++.h>
#define IOS {ios::sync_with_stdio(false);cin.tie(0);}
#define ll long long
#define SZ(X) (int)X.size()
#define INF 0x3f3f3f3f

using namespace std;

const int maxn = 15000 + 5;
struct node {
    int x, y;
    bool operator  < (const node & a) const {
        if(x == a.x) {
            return y < a.y;
        }
        return x < a.x;
    }
};
int N, n;
multiset<node>ms;
multiset<node>::iterator it;
int main()
{
   IOS
   cin >> N;
   for(int Case = 1; Case <= N; Case++) {
       if(Case != 1) {
           cout << endl;
       }
       cout << "Case #" << Case << ":" << endl;
       cin >> n;
       ms.clear();
       for(int i = 0; i < n; i++) {
           node tmp;
           cin >> tmp.x >> tmp.y;
           it = ms.lower_bound(tmp);
           if(it == ms.begin() || (--it) -> y >= tmp.y) {
               ms.insert(tmp);
               it = ms.upper_bound(tmp);
               while(it != ms.end() && it -> y >= tmp.y) {
                   ms.erase(it++);
               }
           }
           cout << ms.size() << endl;
       }
   }
//    system("pause");
   return 0;
}
/*
4
1
100 200
2
100 200
101 202
2
100 200
200 100
5
11 20
20 10
20 10
100 20
1 1
*/