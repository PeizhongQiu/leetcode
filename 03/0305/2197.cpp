//283次周赛 4
class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> ret;
        ret.push_back(nums[0]);
        int ok = 1;
        
        for(int i = 1; i < nums.size(); ++i) {
            int temp = ret[ret.size() - 1];
            
            int x = __gcd(temp,nums[i]);
            //cout << temp << " " << nums[i] << " " << x << endl;
            if(x == 1) {
                ret.push_back(nums[i]);
            } else {
                int in = nums[i] / x * temp;
                while(!ret.empty()) {
                    ret.pop_back();
                     
                    if(!ret.empty()) {
                        temp = ret[ret.size() - 1];
                        int y = __gcd(temp, in);
                        if(y == 1){
                            break;
                        } else {
                            in = in / y * temp;
                        }
                    }
                        
                }
                
                ret.push_back(in);
            }
        }
        //cout << __gcd(899,20677);
        return ret;
    }
};