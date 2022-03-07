/*
 * @lc app=leetcode.cn id=498 lang=cpp
 *
 * [498] 对角线遍历
 *
 * https://leetcode-cn.com/problems/diagonal-traverse/description/
 *
 * algorithms
 * Medium (48.61%)
 * Likes:    276
 * Dislikes: 0
 * Total Accepted:    53.3K
 * Total Submissions: 109K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * 给你一个大小为 m x n 的矩阵 mat ，请以对角线遍历的顺序，用一个数组返回这个矩阵中的所有元素。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：mat = [[1,2,3],[4,5,6],[7,8,9]]
 * 输出：[1,2,4,7,5,3,6,8,9]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：mat = [[1,2],[3,4]]
 * 输出：[1,2,3,4]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == mat.length
 * n == mat[i].length
 * 1 <= m, n <= 10^4
 * 1 <= m * n <= 10^4
 * -10^5 <= mat[i][j] <= 10^5
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int direction = 1;
        vector<int> ret;
        int i = 0;
        int j = 0;
        while(i < mat.size() && j < mat[0].size()) {
            ret.push_back(mat[i][j]);
            //cout << direction << endl;
            if(direction == 1) {
                if(j == mat[0].size() - 1) {
                    ++i;
                    direction = -1;
                } else if(i == 0) {
                    ++j;
                    direction = -1;
                } else{
                    --i;
                    ++j;
                }
                
            } else {
                if(i == mat.size() - 1) {
                    ++j;
                    direction = 1;
                } else if(j == 0) {
                    ++i;
                    direction = 1;
                } else {
                    ++i;
                    --j;
                }
            }
        }
        return ret;
    }
};
// @lc code=end

