class Solution {
public:
    string tran(string s) {
        string ret = "";
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == '#') {
                if(ret != "")
                    ret.pop_back();
            } else {
                ret += s[i];
            }
        }
        return ret;
    }
    bool backspaceCompare(string s, string t) {
        return tran(s) == tran(t);   
    }
};