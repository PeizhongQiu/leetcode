class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int ans = intervals.size();
        for(int i = 0; i < intervals.size(); ++i) {
            for(int j = 0; j < intervals.size(); ++j) {
                if (i != j && intervals[j][0] <= intervals[i][0] && intervals[i][1] <= intervals[j][1]) {
                    --ans;
                    break;
                }
            }
        }
        return ans;
    }
};