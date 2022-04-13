#include <algorithm>
#include "limits.h"
using namespace std;

/*
111. 二叉树的最小深度
https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/

用递归解决
思路1：自底向上统计信息。最大深度=max(左子树最大深度, 右子树最大深度) + 1
思路2：自顶向下维护信息。深度作为全局共享变量，level+1
变量+1，到叶子结点更新答案。注意要还原现场

这道题用思路2，104用思路1
*/

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
   public:
    int minDepth(TreeNode* root) {
        calc(root);
        return ans == INT_MAX ? 0 : ans;
    }

   private:
    int depth = 0;
    int ans = INT_MAX;

    void calc(TreeNode* root) {
        // 递归边界
        if (root != nullptr && root->left == nullptr && root->right == nullptr) {
            ans = min(ans, depth + 1);
            return;
        } else if (root == nullptr)
            return;

        // 本层逻辑，下一层left，还原现场
        depth += 1;
        calc(root->left);
        // depth -= 1

        // 本层逻辑，下一层right，还原现场
        // depth += 1;
        calc(root->right);
        depth -= 1;
    }
};