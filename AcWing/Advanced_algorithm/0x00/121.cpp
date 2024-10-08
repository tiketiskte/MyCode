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

const int maxn = 1000 + 10;
int N, C;
PII points[maxn];
int sum[maxn][maxn];
vector <int> numbers;
int get(int x) {
    int l = 0, r = numbers.size();
    while(l < r) {
        int mid = l + r >> 1;
        if(numbers[mid] >= x) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return r;
}
bool check(int len) {
    for(int x1 = 0, x2 = 1; x2 < numbers.size(); x2++) {
        while(numbers[x2] - numbers[x1 + 1] + 1 > len) {
            x1++;
        }
        for(int y1 = 0, y2 = 1; y2 < numbers.size(); y2++) {
            while(numbers[y2] - numbers[y1 + 1] + 1 >len) {
                y1++;
            }
            if(sum[x2][y2]- sum[x1][y2]- sum[x2][y1] + sum[x1][y1] >= C) {
                return true;
            }
        }
    }
    return false;
}
int main(void)
{
    IOS
    cin >> C >> N;
    for(int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        points[i] = make_pair(x, y);
        numbers.push_back(x);
        numbers.push_back(y);
    }
    sort(numbers.begin(), numbers.end());
    numbers.erase(unique(numbers.begin(), numbers.end()), numbers.end());
    for(int i = 0; i < N; i++) {
        int x = get(points[i].first), y = get(points[i].second);
        sum[x][y]++;
    }
    for(int i = 1; i < numbers.size(); i++) {
        for(int j = 1; j < numbers.size(); j++) {
            sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
        }
    }
    int l = 1, r = 1000;
    while(l < r) {
        int mid = l + r >> 1;
        if(check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << r << endl;
    system("pause");
    return 0;
}
