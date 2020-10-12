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

const int maxn = 1e6 + 5;

int T, x, k, ansL, ansR;
int L[maxn], R[maxn];
int sum[maxn], sum_max[maxn];
void add(int tmp) {
    L[++ansL] = tmp;
    sum[ansL] = tmp + sum[ansL - 1];
    sum_max[ansL] = max(sum[ansL], sum_max[ansL - 1]);
}
int main(void)
{
    IOS
    char ch[2];
    cin >> T;
    sum_max[0] = INT_MIN; 
    while(T--) {
        x = k = 0;
        cin >> ch;
        if(*ch == 'I') {
            cin >> k;
            add(k);
        } else if(*ch == 'D') {
            if(ansL) {
                ansL--;
            }
        } else if(*ch == 'L') {
            if(ansL) {
                R[++ansR] = L[ansL--];
            }
        } else if(*ch == 'R') {
            if(ansR) {
                add(R[ansR--]);
            }
        } else {
            cin >> k;
            cout << sum_max[k] << endl;
        }
    }
    system("pause");
    return 0;
}
