/*
 * @lc app=leetcode.cn id=767 lang=cpp
 *
 * [767] 重构字符串
 *
 * https://leetcode-cn.com/problems/reorganize-string/description/
 *
 * algorithms
 * Medium (47.84%)
 * Likes:    389
 * Dislikes: 0
 * Total Accepted:    43K
 * Total Submissions: 89.9K
 * Testcase Example:  '"aab"'
 *
 * 给定一个字符串 s ，检查是否能重新排布其中的字母，使得两相邻的字符不同。
 * 
 * 返回 s 的任意可能的重新排列。若不可行，返回空字符串 "" 。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: s = "aab"
 * 输出: "aba"
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: s = "aaab"
 * 输出: ""
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 <= s.length <= 500
 * s 只包含小写字母
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string reorganizeString(string s) {
        vector<int> freq(26,0);
        for(int i = 0; i < s.size(); ++i) {
            ++freq[s[i]-'a'];
        }
        
        string ret = "";
        for(int i = 0; i < s.size(); ++i) {
            auto iter = max_element (freq.begin(),freq.end());
            int index = iter - freq.begin();
            if(ret.size() == 0 || ret[i-1] - 'a' != index) {
                ret += (char)(index + 'a');
                --*iter;
                //cout << ret << endl;
            } else {
                int temp = *iter;
                *iter = 0;
                auto iter2 = max_element (freq.begin(),freq.end());
                if(*iter2 == 0) {
                    return "";
                }
                int index = iter2 - freq.begin();
                *iter = temp;
                ret += (char)(index + 'a');
                --*iter2;
                
                //cout << ret << endl;
            }
        }
        return ret;
    }
};
// @lc code=end

