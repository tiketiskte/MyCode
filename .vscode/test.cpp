/**
* Copyright(c)
* Author : tiketiskte
**/
#include <bits/stdc++.h>
#include <tr1/unordered_map>
#define IOS {ios::sync_with_stdio(false);cin.tie(0);}
#define ll long long
#define SZ(X) (int)X.size()
#define INF 0x3f3f3f3f
using namespace std;
using namespace std::tr1;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int ans = 0;
        tr1::unordered_map <int, int> mp;
        tr1::unordered_map <int, int> :: iterator it; 
        int len = nums.size();
        cout << len << "###" << endl;
        for(int i = 0; i < len; i++) {
            if(mp.find(nums[i]) == mp.end()) {
                mp.insert(make_pair(nums[i], 1));
            }
        }
        for(it = mp.begin(); it != mp.end(); it++) {
           cout << it -> first << "#####" << it -> second << endl;
        }
        int len2 = mp.size();
        for(int i = 0; i <= len2; i++) {
            if(mp[nums[i]] == 0) {
                ans = i;
                break;
            }
        }
        return ans;
    }
};
template<typename T, size_t N>
size_t size(const T(&)[N]) {
    return N;
}
int main()
{
   IOS
   Solution solution;
   int arr[] ={1, 2, 0};
   vector <int> v(arr, arr + size(arr));
   /* vector <int> :: iterator it;
   for(it = v.begin(); it != v.end(); it++) {
      cout << *it << endl;
   } */
   cout << solution.firstMissingPositive(v) << endl;
   system("pause");
   return 0;
}
