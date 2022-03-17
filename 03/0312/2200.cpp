// 284-1
class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> ret;
        int j = 0;
        int n = nums.size();
        for(int i = 0; i < n; ++i) {
            if(nums[i] == key) {
                //cout << i << " ";
                int maxDis = min(n - 1, i + k);
                while(j <= maxDis) {
                    int dis = j - i > 0 ? j - i : i - j;
                    //cout << j << " ";
                    if(dis <= k) {
                        ret.push_back(j);
                    }
                    ++j;
                }
                //cout << endl;
            }
        }
        return ret;
    }
};