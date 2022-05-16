#include <vector>
using namespace std;

/*
59. 螺旋矩阵 II
https://leetcode.cn/problems/spiral-matrix-ii/

*/

class Solution {
   public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        int x = 1;
        int i = 0, j = -1;

        vector<vector<bool>> visited(n, vector<bool>(n, false));
        int dx[4] = {0, 1, 0, -1};  // 右下左上
        int dy[4] = {1, 0, -1, 0};
        
        int k = 0;
        while (x <= n * n) {
            if (n > 1 && i == 0 && j == n - 1)
                k = 1;
            else if (n > 1 && i == n - 1 && j == n - 1)
                k = 2;
            else if (n > 1 && i == n - 1 && j == 0)
                k = 3;

            int ni = i + dx[k];
            int nj = j + dy[k];
            if (ni < 0 || ni >= n || nj < 0 || nj >= n || visited[ni][nj])
                k = (k + 1) % 4;

            i += dx[k];
            j += dy[k];
            ans[i][j] = x;
            visited[i][j] = true;

            // cout << "k=" << k << ",i=" << i << ",j=" << j << ",x=" << x << endl;

            ++x;
        }
        return ans;
    }
};