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

const int MAXN = 300 + 5;
struct node {
    int a, b, c, id, all;
}a[MAXN];
bool cmp(node &x, node &y) {
    if(x.all == y.all) {
        if(x.a == y.a) {
            return x.id < y.id;
        } else {
            return x.a > y.a;
        }
    }
    return x.all > y.all;
}
int n;
int main(void) {
    IOS
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i].a >> a[i].b >> a[i].c;
        a[i].id = i + 1, a[i].all = a[i].a + a[i].b + a[i].c;
    }
    sort(a, a + n, cmp);
    for(int i = 0; i < 5; i++) {
        cout << a[i].id << " " << a[i].all << endl;
    }
    system("pause");
    return 0;
}
