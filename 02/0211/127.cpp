class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, vector<string>> graph;
        unordered_map<string, int> visit;
        wordList.push_back(beginWord);
        for(auto s : wordList) {
            for(int i = 0; i < s.size(); ++i) {
                string temp = s;
                temp[i] = '*';
                graph[temp].push_back(s);
                graph[s].push_back(temp);
                visit[temp] = 0;
            }
            visit[s] = 0;
        }
        int ret = 0;
        int length = 1;
        queue<string> q;
        q.push(beginWord);
        visit[beginWord] = 1;
        int over = 0;
        while(!q.empty()) {
            ++ret;
            for(int i = 0; i < length; ++i) {
                string top = q.front();
                //cout << ret << " " << top << endl;
                q.pop();
                for(int i = 0; i < graph[top].size(); ++i) {
                    if(visit[graph[top][i]] == 0) {
                        q.push(graph[top][i]);
                        visit[graph[top][i]] = 1;
                        if(graph[top][i] == endWord) {
                            return ret/2 + 1;
                        }
                    }
                }
            }
            length = q.size();
        }

        return 0;
    }
};