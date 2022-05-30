class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ret;
        int x = 0;
        for(int i = 0; i < intervals.size(); ++i) {
            if(intervals[i][1] < newInterval[0]) {
                ret.push_back(intervals[i]);
            } else if(intervals[i][0] > newInterval[1]) {
                if(x == 0) {
                    ret.push_back(newInterval);
                    x = 1;
                }
                ret.push_back(intervals[i]);
            } else {
                newInterval[0] = min(intervals[i][0], newInterval[0]);
                newInterval[1] = max(intervals[i][1], newInterval[1]);
            }
        }
        if(x == 0) {
            ret.push_back(newInterval);
        }
        return ret;
    }
};