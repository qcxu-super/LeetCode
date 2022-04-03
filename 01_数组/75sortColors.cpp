#include <vector>
using namespace std;

#include <iostream>

/*
75. 颜色分类
https://leetcode-cn.com/problems/sort-colors/

想法：左指针用来交换0，右指针用来交换1，遍历指针如果遍历到0和1就交换。左指针一定在右指针的左边
*/

class Solution {
   public:
    void sortColors(vector<int>& nums) {
        int l = 0, r = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            // cout << "-------------------" << endl;
            // cout << "l=" << l << ",i=" << i << ",r=" << r << endl;
            // for (int& n1: nums)
            //     cout << n1 << ",";
            // cout << endl;

            if (nums[i] == 1) {
                swap(nums, i, r);
                ++r;
            } else if (nums[i] == 0) {
                swap(nums, i, l);
                if (nums[i] <
                    nums[r])  // 可能出现上一步后nums[l]=1换到nums[r]=2后面
                    swap(nums, i, r);
                ++l;
                ++r;
            }
        }
    }

   private:
    void swap(vector<int>& nums, int i, int j) {
        // cout << "swap " << i << " & " << j << endl;
        // cout << "swap before: ";
        // for (int& n: nums)
        //     cout << n << ",";

        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;

        // cout << endl << "after swap: ";
        // for (int& n : nums)
        //     cout << n << ",";
        // cout << endl;
    }
};