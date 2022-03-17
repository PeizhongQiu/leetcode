/*
 * @lc app=leetcode.cn id=329 lang=cpp
 *
 * [329] 矩阵中的最长递增路径
 *
 * https://leetcode-cn.com/problems/longest-increasing-path-in-a-matrix/description/
 *
 * algorithms
 * Hard (49.46%)
 * Likes:    609
 * Dislikes: 0
 * Total Accepted:    66.8K
 * Total Submissions: 134.7K
 * Testcase Example:  '[[9,9,4],[6,6,8],[2,1,1]]'
 *
 * 给定一个 m x n 整数矩阵 matrix ，找出其中 最长递增路径 的长度。
 * 
 * 对于每个单元格，你可以往上，下，左，右四个方向移动。 你 不能 在 对角线 方向上移动或移动到 边界外（即不允许环绕）。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：matrix = [[9,9,4],[6,6,8],[2,1,1]]
 * 输出：4 
 * 解释：最长递增路径为 [1, 2, 6, 9]。
 * 
 * 示例 2：
 * 
 * 
 * 输入：matrix = [[3,4,5],[3,2,6],[2,2,1]]
 * 输出：4 
 * 解释：最长递增路径是 [3, 4, 5, 6]。注意不允许在对角线方向上移动。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：matrix = [[1]]
 * 输出：1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == matrix.length
 * n == matrix[i].length
 * 1 
 * 0 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int dp[200][200] = {0};
    int _getdp(vector<vector<int>>& matrix, int row, int col) {
        if(dp[row][col] != 0) {
            return dp[row][col];
        }
        int maxDp = 1;
        if(row > 0 && matrix[row][col] > matrix[row - 1][col]) {
            maxDp = max(maxDp, _getdp(matrix, row - 1, col) + 1);
        }
        if(row < matrix.size() - 1 && matrix[row][col] > matrix[row + 1][col]) {
            maxDp = max(maxDp, _getdp(matrix, row + 1, col) + 1);
        }
        if(col > 0 && matrix[row][col] > matrix[row][col - 1]) {
            maxDp = max(maxDp, _getdp(matrix, row, col - 1) + 1);
        }
        if(col < matrix[0].size() - 1 && matrix[row][col] > matrix[row][col + 1]) {
            maxDp = max(maxDp, _getdp(matrix, row, col + 1) + 1);
        }
        dp[row][col] = maxDp;
        return dp[row][col];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ret = -1;
        for(int i = 0; i < matrix.size(); ++i) {
            for(int j = 0; j < matrix[0].size(); ++j) {
                ret = max(ret, _getdp(matrix, i ,j));
                //cout << dp[i][j] << " ";
            }
            //cout << endl;
        }
        return ret;
    }
};
// @lc code=end

