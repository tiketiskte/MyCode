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
char qwq;
int n, m, Next[MAXN];
void get_next(String S, int next[]) {
    int i = 1, j = 0;
    next[1] = 0;
    while(i < S.length) {
        if(j == 0 || S.ch[i] == S.ch[j]) {
            ++i, ++j;
            next[i] = j;
        } else {
            j = next[j];
        }
    }
}
int Index_KMP(String a, String b, int next[]) {
    int i = 1, j = 1;
    while(i <=  a.length && j <= b.length) {
        if(j == 0 || a.ch[i] == b.ch[j]) {
            ++i, ++j;
        } else {
            j = next[j];
        }
    }
    if(j > b.length) {
        return i - b.length;
    } else {
        return 0;
    }
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
    get_next(S2, Next);
    int ans = Index_KMP(S1, S2, Next);
    cout << ans << endl;
    system("pause");
    return 0;
}
/*
Input:
10 5
qwqabcdezp
abcde
Output:
4
*/