class Solution {
public:
    bool isPrintable(vector<vector<int>>& targetGrid) {
        int color[61][4];
        for(int i = 0; i < 61; ++i) {
            color[i][0] = INT_MAX;
            color[i][1] = 0;
            color[i][2] = INT_MAX;
            color[i][3] = 0;
        }
        int m = targetGrid.size();
        int n = targetGrid[0].size();
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                color[targetGrid[i][j]][0] = min(color[targetGrid[i][j]][0], i);
                color[targetGrid[i][j]][1] = max(color[targetGrid[i][j]][1], i);
                color[targetGrid[i][j]][2] = min(color[targetGrid[i][j]][2], j);
                color[targetGrid[i][j]][3] = max(color[targetGrid[i][j]][3], j);
            }
        }
        vector<unordered_set<int>> graph(61);
        vector<int> in(61,0);
        for(int i = 1; i <= 60; ++i) {
            for(int j = color[i][0]; j <= color[i][1]; ++j) {
                for(int k = color[i][2]; k <= color[i][3]; ++k) {
                    if(targetGrid[j][k] != i && graph[i].find(targetGrid[j][k]) == graph[i].end()) {
                        graph[i].insert(targetGrid[j][k]);
                        ++in[targetGrid[j][k]];
                    }
                }
            }
        }
        queue<int> q;
        int num = 0;
        for(int i = 1; i <= 60; ++i) {
            //cout << in[i] << " ";
            if(in[i] == 0) {
                q.push(i);
                ++num;
            }
        }
        //cout << endl;
        while(!q.empty()) {
            int top = q.front();
            q.pop();
            for(auto iter = graph[top].begin(); iter != graph[top].end(); ++iter) {
                --in[*iter];
                if(in[*iter] == 0) {
                    q.push(*iter);
                    ++num;
                }
            }
        }
        //cout << num << endl;
        if(num == 60) {
            return true;
        } else return false;
    }
};