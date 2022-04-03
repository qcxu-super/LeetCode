#include <algorithm>
#include <unordered_set>
#include <vector>
using namespace std;

#include <iostream>

/*
15. 三数之和
https://leetcode-cn.com/problems/3sum/

思路：hashmap，可以c=target-(a+b)，可以去掉一重循环。
另外一种思路是用 sort&find
*/

class Solution {
   public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        vector<vector<int> > ans;
        if (nums.size() < 3)
            return ans;

        sort(nums.begin(), nums.end());  // 为了方便去掉重复的答案
        for (int i = 0; i < nums.size() - 2; ++i) {
            // duplicate
            if (i >= 1 && nums[i] == nums[i - 1])
                continue;

            unordered_set<int> sum;
            for (int j = i + 1; j < nums.size(); ++j) {
                //...,-2,1,1,1; ...,-2,-1,3,3
                if (j >= i + 3 && nums[j] == nums[j - 2])
                    continue;

                auto iter = sum.find(-nums[j]);
                if (iter != sum.end()) {
                    ans.push_back({nums[i], -nums[j] - nums[i], nums[j]});
                    sum.erase(iter);  //
                } else {
                    sum.insert(nums[i] + nums[j]);
                }
            }
        }
        return ans;
    }
};