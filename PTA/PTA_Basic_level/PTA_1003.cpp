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


const int MAXN = 100 + 5;
int n;
string s;
inline bool qwq1() {
    int a = 0, b = 0, c = 0, other = 0;
    int pos1 = 0, pos2 = 0;
    int len = s.length();
    for(int i = 0; s[i] != '\0'; i++) {
        if(s[i] == 'P') {
            a++;
            pos1 = i;
        } else if(s[i] == 'T') {
            b++;
            pos2 = i;
        } else if(s[i] == 'A') {
            c++;
        } else {
            other++;
        }
    }
    if(other > 0 || a != 1 || b != 1 || len < 2 || (pos1 > pos2)) {
        return false;
    } else {
        return true;
    }
}
inline bool qwq2 () {
    int x = 0, y = 0, z = 0;
    int p1 = 0, p2 = 0;
    for(int i = 0; s[i] != '\0'; i++) {
        if(s[i] == 'P') {
            break;
            p1 = i;
        } else {
            x++;
        }
    }
    for(int i = p1; s[i] != '\0'; i++) {
        if(s[i] == 'T') {
            break;
            p2 = i;
        } else {
            y++;
        }
    }
    for(int i = p2; s[i] != '\0'; i++) {
       z++;
    }
    if(x * y == z) {
        return true;
    } else {
        return false;
    }
}
void solve() {
    cin >> s;
    if(qwq1() && qwq2()) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}
int main(void) {
    IOS
    cin >> n;
    while(n--) {
        solve();
    }
    system("pause");
    return 0;
}
