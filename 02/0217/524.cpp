/*
 * @lc app=leetcode.cn id=524 lang=cpp
 *
 * [524] 通过删除字母匹配到字典里最长单词
 *
 * https://leetcode-cn.com/problems/longest-word-in-dictionary-through-deleting/description/
 *
 * algorithms
 * Medium (49.75%)
 * Likes:    287
 * Dislikes: 0
 * Total Accepted:    79.6K
 * Total Submissions: 160K
 * Testcase Example:  '"abpcplea"\n["ale","apple","monkey","plea"]'
 *
 * 给你一个字符串 s 和一个字符串数组 dictionary ，找出并返回 dictionary 中最长的字符串，该字符串可以通过删除 s
 * 中的某些字符得到。
 * 
 * 如果答案不止一个，返回长度最长且字母序最小的字符串。如果答案不存在，则返回空字符串。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "abpcplea", dictionary = ["ale","apple","monkey","plea"]
 * 输出："apple"
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "abpcplea", dictionary = ["a","b","c"]
 * 输出："a"
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 1000
 * 1 <= dictionary.length <= 1000
 * 1 <= dictionary[i].length <= 1000
 * s 和 dictionary[i] 仅由小写英文字母组成
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    static bool cmp(string a, string b) {
        if(a.size() != b.size()) return a.size() > b.size();
        else return a < b;
    }

    bool isMatch(string s, string a) {
        int i = 0, j = 0;
        while(i < s.size() && j < a.size()) {
            if(s[i] == a[j]) {
                ++i;
                ++j;
            } else {
                ++i;
            }
        }
        if(j == a.size()) return true;
        else return false;
    }
    string findLongestWord(string s, vector<string>& dictionary) {
        sort(dictionary.begin(), dictionary.end(), Solution::cmp);
        for(int i = 0; i < dictionary.size(); i++) {
            if(isMatch(s, dictionary[i])) {
                return dictionary[i];
            }
        }
        return "";
    }
};
// @lc code=end

