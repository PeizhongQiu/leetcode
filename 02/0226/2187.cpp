//282周赛
class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long start = 1, end = 10e14;
        while(start < end) {
            long long mid = (end - start) / 2 + start;
            long long sum = 0;
            for(int i = 0; i < time.size(); i++) {
                sum += mid/time[i];
                if(sum >= totalTrips) break;
            }
            if(sum < totalTrips) {
                start = mid + 1;
            } else if(sum >= totalTrips) {
                end = mid;
            }
        }
        return start;
    }
};