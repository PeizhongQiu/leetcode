/*
 * @lc app=leetcode.cn id=784 lang=cpp
 *
 * [784] 字母大小写全排列
 *
 * https://leetcode-cn.com/problems/letter-case-permutation/description/
 *
 * algorithms
 * Medium (69.36%)
 * Likes:    365
 * Dislikes: 0
 * Total Accepted:    56.1K
 * Total Submissions: 80.8K
 * Testcase Example:  '"a1b2"'
 *
 * 给定一个字符串 s ，通过将字符串 s 中的每个字母转变大小写，我们可以获得一个新的字符串。
 * 
 * 返回 所有可能得到的字符串集合 。以 任意顺序 返回输出。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "a1b2"
 * 输出：["a1b2", "a1B2", "A1b2", "A1B2"]
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: s = "3z4"
 * 输出: ["3z4","3Z4"]
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 <= s.length <= 12
 * s 由小写英文字母、大写英文字母和数字组成
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        unordered_set<string> ret;
        ret.insert(s);
        for(int i = 0; i < (1 << s.size()); ++i) {
            string temp = s;
            int ok = 0;
            for(int j = 0; j < s.size(); j++){
                if(i & (1 << j)) {
                    if(temp[j] >= 'a' && temp[j] <= 'z') {
                        temp[j] = 'A' + temp[j] - 'a';
                        ok = 1;
                    } else if(temp[j] >= 'A' && temp[j] <= 'Z') {
                        temp[j] = 'a' + temp[j] - 'A';
                        ok = 1;
                    }
                }
            }
            if(ok)
                ret.insert(temp);
        }
        vector<string> ret2;
        for(auto iter = ret.begin(); iter!=ret.end(); ++iter) {
            ret2.push_back(*iter);
        }
        return ret2;
    }
};
// @lc code=end

