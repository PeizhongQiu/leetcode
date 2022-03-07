/*
 * @lc app=leetcode.cn id=1702 lang=cpp
 *
 * [1702] 修改后的最大二进制字符串
 *
 * https://leetcode-cn.com/problems/maximum-binary-string-after-change/description/
 *
 * algorithms
 * Medium (47.98%)
 * Likes:    20
 * Dislikes: 0
 * Total Accepted:    3.4K
 * Total Submissions: 7K
 * Testcase Example:  '"000110"'
 *
 * 给你一个二进制字符串 binary ，它仅有 0 或者 1 组成。你可以使用下面的操作任意次对它进行修改：
 * 
 * 
 * 操作 1 ：如果二进制串包含子字符串 "00" ，你可以用 "10" 将其替换。
 * 
 * 
 * 比方说， "00010" -> "10010"
 * 
 * 
 * 操作 2 ：如果二进制串包含子字符串 "10" ，你可以用 "01" 将其替换。
 * 
 * 比方说， "00010" -> "00001"
 * 
 * 
 * 
 * 
 * 请你返回执行上述操作任意次以后能得到的 最大二进制字符串 。如果二进制字符串 x 对应的十进制数字大于二进制字符串 y
 * 对应的十进制数字，那么我们称二进制字符串 x 大于二进制字符串 y 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：binary = "000110"
 * 输出："111011"
 * 解释：一个可行的转换为：
 * "000110" -> "000101" 
 * "000101" -> "100101" 
 * "100101" -> "110101" 
 * "110101" -> "110011" 
 * "110011" -> "111011"
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：binary = "01"
 * 输出："01"
 * 解释："01" 没办法进行任何转换。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * binary 仅包含 '0' 和 '1' 。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string maximumBinaryString(string binary) {
        int last0 = -1;
        for(int i = 0; i < binary.size(); ++i) {
            if(binary[i] == '0') {
                if(last0 == -1) last0 = i;
                else last0 = last0 + 1;
                //cout << last0 << endl;
            } 
        }
        string ret(binary.size(), '1');
        if(last0 != -1) {
            ret[last0] = '0';
            
        }
        return ret;
    }
};
// @lc code=end

