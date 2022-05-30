class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        vector<vector<int>> dp (n, vector<int> (m, INT_MAX));
        
        vector<int> pre(n+1, 0);
        pre[0] = 0;
        for(int i = 0; i < n; ++i) {
            pre[i+1] = pre[i] + nums[i];
        }
        
        for(int i = 0; i < n; ++i) {

            for(int j = 0; j < min(m, i+1); ++j) {
                if(j == 0) {
                    dp[i][j] = pre[i+1];
                    //cout << i << " " << j << " " << dp[i][j] << endl;
                    continue;
                }
                for(int k = j - 1; k < i; ++k) {
                    dp[i][j] = min(dp[i][j], max(dp[k][j-1], pre[i+1]-pre[k+1]));
                    //cout << i << " " << j << " " << dp[i][j] << endl;
                }
            }
        }

        return dp[n-1][m-1];
    }
};