/**
 * flag:0代表未到一个单词结尾，1代表到达一个单词结尾。其余值根据题目自定义。
 * 注意，这只有小写字母string
 */

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