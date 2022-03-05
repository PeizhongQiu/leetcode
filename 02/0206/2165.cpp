/*
 * @lc app=leetcode.cn id=2165 lang=cpp
 *
 * [2165] 重排数字的最小值
 *
 * https://leetcode-cn.com/problems/smallest-value-of-the-rearranged-number/description/
 *
 * algorithms
 * Medium (54.44%)
 * Likes:    5
 * Dislikes: 0
 * Total Accepted:    5.6K
 * Total Submissions: 10.3K
 * Testcase Example:  '310'
 *
 * 给你一个整数 num 。重排 num 中的各位数字，使其值 最小化 且不含 任何 前导零。
 * 
 * 返回不含前导零且值最小的重排数字。
 * 
 * 注意，重排各位数字后，num 的符号不会改变。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：num = 310
 * 输出：103
 * 解释：310 中各位数字的可行排列有：013、031、103、130、301、310 。
 * 不含任何前导零且值最小的重排数字是 103 。
 * 
 * 
 * 示例 2：
 * 
 * 输入：num = -7605
 * 输出：-7650
 * 解释：-7605 中各位数字的部分可行排列为：-7650、-6705、-5076、-0567。
 * 不含任何前导零且值最小的重排数字是 -7650 。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * -10^15 <= num <= 10^15
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    long long smallestNumber(long long num) {
        vector<long long> bitNum;
        long long result = 0;
        while(num != 0) {
            bitNum.push_back(num%10);
            //cout << num%10 << endl;
            num /= 10;
        }
        sort(bitNum.begin(), bitNum.end());
        for(int i = 0; i < bitNum.size(); i++) {
            if(bitNum[i] != 0) {
                int temp = bitNum[0];
                bitNum[0] = bitNum[i];
                bitNum[i] = temp;
                break;
            }
        }
        for(int i = 0; i < bitNum.size(); i++) {
            result = result * 10 + bitNum[i];
        }
        
        return result;
    }
};
// @lc code=end

