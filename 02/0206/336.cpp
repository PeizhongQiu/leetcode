/*
 * @lc app=leetcode.cn id=336 lang=cpp
 *
 * [336] 回文对
 *
 * https://leetcode-cn.com/problems/palindrome-pairs/description/
 *
 * algorithms
 * Hard (39.80%)
 * Likes:    306
 * Dislikes: 0
 * Total Accepted:    24.4K
 * Total Submissions: 61.9K
 * Testcase Example:  '["abcd","dcba","lls","s","sssll"]'
 *
 * 给定一组 互不相同 的单词， 找出所有 不同 的索引对 (i, j)，使得列表中的两个单词， words[i] + words[j]
 * ，可拼接成回文串。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：words = ["abcd","dcba","lls","s","sssll"]
 * 输出：[[0,1],[1,0],[3,2],[2,4]] 
 * 解释：可拼接成的回文串为 ["dcbaabcd","abcddcba","slls","llssssll"]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：words = ["bat","tab","cat"]
 * 输出：[[0,1],[1,0]] 
 * 解释：可拼接成的回文串为 ["battab","tabbat"]
 * 
 * 示例 3：
 * 
 * 
 * 输入：words = ["a",""]
 * 输出：[[0,1],[1,0]]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 0 
 * words[i] 由小写英文字母组成
 * 
 * 
 */

// @lc code=start
class Solution {
public:
#define REV 2
#define SEQ 4
    struct tie{
        int flag = 0;
        int rev = 0;
        int seq = 0;
        int index[26] = {0};
    };
    vector<tie> data;
    void insert(string s, int flag, int num) {
        int index = 0;
        for(int i = 0; i < s.size(); ++i) {
            if(data[index].index[s[i]-'a'] == 0) {
                tie temp;
                data.push_back(temp);
                data[index].index[s[i]-'a'] = data.size() - 1;
            }
            index = data[index].index[s[i]-'a'];
            //cout << index << endl;
        }
        data[index].flag |= flag;
        if(flag == REV) {
            data[index].rev = num;
        } else {
            data[index].seq = num;
        }
    }
    bool isPalindrome(string s) {
        int n = s.size();
        for(int i = 0; i < n/2; ++i) {
            if(s[i] != s[n-1-i]) return false;
        }
        return true;
    }
    
    vector<vector<int>> palindromePairs(vector<string>& words) {
        tie temp;
        data.push_back(temp);
        for(int i = 0; i < words.size(); ++i) {
            insert(words[i], SEQ, i);
            reverse(words[i].begin(), words[i].end());
            insert(words[i], REV, i);
        }
        vector<vector<int>> ans;
        for(int i = 0; i < words.size(); ++i) {
            cout << words[i] << endl;
            int index = 0;
            for(int j = 0; j < words[i].size(); ++j) {
                if((data[index].flag & SEQ) != 0) {
                    if(isPalindrome(words[i].substr(j))) {
                        vector<int> temp{data[index].seq,i};
                        ans.push_back(temp);
                    }
                    //cout << j << endl;
                }
                index = data[index].index[words[i][j]-'a'];
            }
            if((data[index].flag & SEQ) != 0 && data[index].seq < i) {
                vector<int> temp{data[index].seq,i};
                ans.push_back(temp);
                //cout << "last" << endl;
            }

            reverse(words[i].begin(), words[i].end());
            index = 0;
            for(int j = 0; j < words[i].size(); ++j) {
                if((data[index].flag & REV) != 0) {
                    if(isPalindrome(words[i].substr(j))) {
                        vector<int> temp{i, data[index].rev};
                        ans.push_back(temp);
                    }
                }
                index = data[index].index[words[i][j]-'a'];
            }
            if((data[index].flag & REV) != 0 && data[index].rev < i) {
                vector<int> temp{i, data[index].rev};
                ans.push_back(temp);
            }
        }
        return ans;
    }
};
// @lc code=end

