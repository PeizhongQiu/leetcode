class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int, int> index;
        int ret = 1 << 30;
        for(int i = 0; i < cards.size(); ++i) {
            if(index.count(cards[i]) != 0) {
                ret = min(ret, i - index[cards[i]] + 1);
            }
            index[cards[i]] = i;
        }
        if(ret == (1 << 30)) return -1;
        return ret;
    }
};