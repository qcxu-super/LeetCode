#include <vector>
using namespace std;

/*
54. 螺旋矩阵
https://leetcode.cn/problems/spiral-matrix/

*/

class Solution {
   public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        int k = 0;

        int i = 0, j = -1, totnum = 0;
        vector<int> ans;
        while (totnum < m * n) {
            int ni = i + dx[k];
            int nj = j + dy[k];
            //
            if (i == 0 && j == n - 1)
                k = 1;
            else if (m > 1 && i == m - 1 && j == n - 1)
                k = 2;
            else if (m > 1 && i == m - 1 && j == 0) // [0,0]的别转到这里
                k = 3;
            else if (ni >= 0 && ni < m && nj >= 0 && nj < n && visited[ni][nj])
                k = (k + 1) % 4;
            //
            i = i + dx[k];
            j = j + dy[k];
            // cout << "k=" << k << ",i=" << i << ",j=" << j << ",num=" << matrix[i][j] << endl;
            //
            ans.push_back(matrix[i][j]);
            visited[i][j] = true;
            totnum += 1;
        }
        return ans;
    }
};