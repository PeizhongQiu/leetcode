/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
 *
 * https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/description/
 *
 * algorithms
 * Hard (44.72%)
 * Likes:    1459
 * Dislikes: 0
 * Total Accepted:    201.1K
 * Total Submissions: 448.8K
 * Testcase Example:  '[1,2,3]'
 *
 * 路径 被定义为一条从树中任意节点出发，沿父节点-子节点连接，达到任意节点的序列。同一个节点在一条路径序列中 至多出现一次 。该路径 至少包含一个
 * 节点，且不一定经过根节点。
 * 
 * 路径和 是路径中各节点值的总和。
 * 
 * 给你一个二叉树的根节点 root ，返回其 最大路径和 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：root = [1,2,3]
 * 输出：6
 * 解释：最优路径是 2 -> 1 -> 3 ，路径和为 2 + 1 + 3 = 6
 * 
 * 示例 2：
 * 
 * 
 * 输入：root = [-10,9,20,null,null,15,7]
 * 输出：42
 * 解释：最优路径是 15 -> 20 -> 7 ，路径和为 15 + 20 + 7 = 42
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中节点数目范围是 [1, 3 * 10^4]
 * -1000 
 * 
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode *, vector<int>> dp;
    int ret = INT_MIN;
    void maxPathSumRoot(TreeNode* root) {
        if(dp.count(root) == 0) {
            int left = 0, right = 0;
            if(root->left) {
                maxPathSumRoot(root->left);
                dp[root].push_back(max(max(dp[root->left][0], dp[root->left][1]), 0) + root->val);
            } else {
                dp[root].push_back(root->val);
            }
            if(root->right) {
                maxPathSumRoot(root->right);
                dp[root].push_back(max(max(dp[root->right][0], dp[root->right][1]), 0) + root->val);
            } else {
                dp[root].push_back(root->val);
            }
            ret = max(ret, root->val);
            ret = max(ret, dp[root][0]);
            ret = max(ret, dp[root][1]);
            ret = max(ret, dp[root][0] + dp[root][1] - root->val);
        } 
        
    }
    int maxPathSum(TreeNode* root) {
        maxPathSumRoot(root);
        return ret;
    }
};
// @lc code=end

