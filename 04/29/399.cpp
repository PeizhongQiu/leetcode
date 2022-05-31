class Solution {
public:
    double calc(string a, string b, unordered_map<string, vector<pair<string, double>>>& graph) {
        unordered_map<string, int> visit; 
        visit[a] = 1;
        queue<pair<string, double>> q;
        q.push({a,1});
        while(!q.empty()){
            pair<string, double> top = q.front();
            q.pop();
            if(top.first == b) {
                return top.second;
            }
            for(int i = 0; i < graph[top.first].size(); ++i) {
                if(visit.find(graph[top.first][i].first) == visit.end()) {
                    visit[graph[top.first][i].first] = 1;
                    q.push({graph[top.first][i].first, graph[top.first][i].second * top.second});
                }
            }
        }
        return -1;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> graph;
        for(int i = 0; i < equations.size(); ++i) {
            graph[equations[i][0]].push_back({equations[i][1],values[i]});
            graph[equations[i][1]].push_back({equations[i][0],1/values[i]});
        }
        vector<double> ret;
        for(auto query : queries) {
            if(graph.find(query[0]) == graph.end() || graph.find(query[1]) == graph.end()) {
                ret.push_back(-1);
            } else {
                ret.push_back(calc(query[0], query[1], graph));
            }
            
        }
        return ret;
    }
};