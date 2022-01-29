#include <bits/stdc++.h>

using namespace std;
/*class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
         vector<int> ans;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(nums[j] == target - nums[i]) {
                    ans.push_back(i);
                    ans.push_back(j);
                }
            }
        }
        return ans;
    }
};*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        int n = nums.size();
        unordered_map<int, int> ump;
        unordered_map<int, int> :: iterator it;
        for(int i = 0; i < n; i++) {
            it = ump.find(target - nums[i]);
            if(it != ump.end()) {
                ans.push_back((*it).second);
                ans.push_back(i);
            }
            ump[nums[i]] = i;
        }
        return ans;
    }
};
int main(void) {
    Solution S;
    vector<int> nums = {2,7,11,15};
    int target = 9;
    vector<int> ans = S.twoSum(nums, target);
    for(auto i : ans) {
        cout << ans[i] << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}