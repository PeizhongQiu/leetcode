class Solution {
public:
    bool checkZeroOnes(string s) {
        int sum1 = 0;
        int max1 = 0;
        int sum0 = 0;
        int max0 = 0;
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == '0') {
                sum0++;
                max1 = max(sum1, max1);
                sum1 = 0;
            } else {
                sum1++;
                max0 = max(sum0, max0);
                sum0 = 0;
            }
        }
        max1 = max(sum1, max1);
        max0 = max(sum0, max0);
        return max1 > max0;
    }
};