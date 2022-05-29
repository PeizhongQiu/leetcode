class Solution {
public:
    int titleToNumber(string columnTitle) {
        long long ret = 0;
        for(auto c : columnTitle) {
            ret = ret * 26 + c - 'A' + 1;
        }
        return ret;
    }
};