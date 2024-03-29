/*
 * @lc app=leetcode.cn id=312 lang=cpp
 *
 * [312] 戳气球
 *
 * https://leetcode-cn.com/problems/burst-balloons/description/
 *
 * algorithms
 * Hard (68.74%)
 * Likes:    924
 * Dislikes: 0
 * Total Accepted:    66.7K
 * Total Submissions: 96.8K
 * Testcase Example:  '[3,1,5,8]'
 *
 * 有 n 个气球，编号为0 到 n - 1，每个气球上都标有一个数字，这些数字存在数组 nums 中。
 * 
 * 现在要求你戳破所有的气球。戳破第 i 个气球，你可以获得 nums[i - 1] * nums[i] * nums[i + 1] 枚硬币。 这里的 i
 * - 1 和 i + 1 代表和 i 相邻的两个气球的序号。如果 i - 1或 i + 1 超出了数组的边界，那么就当它是一个数字为 1 的气球。
 * 
 * 求所能获得硬币的最大数量。
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [3,1,5,8]
 * 输出：167
 * 解释：
 * nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
 * coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1,5]
 * 输出：10
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == nums.length
 * 1 
 * 0 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int minNum = 0;
        int dp[302][302] = {0};
        for(int i = nums.size() + 1; i >= 0; --i) {
            
            for(int j = i; j <= nums.size() + 1; ++j) {
                if(j - i < 2) {
                    dp[i][j] = 0;
                } else {
                    int temp = 0;
                    for(int k = i + 1; k < j; ++k) {
                        int sum = 1;
                        if(i > 0 && i <= nums.size()) sum *= nums[i-1];
                        if(j > 0 && j <= nums.size()) sum *= nums[j-1];
                        if(k > 0 && k <= nums.size()) sum *= nums[k-1];
                        temp = max(temp, dp[i][k] + dp[k][j] +  sum);
                    }
                    dp[i][j] = temp;
                }
            }
        }
        return dp[0][nums.size() + 1];
    }
};
// @lc code=end

