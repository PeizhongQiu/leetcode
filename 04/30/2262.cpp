class Solution {
public:
    long long appealSum(string s) {
        long long ret = 0;
        unordered_map<char, int> index;
        long long dp[100005];
        dp[0] = 1;
        index[s[0]] = 0;
        for(int i = 1; i < s.size(); ++i) {
            if(index.count(s[i]) == 0) {
                dp[i] = dp[i-1] + i + 1;
            } else {
                dp[i] = dp[i - 1] + i - index[s[i]];
            }
            index[s[i]] = i;
        }
        for(int i = 0; i < s.size(); ++i) {
            //cout << dp[i] << endl;
            ret += dp[i];
        }
        return ret;
    }
};