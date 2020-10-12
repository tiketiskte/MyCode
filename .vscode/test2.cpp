#include <bits/stdc++.h>

#define lowbit(pos) (pos) & (-pos)

#define debug(x) cerr << (#x) << ":\t" << (x) << '\n'

#define debug2(x, y) cerr << (#x) << ":\t" << (x) << '\t' << (#y) << ":\t" << (y) << '\n'

#define debug3(x, y, z) cerr << (#x) << ":\t" << (x) << '\t' << (#y) << ":\t" << (y) << '\t' << (#z) << ":\t" << (z) << '\n'

#define IOS() {ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);}

typedef long long ll;

typedef unsigned long long ull;

using namespace std;

const int PRIME = 151;

const ll MOD = 1e9 + 7;

const int MAXN = 1e5 + 5;

const int INF = 0x3f3f3f3f;

 

int n;

 

void quicksort (int* a, int l, int r) {

    if (l >= r) return;

    int temp = a[l], i = l, j = r;

    while (i < j) {

        while (i < j && a[j] > temp) j--;

        a[i] = a[j];

        while (i < j && a[i] <= temp) i++;

        a[j] = a[i];

    }

    a[i] = temp;

    for (int k = 0; k < n - 1; ++k)

        cout << a[k] << ' ';

    cout << a[n - 1] << '\n';

    quicksort(a, l, i - 1);

    quicksort(a, i + 1, r);

}

 

int main () {

    IOS()

    string s, tt;

    getline(cin, s);

    int tmp = 0, a[50];

    for (int i = 0; i < s.length(); ++i) {

        if (isdigit(s[i]))

            tt += s[i];

        else if (isspace(s[i]))

            a[++n] = stoi(tt), tt = "";

    }

    a[++n] = stoi(tt);

    quicksort(a + 1, 0, n - 1);

    return 0;

}