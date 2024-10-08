/**
* Copyright(c)
* Author : tiketiskte
**/
#include <bits/stdc++.h>
#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long
#define PII pair<int, int>
#define PLL pair<ll, ll>
#define PDD pair<double, double>
#define sqr(x) (x) * (x)
#define SZ(X) (int)X.size()
#define INF 0x3f3f3f3f

using namespace std;

const int maxn = 1000 + 5;
struct node {
    int father, size, sum;
    double avg;
}tree[maxn];
int n, r, a[maxn];
int find() {
    double avg = 0;
    int res = -1;
    for(int i = 1; i <= n; i++) {
        if(i != r && avg < tree[i].avg) {
            avg = tree[i].avg;
            res = i;
        }
    }
    return res;
}
int main(void)
{
    IOS
    cin >> n >> r;
    int res = 0;
    for(int i = 1; i <= n; i++) {
        cin >> tree[i].sum;
        tree[i].size = 1;
        tree[i].avg = tree[i].sum;
        res += tree[i].sum;
    }
    for(int i = 0, a, b; i < n - 1; i++) {
        cin >> a >> b;
        tree[b].father = a;
    }
    for(int i = 0; i < n - 1; i++) {
        int ver = find();
        int f = tree[ver].father;
        res += tree[ver].sum * tree[f].size;
        tree[ver].avg = -1;
        for(int j = 1; j <= n; j++) {
            if(tree[j].father == ver) {
                tree[j].father = f;
            }
        }
        tree[f].sum += tree[ver].sum;
        tree[f].size += tree[ver].size;
        tree[f].avg = (double)tree[f].sum / tree[f].size;
    }
    cout << res << endl;
    system("pause");
    return 0;
}
