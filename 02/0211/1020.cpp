/*
 * @lc app=leetcode.cn id=1020 lang=cpp
 *
 * [1020] 飞地的数量
 *
 * https://leetcode-cn.com/problems/number-of-enclaves/description/
 *
 * algorithms
 * Medium (60.80%)
 * Likes:    161
 * Dislikes: 0
 * Total Accepted:    38.3K
 * Total Submissions: 63K
 * Testcase Example:  '[[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]'
 *
 * 给你一个大小为 m x n 的二进制矩阵 grid ，其中 0 表示一个海洋单元格、1 表示一个陆地单元格。
 * 
 * 一次 移动 是指从一个陆地单元格走到另一个相邻（上、下、左、右）的陆地单元格或跨过 grid 的边界。
 * 
 * 返回网格中 无法 在任意次数的移动中离开网格边界的陆地单元格的数量。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
 * 输出：3
 * 解释：有三个 1 被 0 包围。一个 1 没有被包围，因为它在边界上。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：grid = [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
 * 输出：0
 * 解释：所有 1 都在边界上或可以到达边界。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 500
 * grid[i][j] 的值为 0 或 1
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        stack<int> visit;
        int result = 0;
        for(int i = 0; i < grid.size(); i++) {
            if(grid[i][0] == 1) {
                visit.push(i * grid[0].size());
                grid[i][0] = 2;
            }
            if(grid[i][grid[0].size()-1] == 1) {
                visit.push(i * grid[0].size() + grid[0].size()-1);
                grid[i][grid[0].size()-1] = 2;
            }
        }

        for(int i = 0; i < grid[0].size(); i++) {
            if(grid[0][i] == 1) {
                visit.push(i);
                grid[0][i] = 2;
            }
            if(grid[grid.size()-1][i] == 1) {
                visit.push((grid.size() - 1) * grid[0].size() + i);
                grid[grid.size()-1][i] = 2;
            }
        }
        while(!visit.empty()) {
            int top = visit.top();
            visit.pop();
            int first = top / grid[0].size();
            int second = top % grid[0].size();
            if(first != 0 && grid[first - 1][second] == 1) {
                visit.push((first - 1) * grid[0].size() + second);
                grid[first - 1][second] = 2;
            }
            if(second != 0 && grid[first][second - 1] == 1) {
                visit.push(first * grid[0].size() + second - 1);
                grid[first][second - 1] = 2;
            }
            if(first != grid.size() - 1 && grid[first + 1][second] == 1) {
                visit.push((first + 1) * grid[0].size() + second);
                grid[first + 1][second] = 2;
            }
            if(second != grid[0].size() - 1 && grid[first][second + 1] == 1) {
                visit.push(first * grid[0].size() + second + 1);
                grid[first][second + 1] = 2;
            }

        }

        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 1)
                    ++result;
            }
        }
        return result;
    }
};
// @lc code=end

