class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int index = 1;
        int length = 1;
        for(int i = 1; i < nums.size(); ++i) {
            if(nums[i] == nums[i-1]) {
                ++length;
                if(length <= 2) {
                    nums[index] = nums[i];
                    ++index;
                } 
            } else {
                length = 1;
                nums[index] = nums[i];
                ++index;
            }
        }
        return index;
    }
};