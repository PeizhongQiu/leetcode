/*
 * @lc app=leetcode.cn id=2160 lang=cpp
 *
 * [2160] 拆分数位后四位数字的最小和
 *
 * https://leetcode-cn.com/problems/minimum-sum-of-four-digit-number-after-splitting-digits/description/
 *
 * algorithms
 * Easy (88.24%)
 * Likes:    9
 * Dislikes: 0
 * Total Accepted:    5.3K
 * Total Submissions: 6.1K
 * Testcase Example:  '2932'
 *
 * 给你一个四位 正 整数 num 。请你使用 num 中的 数位 ，将 num 拆成两个新的整数 new1 和 new2 。new1 和 new2
 * 中可以有 前导 0 ，且 num 中 所有 数位都必须使用。
 * 
 * 
 * 比方说，给你 num = 2932 ，你拥有的数位包括：两个 2 ，一个 9 和一个 3 。一些可能的 [new1, new2] 数对为 [22,
 * 93]，[23, 92]，[223, 9] 和 [2, 329] 。
 * 
 * 
 * 请你返回可以得到的 new1 和 new2 的 最小 和。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：num = 2932
 * 输出：52
 * 解释：可行的 [new1, new2] 数对为 [29, 23] ，[223, 9] 等等。
 * 最小和为数对 [29, 23] 的和：29 + 23 = 52 。
 * 
 * 
 * 示例 2：
 * 
 * 输入：num = 4009
 * 输出：13
 * 解释：可行的 [new1, new2] 数对为 [0, 49] ，[490, 0] 等等。
 * 最小和为数对 [4, 9] 的和：4 + 9 = 13 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1000 <= num <= 9999
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int minNum(int a, int b) {
        return a < b ? a : b;
    }
    int minimumSum(int num) {
        int max[4] = {0};
        max[0] = num % 10;
        max[1] = (num / 10) % 10;
        max[2] = (num / 100) % 10;
        max[3] = (num / 1000) % 10;
        sort(max, max + 4);
        return (max[0] + max[1]) * 10 + max[2] + max[3];
    }
};
// @lc code=end

