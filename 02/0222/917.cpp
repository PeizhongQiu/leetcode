class Solution {
public:
    string reverseOnlyLetters(string s) {
        int start = 0, end = s.size() - 1;
        while(start < end) {
            if(((s[start] >= 'A' && s[start] <= 'Z') || (s[start] >= 'a' && s[start] <= 'z'))
            && ((s[end] >= 'A' && s[end] <= 'Z') || (s[end] >= 'a' && s[end] <= 'z'))) {
                char temp = s[start];
                s[start] = s[end];
                s[end] = temp;
                ++start;
                --end;
            }
            if(!((s[start] >= 'A' && s[start] <= 'Z') || (s[start] >= 'a' && s[start] <= 'z'))) {
                ++start;
            }
            if(!((s[end] >= 'A' && s[end] <= 'Z') || (s[end] >= 'a' && s[end] <= 'z'))) {
                --end;
            }
        }
        return s;
    }
};