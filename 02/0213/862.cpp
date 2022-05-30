class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        deque<int> d;
        d.push_front(0);
        int ret = nums.size() + 1;
        vector<long long> sum;
        sum.push_back(0);
        for(int i = 1; i <= nums.size(); ++i) {
            sum.push_back(sum[i-1] + nums[i-1]);
        }
        for(int i = 1; i <= nums.size(); ++i) {
            while(!d.empty() && sum[i] - sum[d.back()] >= k) {
                ret = min(ret, i - d.back());
                d.pop_back();
            }
            while(!d.empty() && sum[i] <= sum[d.front()]) {
                d.pop_front();
            }
            d.push_front(i);
        }
        return ret > nums.size() ? -1 : ret;
    }
};