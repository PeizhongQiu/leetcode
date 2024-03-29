/*
 * @lc app=leetcode.cn id=2055 lang=cpp
 *
 * [2055] 蜡烛之间的盘子
 *
 * https://leetcode-cn.com/problems/plates-between-candles/description/
 *
 * algorithms
 * Medium (38.92%)
 * Likes:    51
 * Dislikes: 0
 * Total Accepted:    7.4K
 * Total Submissions: 17.3K
 * Testcase Example:  '"**|**|***|"\n[[2,5],[5,9]]'
 *
 * 给你一个长桌子，桌子上盘子和蜡烛排成一列。给你一个下标从 0 开始的字符串 s ，它只包含字符 '*' 和 '|' ，其中 '*' 表示一个 盘子
 * ，'|' 表示一支 蜡烛 。
 * 
 * 同时给你一个下标从 0 开始的二维整数数组 queries ，其中 queries[i] = [lefti, righti] 表示 子字符串
 * s[lefti...righti] （包含左右端点的字符）。对于每个查询，你需要找到 子字符串中 在 两支蜡烛之间 的盘子的 数目 。如果一个盘子在
 * 子字符串中 左边和右边 都 至少有一支蜡烛，那么这个盘子满足在 两支蜡烛之间 。
 * 
 * 
 * 比方说，s = "||**||**|*" ，查询 [3, 8] ，表示的是子字符串 "*||**|" 。子字符串中在两支蜡烛之间的盘子数目为 2
 * ，子字符串中右边两个盘子在它们左边和右边 都 至少有一支蜡烛。
 * 
 * 
 * 请你返回一个整数数组 answer ，其中 answer[i] 是第 i 个查询的答案。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 
 * 输入：s = "**|**|***|", queries = [[2,5],[5,9]]
 * 输出：[2,3]
 * 解释：
 * - queries[0] 有两个盘子在蜡烛之间。
 * - queries[1] 有三个盘子在蜡烛之间。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 
 * 输入：s = "***|**|*****|**||**|*", queries =
 * [[1,17],[4,5],[14,17],[5,11],[15,16]]
 * 输出：[9,0,0,0,0]
 * 解释：
 * - queries[0] 有 9 个盘子在蜡烛之间。
 * - 另一个查询没有盘子在蜡烛之间。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 3 <= s.length <= 10^5
 * s 只包含字符 '*' 和 '|' 。
 * 1 <= queries.length <= 10^5
 * queries[i].length == 2
 * 0 <= lefti <= righti < s.length
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        vector<int> nextCandle(s.size() + 2, 0);
        vector<int> leftNextCandle(s.size() + 2, 0);
        vector<int> rightCandleNum(s.size() + 2, 0);
        rightCandleNum[s.size() + 1] = 0;

        int next = s.size();
        for(int i = s.size(); i > 0; --i) {
            nextCandle[i] = next;
            if(s[i-1] == '|') {
                next = i-1;
                rightCandleNum[i] = rightCandleNum[i+1] + 1;
            } else {
                rightCandleNum[i] = rightCandleNum[i+1];
            }
        }
        nextCandle[0] = next;

        next = 0;
        for(int i = 1; i <= s.size(); ++i) {
            leftNextCandle[i] = next;
            if(s[i-1] == '|') {
                next = i - 1;
            } 
        }
        leftNextCandle[s.size() + 1] = next;

        vector<int> ret;
        for(int i = 0; i < queries.size(); ++i) {
            int left = queries[i][0];
            int right = queries[i][1];
            int candleNum = rightCandleNum[left + 1] - rightCandleNum[right + 2];
            //cout << candleNum << endl;
            int length = leftNextCandle[right + 2] - nextCandle[left] + 1;
            //cout << leftNextCandle[right + 2] << " " << nextCandle[left] << endl;
           
            if(length < 0) {
                ret.push_back(0);
            } else {
                ret.push_back(length - candleNum);
            }
            
        }
        return ret;
    }
};
// @lc code=end

