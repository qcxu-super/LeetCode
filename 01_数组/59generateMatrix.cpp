#include <vector>
using namespace std;

/*
59. 螺旋矩阵 II
https://leetcode.cn/problems/spiral-matrix-ii/

*/

class Solution {
   public:
    vector<vector<int>> generateMatrix(int n) {
        this->n = n;
        vector<vector<int>> ans(n, vector<int>(n, 0));
        int totnum = 0;
        int dx[4] = {0, 1, 0, -1};  // 右下左上
        int dy[4] = {1, 0, -1, 0};
        int k = 0;
        int i = 0, j = -1;
        while (totnum < n * n) {
            // 本层逻辑
            i += dx[k];
            j += dy[k];
            if (isValid(i, j) && ans[i][j] == 0) {
                totnum += 1;
                ans[i][j] = totnum;
            }

            // 下一次的方向
            // 右上角
            if (i == 0 && j == n - 1)
                k = (k + 1) % 4;
            // 右下角
            else if (i == n - 1 && j == n - 1)
                k = (k + 1) % 4;
            // 左下角
            else if (n > 1 && i == n - 1 && j == 0)
                k = (k + 1) % 4;
            // visited
            else if (isValid(i + dx[k], j + dy[k]) && ans[i + dx[k]][j + dy[k]] > 0)
                k = (k + 1) % 4;
        }
        return ans;
    }

   private:
    int n;
    bool isValid(int i, int j) {
        return i >= 0 && i < n && j >= 0 && j < n;
    }
};