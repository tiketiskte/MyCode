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

int n;
/* void solve() {
    while(n >= 10) {
        int ans = 0;//！！！
        while(n) {
            ans += n % 10;
            n /= 10;
        }
        n = ans;
        //cout << "###1" << n << endl;
    }
    cout << n << endl;
} */
int get_sum(int x) {
    int cnt = 0;
    while(x) {
        cnt += x % 10;
        x /= 10;
    }
    return cnt;
}
void solve() {
    cin >> n;
    while(n >= 10) {
        n = get_sum(n);
    }
    cout << n << endl;
    
}
int main()
{
   IOS
   solve();
   system("pause");
   return 0;
}
