class Solution {
public:
    string capitalizeTitle(string title) {
        for(int i = 0; i < title.size(); ++i) {
            if((i == 0 || title[i-1] == ' ') && title[i] != ' ' && i+2 < title.size() && title[i+1] != ' '  && title[i+2] != ' ') {
                title[i] = toupper(title[i]);
            } else {
                title[i] = tolower(title[i]);
            }
        }
        return title;
    }
};