/*
 * @lc app=leetcode.cn id=1189 lang=cpp
 *
 * [1189] “气球” 的最大数量
 *
 * https://leetcode-cn.com/problems/maximum-number-of-balloons/description/
 *
 * algorithms
 * Easy (68.76%)
 * Likes:    109
 * Dislikes: 0
 * Total Accepted:    51.7K
 * Total Submissions: 75.1K
 * Testcase Example:  '"nlaebolko"'
 *
 * 给你一个字符串 text，你需要使用 text 中的字母来拼凑尽可能多的单词 "balloon"（气球）。
 * 
 * 字符串 text 中的每个字母最多只能被使用一次。请你返回最多可以拼凑出多少个单词 "balloon"。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 输入：text = "nlaebolko"
 * 输出：1
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 输入：text = "loonbalxballpoon"
 * 输出：2
 * 
 * 
 * 示例 3：
 * 
 * 输入：text = "leetcode"
 * 输出：0
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= text.length <= 10^4
 * text 全部由小写英文字母组成
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int freqB = 0;
        int freqA = 0;
        int freqL = 0;
        int freqO = 0;
        int freqN = 0;
        for(int i = 0; i < text.size(); i++) {
            if(text[i] == 'b') ++freqB;
            if(text[i] == 'a') ++freqA;
            if(text[i] == 'l') ++freqL;
            if(text[i] == 'o') ++freqO;
            if(text[i] == 'n') ++freqN;
        }
        int min = freqB;
        min = min < freqA ? min : freqA;
        min = min < freqL/2 ? min : freqL/2;
        min = min < freqO/2 ? min : freqO/2;
        min = min < freqN ? min : freqN;
        
        return min;
    }
};
// @lc code=end

