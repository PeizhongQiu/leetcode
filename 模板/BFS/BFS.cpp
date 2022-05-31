/**
 * @file BFS.cpp
 * @author littleQiu
 * 图采用 unordered_map<string, vector<string>> graph; 来存储;
 * @version 0.1
 * @date 2022-05-31
 * 
 * @copyright Copyright (c) 2022
 */
unordered_map<string, vector<string>> graph;
/**
 * 判断是否存在从 a 到 b 的一条路径
 * 
 * @param a 
 * @param b 
 */
bool BFS(string a, string b) {
    unordered_map<string, int> visit; 
    visit[a] = 1;
    queue<string> q;
    q.push(a);
    while(!q.empty()){
        string top = q.front();
        q.pop();
        if(top == b) {
            return true;
        }
        for(int i = 0; i < graph[top].size(); ++i) {
            if(visit.find(graph[top][i]]) == visit.end()) {
                visit[graph[top][i]] = 1;
                q.push(graph[top][i]);
            }
        }
    }
    return false;
}
/**
 * @param edge : vector<string> 是一个只有两个元素的数组，代表 from 到 to 的一条边。
 */
void buildGraph(vector<vector<string>>& edges) {
    for(auto &edge : edges) {
        graph[edge[0]].push_back(edge[1]);
        /**
         * 如果是无向边，则还要添加以下一条语句：
         * graph[edge[1]].push_back(edge[0]);
         */
    }
}
