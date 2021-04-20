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

const int MAXN = 100 + 5;
typedef struct StringNode {
    char ch[MAXN];
    int length;
}String;
int n, m;
char qwq;
int StrCompare(String a, String b) {
    for(int i = 1; i <= a.length && i <= b.length; i++) {
        if(a.ch[i] != b.ch[i]) {
            return a.ch[i] - b.ch[i];
        }
    }
    return a.length - b.length;
}
void SubString(String &Sub, String S, int pos, int len) {
    if(pos + len - 1 > S.length) {
        return ; 
    }
    for(int i = pos; i < len; i++) {
        Sub.ch[i - pos + 1] = S.ch[i]; 
    }
    Sub.length = len;
}
int main(void) {
    IOS
    String S1, S2;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> qwq;
        S1.ch[i] = qwq;
    }
    S1.length = n;
    for(int i = 1; i <= m; i++) {
        cin >> qwq;
        S2.ch[i] = qwq;
    }
    S2.length = m;
    int x = StrCompare(S1, S2);
    cout << x << endl;
    system("pause");
    return 0;
}
