/*
 * @lc app=leetcode.cn id=413 lang=cpp
 *
 * [413] 等差数列划分
 *
 * https://leetcode-cn.com/problems/arithmetic-slices/description/
 *
 * algorithms
 * Medium (69.14%)
 * Likes:    420
 * Dislikes: 0
 * Total Accepted:    87.2K
 * Total Submissions: 126K
 * Testcase Example:  '[1,2,3,4]'
 *
 * 如果一个数列 至少有三个元素 ，并且任意两个相邻元素之差相同，则称该数列为等差数列。
 * 
 * 
 * 例如，[1,3,5,7,9]、[7,7,7,7] 和 [3,-1,-5,-9] 都是等差数列。
 * 
 * 
 * 
 * 
 * 给你一个整数数组 nums ，返回数组 nums 中所有为等差数组的 子数组 个数。
 * 
 * 子数组 是数组中的一个连续序列。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,2,3,4]
 * 输出：3
 * 解释：nums 中有三个子等差数组：[1, 2, 3]、[2, 3, 4] 和 [1,2,3,4] 自身。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1]
 * 输出：0
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * -1000 
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int start = 0;
        int end = 2;
        int ret = 0;
        while(end < nums.size()) {
            if(nums[end] - nums[end-1] == nums[end - 1] - nums[end - 2]) {
                ++end;
            } else {
                //cout << start << " " << end << endl;
                int x = end - start;
                ret += (x-1)*(x-2) / 2;
                start = end - 1;
                end = end + 1;
            }
        }
        int x = end - start;
        ret += (x-2)*(x-1) / 2;
        return ret;
    }
};
// @lc code=end

