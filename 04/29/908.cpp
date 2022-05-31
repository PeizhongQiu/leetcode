class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int min = *min_element(nums.begin(), nums.end());
        int max = *max_element(nums.begin(), nums.end());

        return max - min > 2 * k ? max - min - 2 * k : 0;
    }
};