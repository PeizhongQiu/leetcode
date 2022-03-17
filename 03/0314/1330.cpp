/*
 * @lc app=leetcode.cn id=1330 lang=cpp
 *
 * [1330] 翻转子数组得到最大的数组值
 *
 * https://leetcode-cn.com/problems/reverse-subarray-to-maximize-array-value/description/
 *
 * algorithms
 * Hard (38.83%)
 * Likes:    60
 * Dislikes: 0
 * Total Accepted:    1.4K
 * Total Submissions: 3.5K
 * Testcase Example:  '[2,3,1,5,4]'
 *
 * 给你一个整数数组 nums 。「数组值」定义为所有满足 0 <= i < nums.length-1 的 |nums[i]-nums[i+1]|
 * 的和。
 * 
 * 你可以选择给定数组的任意子数组，并将该子数组翻转。但你只能执行这个操作 一次 。
 * 
 * 请你找到可行的最大 数组值 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [2,3,1,5,4]
 * 输出：10
 * 解释：通过翻转子数组 [3,1,5] ，数组变成 [2,5,1,3,4] ，数组值为 10 。
 * 
 * 
 * 示例 2：
 * 
 * 输入：nums = [2,4,9,24,2,1,10]
 * 输出：68
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 3*10^4
 * -10^5 <= nums[i] <= 10^5
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int maxValueAfterReverse(vector<int>& nums) {

        int base = 0;
        for (int i = 1; i < nums.size(); ++i) base += abs(nums[i-1]-nums[i]);
        int res = base;
        for (int i = 1; i < nums.size() - 1; ++i) {
            res = max(res, base-abs(nums[i]-nums[i+1])+abs(nums[i+1]-nums[0]));
            res = max(res, base-abs(nums[i]-nums[i-1])+abs(nums[i-1]-nums[nums.size()-1])); 
        }
        int f[2] = {-1, 1};
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                int maxF = -1e9;
                int minF = 1e9;
                for (int k = 1; k < nums.size(); ++k) {
                    maxF = max(maxF, f[i]*nums[k-1]+f[j]*nums[k]-abs(nums[k-1]-nums[k]));
                    minF = min(minF, f[i]*nums[k-1]+f[j]*nums[k]+abs(nums[k-1]-nums[k]));
                }
                res = max(res, base + maxF - minF);
            }
        }
        return res;
    }
};
// @lc code=end

