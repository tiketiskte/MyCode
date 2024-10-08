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

const int MAXN1 = 1e5 + 5;
const int MAXN2 = MAXN1 * 2;
int ans, n, idx, s[MAXN1], son[MAXN2][2], id[MAXN2];
void insert(int x, int k) {
    int p = 0;
    for(int i = 20; i >= 0; i--) {
        int u = x >> i & 1;
        if(!son[p][u]) {
            son[p][u] = ++idx;
        }
        p = son[p][u];
    }
    id[p] = k;
}
int query(int x) {
    int p = 0;
    for(int i = 20; i >= 0; i--) {
        int u = x >> i & 1;
        if(son[p][!u]) {
            p = son[p][!u];
        } else {
            p = son[p][u];
        }
    }
    return id[p];
}
int main(void) {
    IOS
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> s[i];
        s[i] ^= s[i - 1];
    }
    ans = -1;
    int a, b; // 答案区间
    insert(s[0], 0);
    for(int i = 1; i <= n; i++) {
        int k = query(s[i]);
        int t = s[i] ^ s[k];
        if(t > ans) {
            ans = t;
            a = k + 1, b = i;
        }
        insert(s[i], i);
    }
    cout << ans << " " << a << " " << b << endl; 
    system("pause");
    return 0;
}
