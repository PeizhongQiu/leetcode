class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> large;
        int mini = 0x7fffffff;
        for (auto& num : nums) {
            if(num % 2) num = num * 2;
            large.push(num);
            mini = min(mini,num);
        }
        int ret = large.top() - mini;
        while (!large.empty() && large.top() % 2 == 0) {
            int temp = large.top() >> 1;
            large.pop();
            large.push(temp);
            mini = min(temp, mini);
            ret = min(ret, large.top() - mini);
        }
        return ret;
    }
};