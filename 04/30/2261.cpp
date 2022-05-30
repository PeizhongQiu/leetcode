
class Solution {
public:
    
    int countDistinct(vector<int>& nums, int k, int p) {
        unordered_set<string> ret;
        for(int i = 0; i < nums.size(); ++i) {
            int all = 0;
            string temp = "";
            for(int j = 0; j <= i; ++j) {
                temp = to_string(nums[i - j]) + "#" + temp;
                if(nums[i - j] % p == 0) {
                    ++all;
                } 
                if(all <= k) {
                    ret.insert(temp);
                    //cout << temp << endl;
                } else {
                    break;
                }
                
            }
        }
        
        return ret.size();
    }
};