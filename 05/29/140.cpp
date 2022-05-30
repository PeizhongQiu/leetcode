class Solution {
public:
    struct tie
    {
        int flag = 0;
        int index[26] = {0};
    };
    vector<tie> data;
    void insert(string s, int flag)
    {
        int index = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (data[index].index[s[i] - 'a'] == 0)
            {
                tie temp;
                data.push_back(temp);
                data[index].index[s[i] - 'a'] = data.size() - 1;
            }
            index = data[index].index[s[i] - 'a'];
        }
        data[index].flag |= flag;
    }
    void initTie() {
        tie temp;
        data.push_back(temp);
    }

    vector<string> ret;
    void _wordBreak(string s, string t) {
        if(s == "") {
            t.pop_back();
            ret.push_back(t);
            return ;
        }
        int index = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (data[index].index[s[i] - 'a'] == 0) {
                return ;
            }
            index = data[index].index[s[i] - 'a'];
            if(data[index].flag == 1){
                //cout << i << " " << s.substr(i+1) << " " << t + s.substr(0,i+1) + " ";
                _wordBreak(s.substr(i+1), t + s.substr(0,i+1) + " ");
            }
        }

    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        initTie();
        for(auto c : wordDict) {
            insert(c, 1);
        }
        _wordBreak(s, "");
        return ret;
    }
};