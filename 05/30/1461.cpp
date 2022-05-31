class Solution {
public:
    bool hasAllCodes(string s, int k) {
        vector<bool> has(1<<k,false);
        
        int sum = 0;
        for(int i = 0; i < s.size(); ++i) {
            if(i < k) {
                sum = sum * 2 + s[i] - '0';
            } else {
                sum = sum & ((1 << (k-1)) - 1);
                sum = sum * 2 + s[i] - '0';
            }
            if(i >= k - 1) {
                has[sum] = true;
            }
        }
        
        for(int i = 0; i < (1 << k); ++i) {
            
            if(has[i] == false) {
                //cout << i << endl;
                return false;
            }
        }
        return true;
    }
};