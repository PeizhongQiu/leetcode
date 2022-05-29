class Solution {
public:
    int countEven(int num) {
        int count = 0;
        for(int i = 1; i <= num; i++) {
            int temp = (i/1000) + (i / 100) + (i / 10) + (i % 10);
            if(temp%2 == 0) count++;
        }
        return count;
    }
};