/**
* Copyright(c)
* Author : tiketiskte
*/
#include <bits/stdc++.h>
#define IOS {ios::sync_with_stdio(false);cin.tie(0);}
#define ll long long
#define INF 0x3f3f3f3f

using namespace std;
int n;
string s;
bool flag;
int a[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
int ans[11] = {1, 0, 10, 9, 8, 7, 6, 5, 4, 3, 2};
bool solve() {
    int sum = 0;
    for(int i = 0; i < 17; i++) {
        if(s[i] <'0' || s[i] > '9') {
            return false;
        }
        sum += (s[i] - '0') * a[i];
    }
    int temp = (s[17] == 'X') ? 10 : (s[17] - '0');
    return temp == ans[sum % 11];
}
int main()
{
   IOS
   cin >> n;
   flag = false;//所有的都要去满足 定义在while内部可能出现第一个满足，结果后边的不满足情况
   while(n--) {
       cin >> s;
       if(!solve()) {
           cout << s << endl;
           flag = true;
       }
   }
   if(!flag) {
       cout << "All passed" << endl;
   }
   //system("pause");
   return 0;
}
