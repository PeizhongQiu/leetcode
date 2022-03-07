/*
 * @lc app=leetcode.cn id=345 lang=cpp
 *
 * [345] 反转字符串中的元音字母
 *
 * https://leetcode-cn.com/problems/reverse-vowels-of-a-string/description/
 *
 * algorithms
 * Easy (54.05%)
 * Likes:    240
 * Dislikes: 0
 * Total Accepted:    119.8K
 * Total Submissions: 221.6K
 * Testcase Example:  '"hello"'
 *
 * 给你一个字符串 s ，仅反转字符串中的所有元音字母，并返回结果字符串。
 * 
 * 元音字母包括 'a'、'e'、'i'、'o'、'u'，且可能以大小写两种形式出现。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "hello"
 * 输出："holle"
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "leetcode"
 * 输出："leotcede"
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 3 * 10^5
 * s 由 可打印的 ASCII 字符组成
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string reverseVowels(string s) {
        int left = 0;
        int right = s.size() - 1;
        while(left < right) {
            if(s[left] == 'a' || s[left] == 'e' || s[left] == 'o' || s[left] == 'u' || s[left] == 'i' ||
              s[left] == 'A' || s[left] == 'E' || s[left] == 'I' || s[left] == 'O' || s[left] == 'U') {
                while(left < right) {
                    if(s[right] == 'a' || s[right] == 'e' || s[right] == 'o' || s[right] == 'u' || s[right] == 'i' || s[right] == 'A' || s[right] == 'E' || s[right] == 'I' || s[right] == 'O' || s[right] == 'U'){
                        int temp = s[right];
                        s[right] = s[left];
                        s[left] = temp;
                        break;
                    } else {
                        --right;
                    }
                }
                --right;
                ++left;
                
            } else {
                ++left;
            }
        }
        return s;
    }
};
// @lc code=end

