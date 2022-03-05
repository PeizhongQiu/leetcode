/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 *
 * https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 *
 * algorithms
 * Medium (42.34%)
 * Likes:    1501
 * Dislikes: 0
 * Total Accepted:    453.5K
 * Total Submissions: 1.1M
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * 给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
 * 
 * 如果数组中不存在目标值 target，返回 [-1, -1]。
 * 
 * 进阶：
 * 
 * 
 * 你可以设计并实现时间复杂度为 O(log n) 的算法解决此问题吗？
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [5,7,7,8,8,10], target = 8
 * 输出：[3,4]
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [5,7,7,8,8,10], target = 6
 * 输出：[-1,-1]
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [], target = 0
 * 输出：[-1,-1]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 
 * -10^9 
 * nums 是一个非递减数组
 * -10^9 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int start = 0, equal = -1, end = nums.size() - 1, mid = 0;
        while(start < end) {
            mid = (start + end) / 2;
            if(nums[mid] < target) {
                start = mid + 1;
            } else if(nums[mid] == target) {
                break;
            } else {
                end = mid;
            }
        }
        vector<int> result;
        if(nums.empty() || (start == end && nums[start] != target)) {
            result.push_back(-1);
            result.push_back(-1);
            return result;
        }
        int equalStart = (start + end) / 2;
        int equalEnd = (start + end) / 2;
        //cout << start << " " << end << endl;
        while(start < equalStart) {
            mid = (start + equalStart) / 2;
            if(nums[mid] != target) {
                start = mid + 1;
            } else {
                equalStart = mid;
            }
        }
        while(equalEnd < end) {
            mid = (equalEnd + end) / 2 + 1;
            if(nums[mid] != target) {
                end = mid - 1;
            } else {
                equalEnd = mid;
            }
        }
        result.push_back(equalStart);
        result.push_back(equalEnd);
        return result;
    }
};
// @lc code=end

