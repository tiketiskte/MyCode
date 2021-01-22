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

stack <char> s;
string str;
bool solve() {
    for(int i = 0; i < SZ(str); i++) {
        if(str[i] == '(' || str[i] == '[' || str[i] == '{') {
            s.push(str[i]);
        } else {
            if(s.empty()) {
                return false;
            }
            char tmp = s.top();
            s.pop();
            if(str[i] == ')' && tmp != '(') {
                return false;
            }
            if(str[i] == ']' && tmp != '[') {
                return false;
            }
            if(str[i] == '}' && tmp != '{') {
                return false;
            }
        }
    }
    if(!s.empty()) {
        return false;
    } else {
        return true;
    }
}
int main(void) {
    IOS
    cin >> str;
    bool ans = solve();
    if(ans) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    system("pause");
    return 0;
}
