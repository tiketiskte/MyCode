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

int B;
char get(int a) {
    if(a <= 9) {
        return a + '0';
    } else {
        return a - 10 + 'A';
    }
}
string base(int x, int b) {
    string num;
    while(x) {
        num += get(x % b);
        x /= b;
    }
    reverse(num.begin(), num.end());
    return num;
}
bool check(string res) {
    for(int i = 0, j = res.size() - 1; i <= j; i++, j--) {
        if(res[i] != res[j]) {
            return false;
        }
    }
    return true;
}
int main(void) {
    IOS
    cin >> B;
    for(int i = 1; i <= 300; i++) {
        string ans = base(i * i, B);
        if(check(ans)) {
            cout << base(i, B) << " " << ans << endl;
        }
    }
    system("pause");
    return 0;
}
