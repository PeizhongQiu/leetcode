/*
 * @lc app=leetcode.cn id=856 lang=cpp
 *
 * [856] 括号的分数
 *
 * https://leetcode-cn.com/problems/score-of-parentheses/description/
 *
 * algorithms
 * Medium (62.94%)
 * Likes:    271
 * Dislikes: 0
 * Total Accepted:    18.3K
 * Total Submissions: 29K
 * Testcase Example:  '"()"'
 *
 * 给定一个平衡括号字符串 S，按下述规则计算该字符串的分数：
 * 
 * 
 * () 得 1 分。
 * AB 得 A + B 分，其中 A 和 B 是平衡括号字符串。
 * (A) 得 2 * A 分，其中 A 是平衡括号字符串。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入： "()"
 * 输出： 1
 * 
 * 
 * 示例 2：
 * 
 * 输入： "(())"
 * 输出： 2
 * 
 * 
 * 示例 3：
 * 
 * 输入： "()()"
 * 输出： 2
 * 
 * 
 * 示例 4：
 * 
 * 输入： "(()(()))"
 * 输出： 6
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * S 是平衡括号字符串，且只含有 ( 和 ) 。
 * 2 <= S.length <= 50
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        
        st.push(0);
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == '(') {
                st.push(0);
            } else {
                int top1 = st.top();
                st.pop();
                int top2 = st.top();
                st.pop();
                st.push(top2 + max(1, 2 * top1));
            }
            
        }
        
        return st.top();
    }
};
// @lc code=end

