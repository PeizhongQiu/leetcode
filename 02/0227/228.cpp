/*
 * @lc app=leetcode.cn id=228 lang=cpp
 *
 * [228] 汇总区间
 *
 * https://leetcode-cn.com/problems/summary-ranges/description/
 *
 * algorithms
 * Easy (57.48%)
 * Likes:    203
 * Dislikes: 0
 * Total Accepted:    66.2K
 * Total Submissions: 115.6K
 * Testcase Example:  '[0,1,2,4,5,7]'
 *
 * 给定一个  无重复元素 的 有序 整数数组 nums 。
 * 
 * 返回 恰好覆盖数组中所有数字 的 最小有序 区间范围列表 。也就是说，nums 的每个元素都恰好被某个区间范围所覆盖，并且不存在属于某个范围但不属于
 * nums 的数字 x 。
 * 
 * 列表中的每个区间范围 [a,b] 应该按如下格式输出：
 * 
 * 
 * "a->b" ，如果 a != b
 * "a" ，如果 a == b
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [0,1,2,4,5,7]
 * 输出：["0->2","4->5","7"]
 * 解释：区间范围是：
 * [0,2] --> "0->2"
 * [4,5] --> "4->5"
 * [7,7] --> "7"
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [0,2,3,4,6,8,9]
 * 输出：["0","2->4","6","8->9"]
 * 解释：区间范围是：
 * [0,0] --> "0"
 * [2,4] --> "2->4"
 * [6,6] --> "6"
 * [8,9] --> "8->9"
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= nums.length <= 20
 * -2^31 <= nums[i] <= 2^31 - 1
 * nums 中的所有值都 互不相同
 * nums 按升序排列
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        
        vector<string> ret;
        if(nums.empty()) return ret;
        long long start = nums[0];
        long long length = 1;
        for(int i = 1; i < nums.size(); ++i) {
            if(nums[i] == start + length) {
                ++length;
            } else {
                string temp = "";
                if(length == 1) {
                    ret.push_back(to_string(start));
                } else {
                    temp += to_string(start) + "->" + to_string(start - 1 + length);
                    ret.push_back(temp);
                }
                length = 1;
                start = nums[i];
            }
        }
        string temp = "";
        if(length == 1) {
            ret.push_back(to_string(start));
        } else {
            temp += to_string(start) + "->" + to_string(start - 1 + length);
            ret.push_back(temp);
        }
        return ret;
    }
};
// @lc code=end

