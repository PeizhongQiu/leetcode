class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ret;
        for(int i = left; i <= right; ++i) {
            int temp = i;
            int ok = 1;
            while(temp) {
                int a = temp % 10;
                if(a == 0 || i % a != 0) {
                    ok = 0;
                    break;
                }
                temp = temp / 10;
            }
            if(ok) {
                ret.push_back(i);
            }
        }
        return ret;
    }
};