class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        int freq[26] = {0};
        for(int i = 0; i < s.size(); i++) {
            ++freq[s[i]-'a'];
        }
        string ret = "";
        for(int i = 25; i >= 0; i--) {
            int repeat = 0;
            for(int j = 0; j < freq[i]; j++) {
                //cout << freq[i] << repeat;
                if(repeat < repeatLimit) {
                    ret += (char)('a' + i);
                    repeat++;
                } else {
                    int ok = 0;
                    for(int k = i-1; k >= 0; --k) {
                        if(freq[k] > 0) {
                            ret += (char)('a' + k);
                            ret += (char)('a' + i);
                            freq[k]--;
                            ok = 1;
                            break;
                        }
                    }
                    if(ok) {
                        repeat = 1;
                    }
                    else return ret;
                }
            }
        }
        return ret;
    }
};
