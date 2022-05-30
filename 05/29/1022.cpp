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
    int sumRootToLeaf(TreeNode* root) {
        int sum = 0;
        stack<pair<TreeNode*, int>> s;
        s.push({root, root->val});
        while(!s.empty()) {
            pair<TreeNode*,int> top = s.top();
            s.pop();
            if(top.first->left == NULL && top.first->right == NULL) {
                sum += top.second;
            }
            if(top.first->left != NULL) {
                s.push({top.first->left, top.second * 2 + top.first->left->val});
            }
            if(top.first->right != NULL) {
                s.push({top.first->right, top.second * 2 + top.first->right->val});
            }
        }
        return sum;
    }
};