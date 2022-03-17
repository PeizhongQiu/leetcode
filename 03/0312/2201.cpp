//284-2
class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
        int x[1000][1000];
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j) {
                x[i][j] = -1;
            }
        }
        bool visit[1000][1000] = {false};
        for(int i = 0; i < artifacts.size(); ++i) {
            for(int j = artifacts[i][0]; j <= artifacts[i][2]; ++j) {
                for(int k = artifacts[i][1]; k <= artifacts[i][3]; ++k) {
                    x[j][k] = i;
                }
            }
        }
        
        
        int ret = 0;
        for(int i = 0; i < dig.size(); ++i) {
            visit[dig[i][0]][dig[i][1]] = true;
            int index = x[dig[i][0]][dig[i][1]];
            int ok = 1;
            if(index == -1) {
                continue;
            }
            for(int j = artifacts[index][0]; j <= artifacts[index][2]; ++j) {
                for(int k = artifacts[index][1]; k <= artifacts[index][3]; ++k) {
                    if(visit[j][k] == false) {
                        ok = 0;
                        break;
                    }
                }
                if(ok == 0) {
                    break;
                }
            }
            if(ok) {
                ++ret;
            }
        }
        return ret;
    }
};