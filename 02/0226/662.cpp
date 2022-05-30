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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 1});
        unsigned long long ret = 1;
        int length = 1;
        while(!q.empty()) {
            unsigned long long leftMost = 0x7fffffffff;
            unsigned long long rightMost = 0;
            for(int i = 0; i < length; ++i) {
                pair<TreeNode*, unsigned long long> top = q.front();
                if(i == 0) {
                    leftMost = top.second;
                }
                if(i == length - 1) {
                    rightMost = top.second;
                }
                
                q.pop();
                if(top.first->left != NULL) {
                    q.push({top.first->left, top.second * 2});
                }
                if(top.first->right != NULL) {
                    q.push({top.first->right, top.second * 2 + 1});
                }
            }
            ret = max(ret, rightMost - leftMost + 1);
            length = q.size();
        }
        return ret;
    }
};