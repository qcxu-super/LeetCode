#include <algorithm>
#include <vector>
using namespace std;

/*
15. 三数之和
https://leetcode-cn.com/problems/3sum/

思路：sort&find
把第1题两数之和作为子模块，然后枚举第一个数，在后面找两个数，让两数之和=0-第一个数
注意要全部答案，不能跟第1题一样只返回1个。还有就是不能重复。

另外一种思路是用 hashmap
*/

class Solution {
   public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int> > ans;
        for (int i = 0; i < nums.size(); ++i) {
            if (i >= 1 && nums[i] == nums[i - 1])
                continue;
            vector<vector<int> > jks = twoSum(nums, i + 1, -nums[i]);
            for (vector<int> jk : jks) {
                ans.push_back({nums[i], nums[jk[0]], nums[jk[1]]});
            }
        }
        return ans;
    }

   private:
    vector<vector<int> > twoSum(vector<int>& nums, int start, int target) {
        vector<vector<int> > ans;
        int j = nums.size() - 1;
        for (int i = start; i < nums.size(); ++i) {
            if (i >= start + 1 && nums[i] == nums[i - 1])
                continue;
            while (i < j && nums[i] + nums[j] > target)
                --j;
            if (i < j && nums[i] + nums[j] == target)
                ans.push_back({i, j});
        }
        return ans;
    }
};