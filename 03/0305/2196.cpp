//283次周赛 3
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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        TreeNode * tree = new TreeNode[100010]; 
        int use[100010];
        for(int i = 0; i < 100010; ++i) {
            tree[i].val = i;
            use[i] = -1;
        }
        for(int i = 0; i < descriptions.size(); ++i) {
            if(use[descriptions[i][0]] == -1) {
                use[descriptions[i][0]] = 0;
            }
            use[descriptions[i][1]] = 1;
            if(descriptions[i][2] == 1) {
                tree[descriptions[i][0]].left = &tree[descriptions[i][1]];
                
            } else {
                tree[descriptions[i][0]].right = &tree[descriptions[i][1]];
            }
        }
        for(int i = 0; i < 100010; ++i) {
            if(use[i] == 0) {
                return &tree[i];
            }
        }
        return NULL;
    }
};