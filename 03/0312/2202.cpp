//284-3
class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        if(k == 0) return nums[0];
        if(k % 2 == 1 && nums.size()== 1) return -1; 
        int n = nums.size();
        int maxDelete = -1;
        for(int i = 0; i < min(n, k-1); ++i) {
            maxDelete = max(maxDelete, nums[i]);
        }
        if(k > n) {
            return maxDelete;
        } else if(k == n) {
            return maxDelete;
        } else {
            return max(nums[k], maxDelete);
        }
            
        
    }
};