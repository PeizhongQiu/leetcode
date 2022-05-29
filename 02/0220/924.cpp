class Solution {
public:
    vector<int> parent;
    vector<int> count;
    int root(int a) {
        if(parent[a] == a) return a;
        return root(parent[a]);
    }
    void Union(int a, int b) {
        int ar = root(a);
        int br = root(b);
        if(ar == br) return ;
        parent[ar] = br;
        count[br] += count[ar];
    }
    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        int n = graph.size();
        for(int i = 0; i < n; ++i) {
            parent.push_back(i);
            count.push_back(1);
        }
        for(int i = 0; i < n; ++i) {
            for(int j = i; j < n; ++j) {
                if(graph[i][j] == 1) {
                    Union(i,j);
                }
            }
        }
        
        sort(initial.begin(),initial.end());
        map<int,vector<int>> initialGroup;
        for(auto &i : initial) {
            initialGroup[root(i)].push_back(i);
            //cout << root(i) << endl;
        }
        int maxNode = 0;
        int ans = initial[0];
        for(auto iter = initialGroup.begin(); iter != initialGroup.end(); iter++) {
            if(iter->second.size() == 1) {
                if(count[root(iter->second[0])] > maxNode) {
                    ans = iter->second[0];
                    maxNode = count[root(iter->second[0])];
                } else if(count[root(iter->second[0])] == maxNode && iter->second[0] < ans) {
                    ans = iter->second[0];
                }
            }
        }
        return ans;
    }
};