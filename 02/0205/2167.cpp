/**************************************************************************************************
移除所有载有违禁货物车厢所需的最少时间（279次 leetcode 周赛第四题）

算法思想：
    我们可以将数组分成三个部分：前缀，中间，后缀，每个部分的长度可以为 0。
    dp[i][0] 来表示如果 s[i] 处于前缀花费的时间
    dp[i][1] 来表示如果 s[i] 处于中间花费的时间
    dp[i][2] 来表示如果 s[i] 处于后缀花费的时间
    那么，根据题意，dp[i][0] 恒等于 i；
    dp[i][1] 等于 dp[i-1][0] 和 dp[i-1][1] 的最小值加上本次移动的开销；
    dp[i][2] 有两种情况，
        一是已经在后缀，则与 dp[i-1][2] 相等；
        二是不在后缀，则为 dp[i-1][0], dp[i-1][1] 的最小值加上后缀的开销。
    最终返回的值就是 dp[s.size()][0]，dp[s.size()][1]，dp[s.size()][2] 三者的最小值。
**************************************************************************************************/

class Solution {
public:
    int minimumTime(string s) {
        int dp[200010][3] = {0};
        dp[0][2] = s.size();
        for(int i = 1; i <= s.size(); i++) {
            dp[i][0] = i;
            dp[i][1] = min(dp[i-1][0], dp[i-1][1]) + 2 * (s[i-1] - '0');
            int min2 = min(dp[i-1][0], dp[i-1][1]) + s.size() - i + 1;
            dp[i][2] = min(min2, dp[i-1][2]);
        }
        int result = min(min(dp[s.size()][0], dp[s.size()][1]), dp[s.size()][2]);
        return result;
    }
};