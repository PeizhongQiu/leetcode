//283次周赛 1
class Solution {
public:
    vector<string> cellsInRange(string s) {
        vector<string> ret;
        for(int i = 0; i <= s[3] - s[0]; ++i) {
            for(int j = 0; j <= s[4] - s[1]; ++j) {
                string temp = "";
                temp+=(char)(s[0] + i);
                temp+=(char)(s[1] + j);
                ret.push_back(temp);
            }
        }
        return ret;
    }
};