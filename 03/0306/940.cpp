/*
 * @lc app=leetcode.cn id=940 lang=cpp
 *
 * [940] 不同的子序列 II
 *
 * https://leetcode-cn.com/problems/distinct-subsequences-ii/description/
 *
 * algorithms
 * Hard (42.80%)
 * Likes:    114
 * Dislikes: 0
 * Total Accepted:    5.7K
 * Total Submissions: 13.3K
 * Testcase Example:  '"abc"'
 *
 * 给定一个字符串 s，计算 s 的 不同非空子序列 的个数。因为结果可能很大，所以返回答案需要对 10^9 + 7 取余 。
 * 
 * 字符串的 子序列 是经由原字符串删除一些（也可能不删除）字符但不改变剩余字符相对位置的一个新字符串。
 * 
 * 
 * 例如，"ace" 是 "abcde" 的一个子序列，但 "aec" 不是。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "abc"
 * 输出：7
 * 解释：7 个不同的子序列分别是 "a", "b", "c", "ab", "ac", "bc", 以及 "abc"。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "aba"
 * 输出：6
 * 解释：6 个不同的子序列分别是 "a", "b", "ab", "ba", "aa" 以及 "aba"。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：s = "aaa"
 * 输出：3
 * 解释：3 个不同的子序列分别是 "a", "aa" 以及 "aaa"。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 2000
 * s 仅由小写英文字母组成
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int distinctSubseqII(string s) {
        vector<long long> ret;
        ret.push_back(1);
        
        for(int i = 1; i <= s.size(); ++i) {
            int ok = 0;
            for(int j = i - 1; j > 0; --j) {
                if(s[i-1] == s[j-1]) {
                    
                    ok = j;
                    break;
                }
            }
            //cout << ok << " " ;
            if(ok) {
                ret.push_back((2 * ret[i-1] - ret[ok-1]) % 1000000007);
            } else {
                ret.push_back(2 * ret[i-1] % 1000000007);
            }
            //cout << ret[i] << endl;
        }
        return ret[s.size()] - 1 > 0 ? ret[s.size()] - 1 : ret[s.size()] - 1 + 1000000007;
    }
};
// @lc code=end

