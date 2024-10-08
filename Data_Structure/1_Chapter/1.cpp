
//Fibonacci的递归和非递归实现
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

const int MAXN = 50 + 5;
int n, a[MAXN];
void Fibonacci_1(int n) {
    a[1] = 1, a[2] = 1;
    for(int i = 3; i <= n; i++) {
        a[i] = a[i - 1] + a[i - 2];
    }
}
int Fibonacci_2(int n) {
    if(n == 0) {
        return 0;
    }
    if(n == 1) {
        return 1;
    }
    return Fibonacci_2(n - 1) + Fibonacci_2(n - 2);
}
void display(int n) {
    cout << "recursion:" << a[n] << endl;
    cout << "cycle:" << Fibonacci_2(n) << endl; 
    for(int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}
int main(void) {
    IOS
    cin >> n;
    Fibonacci_1(n);
    display(n);
    system("pause");
    return 0;
}
