class Solution {
public:
    int minimumFinishTime(vector<vector<int>>& tires, int changeTime, int numLaps) {
        vector<long long> best(18, INT_MAX);
        int maxBest = 0;
        for(auto tire : tires) {
            
            long long cur = tire[0];
            long long lap = tire[0];
            
            for(int i = 1; lap < changeTime + tire[0]; ++i) {
                best[i] = min(best[i], cur);
                lap *= tire[1];
                cur = cur + lap;
                
                maxBest = max(maxBest, i);
            }

        }

        vector<long long> dp(numLaps + 1, INT_MAX);
        dp[0] = 0;
        for(int i = 1; i <= numLaps; ++i) {
            for(int j = i - 1; j >= 0 && i - j <= maxBest; --j) {
                dp[i] = min(dp[i], dp[j] + changeTime + best[i-j]);
            }
        }

        return dp[numLaps] - changeTime;
    }
};
