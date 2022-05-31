class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int> available;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> busy;

        for(int i = 0; i < k; ++i) {
            available.insert(i);
        }

        int n = arrival.size();
        vector<int> request(k, 0);
        for(int i = 0; i < n; ++i) {
            while(!busy.empty() && busy.top().first <= arrival[i]) {
                //cout << busy.top().first << " " << busy.top().second << endl;
                available.insert(busy.top().second);
                busy.pop();
            }
            if(!available.empty()) {
                auto iter = available.lower_bound(i%k);
                if(iter == available.end()) {
                    iter = available.lower_bound(0);
                }
                //cout << *iter << endl;
                ++request[*iter];
                busy.push({arrival[i] + load[i], *iter});
                available.erase(iter);
            }
        }

        vector<int> ret;
        int max = 0;

        for(int i = 0; i < k; ++i) {
            //cout << request[i] << endl;
            if(request[i] > max) {
                ret.clear();
                ret.push_back(i);
                max = request[i];
            } else if(request[i] == max) {
                ret.push_back(i);
            }
        }
        return ret;
    }
};