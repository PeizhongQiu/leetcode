class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> all;
        int max = 0;
        for(int i = 0; i < matrix.size(); ++i) {

            string temp1 = "";
            string temp2 = "";
            for(int j = 0; j < matrix[0].size(); ++j) {
                temp1 += (char)('0' + matrix[i][j]);
                temp2 += (char)('0' + 1 - matrix[i][j]);
            }
            ++all[temp1];
            ++all[temp2];
            if(all[temp2] > max) {
                max = all[temp2];
            }
        }
        return max;
    }
};