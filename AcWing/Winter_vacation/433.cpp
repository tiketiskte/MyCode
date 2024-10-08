/**
* Copyright(c)
* Author : tiketiskte
**/
#include <bits/stdc++.h>
using namespace std;
#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define rep(i, a, n) for(int i = a; i < n; i++)
#define per(i, a, n) for(int i = n - 1; i >= a; i--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sqr(x) (x) * (x)
#define SZ(X) (int)X.size()
#define all(x) (x).begin(), (x).end()
#define INF 0x3f3f3f3f
typedef long long ll;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <double, double> PDD;

ll gcd(ll a, ll b) {return b ? gcd(b, a % b) : a;}

string s;
int ans;
int main(void) {
    IOS
    cin >> s;
    for(int i = 0, j = 1; i <= (int)s.size() - 2; i++) {
        if(s[i] >= '0' && s[i] <= '9') {
            ans += (s[i] - '0') * j;
            j++;
        }
    }
    ans = ans % 11;
    if(((s[s.size() - 1] - '0') == ans) || (s[s.size() - 1] == 'X' && ans == 10)) {
        cout << "Right" << endl;
    } else {
        for(int i = 0; i <= (int)s.size() - 2; i++) {
            cout << s[i];
        }
        if(ans > 9) {
            cout << 'X' << endl;
        } else {
            cout << ans << endl;
        }
    }
    system("pause");
    return 0;
}
