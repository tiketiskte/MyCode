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

const int maxn = 100000 + 5;
int n;
bool vis[maxn];
string s;
set<int>st;//存没有建立的文档
set<int>::iterator it;
void solve() {
    cin >> s;
    if(s[0] == 'N') {
        it = st.begin();
        vis[*it] = true;
        cout << *it << endl;
        st.erase(it);
    } else {
        int x;
        cin >> x;
        if(vis[x]) {
            cout << "Successful" << endl;
            vis[x] = false;
            st.insert(x);
        } else {
            cout << "Failed" << endl;
        }
    }
}
int main()
{
   IOS
   cin >> n;
   for(int i = 1; i < maxn; i++) {
       st.insert(i);
   }
   while(n--) {
       solve();
   }
   //system("pause");
   return 0;
}
