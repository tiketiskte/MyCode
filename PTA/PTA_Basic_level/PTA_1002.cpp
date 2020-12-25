/**
* Copyright(c)
* Author : tiketiskte
**/
#include <bits/stdc++.h>
#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define rep(i, a, n) for(int i = a; i < n; i++)
#define per(i, a, n) for(int i = n - 1; i >= a; i--)
#define ll long long
#define PII pair<int, int>
#define PLL pair<ll, ll>
#define PDD pair<double, double>
#define sqr(x) (x) * (x)
#define SZ(X) (int)X.size()
#define all(x) (x).begin(), (x).end()
#define INF 0x3f3f3f3f

using namespace std;
ll gcd(ll a, ll b) {return b ? gcd(b, a % b) : a;}

string s;
int ANS[100];
string qwq[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
void solve() {
    cin >> s;
    int ans = 0;
    for(int i = 0; s[i] != '\0'; i++) {
        ans += s[i] - '0';
    }
    // cout << ans << endl;
    int cnt = 0;
    while(ans != 0) {
        ANS[cnt] = ans % 10;
        ans /= 10;
        cnt++;
    }
    int k = cnt - 1;
    for(int j = k; j > 0; j--) {
        cout << qwq[ANS[j]] << " ";
    }
    cout << qwq[ANS[0]] << endl;
}
int main(void) {
    IOS
    solve();
    system("pause");
    return 0;
}
