/*
 * @lc app=leetcode.cn id=402 lang=cpp
 *
 * [402] 移掉 K 位数字
 *
 * https://leetcode-cn.com/problems/remove-k-digits/description/
 *
 * algorithms
 * Medium (32.71%)
 * Likes:    729
 * Dislikes: 0
 * Total Accepted:    90.9K
 * Total Submissions: 277.9K
 * Testcase Example:  '"1432219"\n3'
 *
 * 给你一个以字符串表示的非负整数 num 和一个整数 k ，移除这个数中的 k 位数字，使得剩下的数字最小。请你以字符串形式返回这个最小的数字。
 * 
 * 
 * 示例 1 ：
 * 
 * 
 * 输入：num = "1432219", k = 3
 * 输出："1219"
 * 解释：移除掉三个数字 4, 3, 和 2 形成一个新的最小的数字 1219 。
 * 
 * 
 * 示例 2 ：
 * 
 * 
 * 输入：num = "10200", k = 1
 * 输出："200"
 * 解释：移掉首位的 1 剩下的数字为 200. 注意输出不能有任何前导零。
 * 
 * 
 * 示例 3 ：
 * 
 * 
 * 输入：num = "10", k = 2
 * 输出："0"
 * 解释：从原数字移除所有的数字，剩余为空就是 0 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * num 仅由若干位数字（0 - 9）组成
 * 除了 0 本身之外，num 不含任何前导零
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string removeKdigits(string num, int k) {
        char result[100000] = {0};
        result[0] = num[0];
        int index = 1;
        int top = 0;
        while(index < num.size()){
            while(top >= 0 && k > 0 && num[index] < result[top]) {
                --top;
                --k;
            }
            
            if(top < 0 || num[index] >= result[top] || k <= 0) {
                ++top;
                result[top] = num[index];
            }
            ++index;
            //cout << result << " " << top << endl;
        }
        //cout << k << endl;
        result[top + 1 - k] = '\0';
        string ret = result;
        
        int i = 0;
        for(i = 0; i < top; i++) {
            if(ret[i] != '0') {
                break;
            }
        }
        ret = ret.substr(i);
        if(ret == "") ret  = "0";
        return ret;
    }
};
// @lc code=end
