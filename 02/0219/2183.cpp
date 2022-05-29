class Solution {
public:
    int GCD(int a, int b) {
        if (a%b == 0) {
            return b;
        }
        return GCD(b, a%b);
    }
    long long coutPairs(vector<int>& nums, int k) {
        map<int, vector<int>> freq;
        long long sum = 0;
        for(int i = 1; i * i <= k; ++i) {
            if(k % i == 0) {
                vector<int> temp1(nums.size() + 1, 0);
                freq[i] = temp1;
                vector<int> temp2(nums.size() + 1, 0);
                freq[k/i] = temp2;
                //cout << i << endl;
            }
        }
        for(int i = nums.size() - 1; i >= 0; i--) {
            for (auto it=freq.begin(); it!=freq.end(); ++it) {
                //cout << it->first << " ";
                if(nums[i] % (it->first) == 0) {
                    //sum += nums.size() - 1 - i;
                    freq[it->first][i] = freq[it->first][i+1] + 1;
                } else {
                    //sum+=x[i+1];
                    freq[it->first][i] = freq[it->first][i+1];
                }
                //cout << freq[it->first][i] << endl;
            }
            sum += freq[k / GCD(k,nums[i])][i+1];
            
        }
        return sum;
    }
};
