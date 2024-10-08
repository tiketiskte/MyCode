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

const int maxn = 1e5 + 5;
int t, n, p[maxn];
void solve() {
    vector<int> v;
    vector<int>::iterator it;
    v.clear();
    memset(p, 0, sizeof(p));
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    v.push_back(p[1]);
    for(int i = 2; i <= n - 1; i++) {
        if((p[i] >= p[i - 1] && p[i] >= p[i + 1]) || (p[i] <= p[i - 1] && p[i] <= p[i + 1])) {
            v.push_back(p[i]);
        }
    }
    v.push_back(p[n]);
    cout << v.size() << endl;
    for(it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    /* for(auto c : v) {
        cout << c << endl;
    } */
    cout << endl;
}
int main()
{
   IOS
   cin >> t;
   while(t--) {
       solve();
   }
//    system("pause");
   return 0;
}
