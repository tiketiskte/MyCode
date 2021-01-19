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

const int MAXN = 1e5 + 5;
int n, m, flag = 1, w[MAXN];
int main(void) {
    IOS
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> w[i];
    }
    sort(w, w + n);
    for(int i = 0, j = n - 1; i < j; i++) {
        while(i < j && w[i] + w[j] > m) {
            j--;
        }
        if(i < j && w[i] + w[j] == m) {
            cout << w[i] << " " <<  w[j] << endl;
            flag = 0;
            break;
        }
    }
    if(flag) {
        cout << "No Solution" << endl;
    }
    system("pause");
    return 0;
}
