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

const int N = 1e5 +5;
int t, n;
int cnt;
char s[N];
void solve() {
    cin >> n;
    cin >> s + 1;
    for(int i = 1; i < n; i++) {
        if(s[i] == '1' && s[i + 1] == '0') {
            cnt++;
            for(int j = i; j < n; j++) {
                s[i] = s[i + 1];
            }
        }
    }
    for(int i = 1; i <= n - cnt; i++) {
        cout << s[i];
    }
    cout << endl;
}
int main()
{
   IOS
   cin >> t;
   while(t--) {
       solve();
   }
   system("pause");
   return 0;
}
