/*
 * @lc app=leetcode.cn id=504 lang=cpp
 *
 * [504] 七进制数
 *
 * https://leetcode-cn.com/problems/base-7/description/
 *
 * algorithms
 * Easy (50.35%)
 * Likes:    130
 * Dislikes: 0
 * Total Accepted:    40.8K
 * Total Submissions: 80K
 * Testcase Example:  '100'
 *
 * 给定一个整数 num，将其转化为 7 进制，并以字符串形式输出。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: num = 100
 * 输出: "202"
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: num = -7
 * 输出: "-10"
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * -10^7 <= num <= 10^7
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string convertToBase7(int num) {
        int ret = 0;
        int index = 1;
        while(num) {
            ret = num % 7 * index + ret;
            index = index * 10;
            num = num / 7;
        }
        return to_string(ret);
    }
};
// @lc code=end

