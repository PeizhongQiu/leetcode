class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> str;
        for(auto s : strs) {
            vector<int> num(2,0);
            for(auto c : s) {
                num[c-'0']++;
            }
            str.push_back(num);
        }
        int dp[601][101][101] = {0};
        for(int i = strs.size() - 1; i >= 0; --i) {
            for(int j = 0; j <= m; ++j) {
                for(int k = 0; k <= n; ++k) {
                    if(str[i][0] > j || str[i][1] > k) {
                        dp[i][j][k] = dp[i+1][j][k];
                    } else {
                        dp[i][j][k] = max(1 + dp[i+1][j-str[i][0]][k-str[i][1]], dp[i + 1][j][k]);
                    }
                }
            }
        }
        return dp[0][m][n];
    }
};