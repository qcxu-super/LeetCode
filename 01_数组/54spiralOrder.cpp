#include <vector>
using namespace std;

/*
54. 螺旋矩阵
https://leetcode.cn/problems/spiral-matrix/

*/

class Solution {
   public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        vector<int> ans;

        int dx[4] = {0, 1, 0, -1};  // 右下左上
        int dy[4] = {1, 0, -1, 0};
        int k = 0;
        vector<vector<int>> visited(m, vector<int>(n, false));
        int i = 0, j = -1, totnum = 0;
        while (totnum < m * n) {
            // 本层逻辑
            i += dx[k];
            j += dy[k];
            // cout << "i=" << i << ",j=" << j << ",k=" << k << endl;
            if (isValid(i, j) && !visited[i][j]) {
                ans.push_back(matrix[i][j]);
                visited[i][j] = true;
                totnum++;
            }

            // 下一次方向
            // 右上角
            if (i == 0 && j == n - 1)
                k = (k + 1) % 4;
            // 右下角
            else if (i == m - 1 && j == n - 1)
                k = (k + 1) % 4;
            // 左下角  [[2,3]]这种只有一行的别落到这种情况
            else if (m > 1 && i == m - 1 && j == 0)
                k = (k + 1) % 4;
            // 已访问过
            else if (isValid(i + dx[k], j + dy[k]) >= 0 && visited[i + dx[k]][j + dy[k]])
                k = (k + 1) % 4;
        }
        return ans;
    }

   private:
    int m, n;
    bool isValid(int i, int j) {
        return i >= 0 && i < m && j >= 0 && j < n;
    }
};