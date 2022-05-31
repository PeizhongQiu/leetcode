class Solution {
public:
    bool bfs(vector<int> &ret, unordered_set<int>& sret, int n) {
        if(ret.size() == (1 << n) && ((ret[ret.size() - 1] & (ret[ret.size()-1] - 1)) == 0)) {
            return true;
        }
        int last = ret[ret.size() - 1];
        for(int i = 0; i < n; ++i) {
            int temp = last ^ (1 << i);
            if(sret.find(temp) == sret.end()) {
                ret.push_back(temp);
                sret.insert(temp);
                if(bfs(ret, sret, n)) {
                    return true;
                }
                ret.pop_back();
                sret.erase(temp);
            }
        }
        return false;
    }
    vector<int> grayCode(int n) {
        vector<int> ret;
        ret.push_back(0);
        unordered_set<int> sret;
        sret.insert(0);
        bfs(ret,sret,n);
        return ret;
    }
};