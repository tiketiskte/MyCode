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


int main(void)
{
    IOS
    vector <int> v = {1, 2, 1, 1, 3, 3, 3, 4, 5, 4};
    sort(v.begin(), v.end());
    // 1 1 1 2 3 3 3 4 4 5
    for(auto it : v) {
        cout << it << " ";
    }
    cout << "###" << endl;
    // 1 2 3 4 5 1 1 3 3 4 
    auto last = unique(v.begin(), v.end());
    cout << "unique: " << *last << endl;
    v.erase(last, v.end());
    cout << "***" << endl;
    for(int x : v) {
        cout << x << " ";
    }
    cout << endl; // 数据缓冲流
    /* auto last = unique(v.begin(), v.end());
    cout << "unique:" << " ";
    for(auto it : v) {
        cout << it << " ";
    }
    cout << "unique:" << " ";
    cout << *last << endl;
    v.erase(last, v.end());
    for(auto it : v) {
        cout << it << endl;
    } */
    system("pause");
    return 0;
}
