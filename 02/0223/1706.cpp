class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> ret;
        for(int i = 0; i < n; ++i) {
            ret.push_back(i);
        }
        for(int i = 0; i < m; ++i) {

            for(int j = 0; j < n; ++j) {
                if(ret[j] == -1) {
                    continue;
                }
                if(grid[i][ret[j]] == 1) {
                    if(ret[j] == n - 1 || grid[i][ret[j] + 1] == -1) {
                        ret[j] = -1;
                    } else {
                        ret[j]++;
                    }
                } else {
                    if(ret[j] == 0 || grid[i][ret[j] - 1] == 1) {
                        ret[j] = -1;
                    } else {
                        ret[j]--;
                    }
                }
                //cout << ret[j] <<" ";
            }
            //cout << endl;
        }
        return ret;
    }
};