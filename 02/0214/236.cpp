/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 *
 * https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/description/
 *
 * algorithms
 * Medium (68.52%)
 * Likes:    1535
 * Dislikes: 0
 * Total Accepted:    311K
 * Total Submissions: 453.8K
 * Testcase Example:  '[3,5,1,6,2,0,8,null,null,7,4]\n5\n1'
 *
 * 给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
 * 
 * 百度百科中最近公共祖先的定义为：“对于有根树 T 的两个节点 p、q，最近公共祖先表示为一个节点 x，满足 x 是 p、q 的祖先且 x
 * 的深度尽可能大（一个节点也可以是它自己的祖先）。”
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
 * 输出：3
 * 解释：节点 5 和节点 1 的最近公共祖先是节点 3 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
 * 输出：5
 * 解释：节点 5 和节点 4 的最近公共祖先是节点 5 。因为根据定义最近公共祖先节点可以为节点本身。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：root = [1,2], p = 1, q = 2
 * 输出：1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中节点数目在范围 [2, 10^5] 内。
 * -10^9 
 * 所有 Node.val 互不相同 。
 * p != q
 * p 和 q 均存在于给定的二叉树中。
 * 
 * 
 */


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/* 算法思想：
 * 首先中序遍历，记录每个 node 对应的 id。
 * p 和 q 的最近公共祖先假设为 m，
 * 则 p 和 q 要么在 m 的两侧，要么一个节点为另一个节点的祖先节点。
 * 因此，在中序遍历后，从根节点位置开始判断
 *  如果 p 和 q 的 id 都比该节点 id 小，则说明 p 和 q 都在左子树；
 *  如果 p 和 q 的 id 都比该节点 id 大，则说明 p 和 q 都在右子树；
 *  如果 p 和 q 的 id 一个大，一个小，则该节点为最近公共祖先；
 *  如果遍历到 p 或 q，则该节点为最近公共祖先。
 */
class Solution {
public:

    void visit(TreeNode* root, unordered_map<int,int>& nodeIndex) {
        if(root == NULL) return;
        if(root->left) visit(root->left, nodeIndex);
        nodeIndex[root->val] = nodeIndex.size();
        if(root->right) visit(root->right, nodeIndex);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        unordered_map<int,int> nodeIndex;
        visit(root, nodeIndex);
        int pIndex = nodeIndex[p->val];
        int qIndex = nodeIndex[q->val];
        int maxIndex = max(pIndex,qIndex);
        int minIndex = min(pIndex,qIndex);
        while(true) {
            if(nodeIndex[root->val] > minIndex && nodeIndex[root->val] < maxIndex) {
                return root;
            } else if(nodeIndex[root->val] == minIndex || nodeIndex[root->val] == maxIndex) {
                return root;
            } else if(nodeIndex[root->val] > maxIndex) {
                root = root->left;
            } else if(nodeIndex[root->val] < minIndex) {
                root = root->right;
            } else {
                return NULL;
            }
        }

    }
};

/* TIPS:
 * 采用递归的思想。
 * 先在左子树和右子树找 p 和 q，
 *  如果左子树和右子树都找到，则说明 p 和 q 分别在 root 的左右子树，
 * 因此，root 即为所求；
 *  如果其中一个没有找到，则说明都在左子树或右子树，只要在其左子树或
 * 右子树上递归即可。
 */
class SolutionOTHERS {
public:

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(root==p || root==q || root==nullptr) return root;
        
        TreeNode* a1=lowestCommonAncestor(root->left, p, q);
        TreeNode* a2=lowestCommonAncestor(root->right, p, q);
        if(a1 && a2) return root;
        
        return a1?a1:a2;
    }
};