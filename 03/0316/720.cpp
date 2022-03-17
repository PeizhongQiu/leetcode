/*
 * @lc app=leetcode.cn id=720 lang=cpp
 *
 * [720] 词典中最长的单词
 *
 * https://leetcode-cn.com/problems/longest-word-in-dictionary/description/
 *
 * algorithms
 * Easy (48.40%)
 * Likes:    270
 * Dislikes: 0
 * Total Accepted:    47.4K
 * Total Submissions: 92.3K
 * Testcase Example:  '["w","wo","wor","worl","world"]'
 *
 * 给出一个字符串数组 words 组成的一本英语词典。返回 words 中最长的一个单词，该单词是由 words 词典中其他单词逐步添加一个字母组成。
 * 
 * 若其中有多个可行的答案，则返回答案中字典序最小的单词。若无答案，则返回空字符串。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：words = ["w","wo","wor","worl", "world"]
 * 输出："world"
 * 解释： 单词"world"可由"w", "wo", "wor", 和 "worl"逐步添加一个字母组成。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：words = ["a", "banana", "app", "appl", "ap", "apply", "apple"]
 * 输出："apple"
 * 解释："apply" 和 "apple" 都能由词典中的单词组成。但是 "apple" 的字典序小于 "apply" 
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= words.length <= 1000
 * 1 <= words[i].length <= 30
 * 所有输入的字符串 words[i] 都只包含小写字母。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(),words.end());

        int maxLength = 0;
        string ret = "";
        int lastLength = 0;

        for(int i = 0; i < words.size(); ++i) {
            if(lastLength == 0) {
                if(words[i].size() == 1) {
                    lastLength = 1;
                }
            } else {
                if(words[i].size() == lastLength + 1 && words[i].substr(0,lastLength) == words[i-1].substr(0,lastLength)) {
                    ++lastLength;
                } else if(words[i].size() == 1) {
                    lastLength = 1;
                } else {
                    for(int j = 0; j < lastLength; ++j) {
                        if(words[i][j] != words[i-1][j]) {
                            if(j == 0) {
                                lastLength = 0;
                            } else {
                                lastLength = j + 1;
                            }
                            
                            break;
                        }
                    }

                }
            }
            //cout << words[i] << " " << lastLength << endl;
            if(lastLength > maxLength) {
                maxLength = lastLength;
                ret = words[i];
            }
        }
        return ret;
    }
};
// @lc code=end

