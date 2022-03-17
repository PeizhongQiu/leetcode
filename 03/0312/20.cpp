/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 *
 * https://leetcode-cn.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (44.55%)
 * Likes:    3071
 * Dislikes: 0
 * Total Accepted:    974.8K
 * Total Submissions: 2.2M
 * Testcase Example:  '"()"'
 *
 * 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
 * 
 * 有效字符串需满足：
 * 
 * 
 * 左括号必须用相同类型的右括号闭合。
 * 左括号必须以正确的顺序闭合。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "()"
 * 输出：true
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "()[]{}"
 * 输出：true
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：s = "(]"
 * 输出：false
 * 
 * 
 * 示例 4：
 * 
 * 
 * 输入：s = "([)]"
 * 输出：false
 * 
 * 
 * 示例 5：
 * 
 * 
 * 输入：s = "{[]}"
 * 输出：true
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * s 仅由括号 '()[]{}' 组成
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        stack<char> s1;
        if(s[0] == '(' || s[0] == '{' || s[0] == '[') {
            s1.push(s[0]);
        } else {
            return false;
        }
        int index = 1;
        while(!s1.empty() || index < s.size()) {
            if(s[index] == '(' || s[index] == '{' || s[index] == '[') {
                s1.push(s[index]);
            } else {
                if(s1.empty()) {
                    return false;
                } else if(s1.top() == '(' && s[index] == ')') {
                    s1.pop();
                } else if(s1.top() == '[' && s[index] == ']') {
                    s1.pop();
                } else if(s1.top() == '{' && s[index] == '}') {
                    s1.pop();
                } else {
                    return false;
                }
            }
            ++index;
            if(index >= s.size()) {
                break;
            }
        }
        if(s1.empty())
            return true;
        return false;
    }
};
// @lc code=end

