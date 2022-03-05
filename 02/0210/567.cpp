/*
 * @lc app=leetcode.cn id=567 lang=cpp
 *
 * [567] 字符串的排列
 *
 * https://leetcode-cn.com/problems/permutation-in-string/description/
 *
 * algorithms
 * Medium (43.62%)
 * Likes:    591
 * Dislikes: 0
 * Total Accepted:    160.8K
 * Total Submissions: 368.5K
 * Testcase Example:  '"ab"\n"eidbaooo"'
 *
 * 给你两个字符串 s1 和 s2 ，写一个函数来判断 s2 是否包含 s1 的排列。如果是，返回 true ；否则，返回 false 。
 * 
 * 换句话说，s1 的排列之一是 s2 的 子串 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s1 = "ab" s2 = "eidbaooo"
 * 输出：true
 * 解释：s2 包含 s1 的排列之一 ("ba").
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s1= "ab" s2 = "eidboaoo"
 * 输出：false
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s1.length, s2.length <= 10^4
 * s1 和 s2 仅包含小写字母
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> diff;
        int n = s1.size();
        for(int i = 0; i < n; i++) {
            if(diff.count(s1[i]) == 0) {
                diff[s1[i]] = 1;
            } else {
                ++diff[s1[i]];
            }
        }
        for(int i = 0; i < s2.size(); i++) {
            if(diff.count(s2[i]) == 0) {
                diff[s2[i]] = -1;
            } else {
                --diff[s2[i]];
                if(diff[s2[i]] == 0) {
                    diff.erase(s2[i]);
                }
            }
            if(i >= n) {
                if(diff.count(s2[i-n]) == 0) {
                    diff[s2[i-n]] = 1;
                } else {
                    ++diff[s2[i-n]];
                    if(diff[s2[i-n]] == 0) {
                        diff.erase(s2[i-n]);
                    }
                }
            }
            if(diff.size() == 0) return true;
        }
        return false;
    }
};
// @lc code=end

