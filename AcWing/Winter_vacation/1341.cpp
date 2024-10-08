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

int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int n, weekday[7]; 
int main(void) {
    IOS
    cin >> n;
    int days = 0;
    for(int year = 1900; year < 1900 + n; year++) {
        for(int i = 1; i <= 12; i++) {
            weekday[(days + 12) % 7]++;
            days += month[i];
            if(i == 2) {
                if((year % 4 == 0 && year % 100 != 0) || (year % 100 == 0 && year % 400 == 0)) {
                    days++;
                }
            }
        }
    }
    cout << weekday[5] << " " << weekday[6] << " ";
    for(int i = 0; i < 5; i++) {
        cout << weekday[i] << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}
