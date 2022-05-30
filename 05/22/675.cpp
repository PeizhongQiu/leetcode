class Solution {
public:
    int BFS(int& row, int& line, int target, vector<vector<int>>& forest) {
        int m = forest.size();
        int n = forest[0].size();
        vector<vector<int>> visit(m, vector<int>(n,0));
        queue<pair<int,int>> s;
        s.push({row, line});
        int ret = 0;
        int length = 1;
        while(!s.empty()) {
            
            for(int i = 0; i < length; ++i) {
                pair<int, int> top = s.front();
                s.pop();
                if(forest[top.first][top.second] == target) {
                    row = top.first;
                    line = top.second;
                    return ret;
                }
                if(top.first < m - 1 && visit[top.first+1][top.second] == 0 && forest[top.first+1][top.second] > 0) {
                    visit[top.first+1][top.second] = 1;
                    s.push({top.first + 1, top.second});
                }
                if(top.first > 0 && visit[top.first-1][top.second] == 0 && forest[top.first-1][top.second] > 0) {
                    visit[top.first-1][top.second] = 1;
                    s.push({top.first - 1, top.second});
                }
                if(top.second < n - 1 && visit[top.first][top.second+1] == 0 && forest[top.first][top.second+1] > 0) {
                    visit[top.first][top.second+1] = 1;
                    s.push({top.first, top.second + 1});
                }
                if(top.second > 0 && visit[top.first][top.second - 1] == 0 && forest[top.first][top.second - 1] > 0) {
                    visit[top.first][top.second-1] = 1;
                    s.push({top.first, top.second - 1});
                }
            }
            ++ret;
            length = s.size();
        }

        return -1;
    }
    int cutOffTree(vector<vector<int>>& forest) {
        vector<int> data;
        for(int i = 0; i < forest.size(); ++i) {
            for(int j = 0; j < forest[i].size(); ++j) {
                if(forest[i][j] > 1)
                    data.push_back(forest[i][j]);
            }
        }
        sort(data.begin(),data.end());
        int ret = 0;
        int row = 0;
        int line = 0;
        for(auto c : data) {
            int temp = BFS(row, line, c, forest);
            //cout << c << " " << temp << endl;
            if(temp < 0) return -1;
            else {
                ret += temp;
            }
        }
        return ret;
    }
};