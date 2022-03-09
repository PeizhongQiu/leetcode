//282周赛
class Solution {
public:
    int minSteps(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        int i = 0, j = 0;
        int sum = 0;
        while(i < s.size() && j < t.size()) {
            if(s[i] == t[j]) {
                ++sum;
                ++i;
                ++j;
            } else if(s[i] > t[j]){
                ++sum;
                ++j;
            } else {
                ++sum;
                ++i;
            }
        }
        sum += s.size() + t.size() - i - j;
        return sum * 2 - s.size() - t.size();
    }
};