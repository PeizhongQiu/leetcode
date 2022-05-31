class Solution {
public:
    int numTimesAllBlue(vector<int>& flips) {
        int max = 0;
        int count = 0;
        for(int i = 0; i < flips.size(); ++i) {
            if(flips[i] > max) max = flips[i];
            if(i + 1== max) {
                ++count;
            }
        }
        return count;
    }
};