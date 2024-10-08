#include <bits/stdc++.h>
#define IOS {iod::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
using namespace std;
const int MAXN = 1000;
string s;
int ANS[MAXN];
string qwq[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
void solve() {
    cin >> s;
    int cnt = 0, ans = 0;
    while(s[cnt] != '\0') {
        ans += s[cnt] - '0';
        cnt++;
    }
    int i = 0;
    
    while(ans != 0) {
        ANS[i] = ans % 10;
        ans /= 10;
        i++;
    }
    for(int k = i - 1; k > 0; k--) {
        cout << qwq[ANS[k]] << " "; 
    }
    cout << qwq[ANS[0]] << endl;
}
int main(void) {
//     IOS
    solve();
    return 0;
}