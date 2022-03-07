//283次周赛 2
class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long ret = k;
        ret = ret * (k+1) / 2;
        //cout << ret;
        long long max = k;
        int indexNum = 0;
        while(indexNum < nums.size()) {
            if(indexNum < nums.size() && nums[indexNum] <= max) {
                ret+=max+1-nums[indexNum];
                max = max+1;
                while(indexNum < nums.size()-1 && nums[indexNum] == nums[indexNum+1]) {
                    indexNum++;
                }
            } 
            indexNum++;
            
        }
        return ret;
    }
};