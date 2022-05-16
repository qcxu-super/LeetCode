#include <vector>
using namespace std;

/*
498. 对角线遍历
https://leetcode.cn/problems/diagonal-traverse/

*/

class Solution {
   public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        // cout << "m=" << m << ",n=" << n << endl;
        vector<int> ans;

        int i = 0, j = 0;
        int dx[4] = {1, -1};
        int dy[4] = {-1, 1};
        int k = 1;
        while (i < m && j < n) {
            ans.push_back(mat[i][j]);

            // cout << "i=" << i << ",j=" << j << ",k=" << k << ",num=" << mat[i][j] << " ==== ";

            // 碰上边 -> 往右移
            if (i == 0 && k == 1 && j < n - 1) {
                // cout << "case1" << endl;
                ++j;
                k = 0;
            }
            // 右上角
            else if (i == 0 && k == 1 && j == n - 1) {
                // cout << "case2" << endl;
                ++i;
                k = 0;
            }
            // 碰左边 -> 往下移
            else if (j == 0 && k == 0 && i < m - 1) {
                // cout << "case3" << endl;
                ++i;
                k = 1;
            }
            // 左下角
            else if (i == m - 1 && k == 0) {
                // cout << "case5" << endl;
                ++j;
                k = (k == 0) ? 1 : 0;  // 换方向
            }
            // 碰右边
            else if (j == n - 1 && k == 1) {
                // cout << "case6" << endl;
                ++i;
                k = 0;
            }
            // 没碰边
            else {
                // cout << "else" << endl;
                i = i + dx[k];
                j = j + dy[k];
            }
        }
        return ans;
    }
};