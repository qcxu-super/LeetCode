#include <vector>
using namespace std;

/*
673. 最长递增子序列的个数
https://leetcode-cn.com/problems/number-of-longest-increasing-subsequence/

状态: f[i][j] 以第 i 个数字结尾。f[i][0]=最长递增子序列长度，f[i][1]=路径数
递推关系: f[i][0] = max(f[j][0]) + 1, 其中 j < i && nums[j] < num[i]
         f[i][1] = sum(f[j][1]), 其中 j = argmax(f[j][0])

我这里定义成二维了。也可以定义两个，可能会更清晰，因为是两个东西。类似于152
*/

class Solution {
   public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int> > f(n, vector<int>(2, 0));
        f[0][1] = 1;
        // 到第 i 个最优
        for (int i = 0; i < n; ++i) {
            f[i][0] = 1;
            // 更新 f[i][0]
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    f[i][0] = max(f[i][0], f[j][0] + 1);
                }
            }
            // 更新 f[i][1]
            // 当前数字很小，最长上升序列只有自己
            if (f[i][0] == 1) {
                f[i][1] = 1;
                continue;
            }
            // 当前最长序列是从前面的子序列上拼接的
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i] && f[i][0] == f[j][0] + 1)
                    f[i][1] += f[j][1];
            }
        }
        // for (int i = 0; i < n; ++i) {
        //     cout << "f[" << i << ",0]=" << f[i][0] << ",f[" << i << ",1]=" <<
        //     f[i][1] << endl;
        // }

        // 全局最优
        // f[i][0]
        int maxLength = 0;
        for (int i = 0; i < n; ++i) {
            if (f[i][0] > maxLength)
                maxLength = max(maxLength, f[i][0]);
        }
        // f[i][1]
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (f[i][0] == maxLength)
                ans += f[i][1];
        }
        return ans;
    }
};
