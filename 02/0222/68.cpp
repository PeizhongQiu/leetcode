class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ret;
        int sum = 0;
        int last = 0;
        for(int i = 0; i < words.size(); ++i) {
            sum += words[i].size();
            if(sum + i - last > maxWidth) {
                string temp = "";
                sum -= words[i].size();
                int spaceNum = 0;
                int spaceSum = 0;
                for(int j = last; j < i; ++j) {
                    temp += words[j];
                    if(j != i - 1) {
                        spaceNum = ceil((maxWidth - sum - spaceSum) * 1.0 / (i - j - 1));
                        spaceSum += spaceNum;
                        for(int k = 0; k < spaceNum; k++) {
                            temp += ' ';
                        }
                    }
                }
                if(last == i - 1) {
                    for(int k = sum; k < maxWidth; k++) {
                        temp += ' ';
                    }
                }
                ret.push_back(temp);
                last = i;
                sum = words[i].size();
                //cout << temp << endl;
            }
        }
        string temp = "";
        sum = 0;
        for(int j = last; j < words.size(); ++j) {
            temp += words[j];
            sum += words[j].size();
            if(j != words.size() - 1) {
                temp += ' ';
                sum += 1;
            }
        }
        for(int k = sum; k < maxWidth; k++) {
            temp += ' ';
        }
        ret.push_back(temp);
        return ret;
    }
};