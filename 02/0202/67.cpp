/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 *
 * https://leetcode-cn.com/problems/add-binary/description/
 *
 * algorithms
 * Easy (54.05%)
 * Likes:    745
 * Dislikes: 0
 * Total Accepted:    221.7K
 * Total Submissions: 410.2K
 * Testcase Example:  '"11"\n"1"'
 *
 * 给你两个二进制字符串，返回它们的和（用二进制表示）。
 * 
 * 输入为 非空 字符串且只包含数字 1 和 0。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: a = "11", b = "1"
 * 输出: "100"
 * 
 * 示例 2:
 * 
 * 输入: a = "1010", b = "1011"
 * 输出: "10101"
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 每个字符串仅由字符 '0' 或 '1' 组成。
 * 1 <= a.length, b.length <= 10^4
 * 字符串如果不是 "0" ，就都不含前导零。
 * 
 * 
 */


class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";
        char carry = 0;
        int ACurrentPosition = a.size() - 1;
        int BCurrentPosition = b.size() - 1;
        
        while(ACurrentPosition >= 0 || BCurrentPosition >= 0 || carry) {
            if(ACurrentPosition >= 0){
                carry += a[ACurrentPosition] - '0';
            }
            if(BCurrentPosition >= 0){
                carry += b[BCurrentPosition] - '0';
            }
            result = char((carry & 1) + '0') + result;
            carry = carry >> 1;
            
            ACurrentPosition--;
            BCurrentPosition--;
        }
        return result;
    }
};


