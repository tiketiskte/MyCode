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

const int MAXN = 20000 + 5;
int n, m, a, b, q, c, d;
int fa[MAXN], Rank[MAXN];
inline void init(int n) {
    for(int i = 1; i <= n; i++) {
        fa[i] = i;
        Rank[i] = 1;
    }
}
inline int find(int x) {
    if(fa[x] == x) {
        return fa[x];
    } else {
        return find(fa[x]);
    }
}
inline void merge(int i, int j) {
    int x = find(i), y = find(j);
    if(Rank[x] <= Rank[y]) {
        fa[x] = y;
    } else {
        fa[y] = x;
    }
    if(Rank[x] == Rank[y] && x != y) {
        Rank[y]++;
    }
}
inline bool check(int i, int j) {
    if(find(i) == find(j)) {
        return true;
    } else {
        return false;
    }
}
int main(void) {
    IOS
    // scanf("%d%d", &n, &m);
    cin >> n >> m;
    init(n);
    for(int i = 0; i < m; i++) {
        // scanf("%d%d", &a, &b);
        cin >> a >> b;
        merge(a, b);
    }
    // scanf("%d",&q);
    cin >> q;
    for(int i = 0; i < q; i++) {
        // scanf("%d%d", &c, &d);
        cin >> c >> d;
        // printf("%s\n", find(c) == find(d) ? "Yes" : "No");
        if(check(c, d)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    system("pause");
    return 0;
}
