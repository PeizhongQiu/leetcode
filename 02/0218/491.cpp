/*
 * @lc app=leetcode.cn id=491 lang=cpp
 *
 * [491] 递增子序列
 *
 * https://leetcode-cn.com/problems/increasing-subsequences/description/
 *
 * algorithms
 * Medium (53.80%)
 * Likes:    401
 * Dislikes: 0
 * Total Accepted:    62.8K
 * Total Submissions: 117.3K
 * Testcase Example:  '[4,6,7,7]'
 *
 * 给你一个整数数组 nums ，找出并返回所有该数组中不同的递增子序列，递增子序列中 至少有两个元素 。你可以按 任意顺序 返回答案。
 * 
 * 数组中可能含有重复元素，如出现两个整数相等，也可以视作递增序列的一种特殊情况。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [4,6,7,7]
 * 输出：[[4,6],[4,6,7],[4,6,7,7],[4,7],[4,7,7],[6,7],[6,7,7],[7,7]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [4,4,3,2,1]
 * 输出：[[4,4]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 15
 * -100 <= nums[i] <= 100
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    void find(vector<int>& nums, int start, int last, vector<int> temp, vector<vector<int>>& ret) {
        if (start == nums.size()) {
            if (temp.size() >= 2) {
                ret.push_back(temp);
            }
            return;
        }
        if (nums[start] >= last) {
            temp.push_back(nums[start]);
            find(nums, start + 1, nums[start], temp, ret);
            temp.pop_back();
        }
        if (nums[start] != last) {
            find(nums, start + 1, last, temp, ret);
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> tmp;
        find(nums, 0, -200, tmp, ret);
        return ret;
    }
};
// @lc code=end

