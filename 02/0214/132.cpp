/*
 * @lc app=leetcode.cn id=132 lang=cpp
 *
 * [132] 分割回文串 II
 */

/* 算法描述
 * 首先通过 dp[i][j] 计算出字符串 s 从 i 到 j 的子串是否为回文串；
 * 然后用第二个 dp2[i] 代表以 s[0...i] 的最小分割。
 * dp2[i]= min{dp2[j]}+1,其中 s[j+1..i] 是一个回文串
 */
class Solution {
public:
    
    int minCut(string s) {
        int ret[2000];
        bool dpPalindrome[2000][2000] = {0};

        for(int i = s.size() - 1; i >= 0; --i) {
            for(int j = i; j < s.size(); ++j) {
                if(i == j) dpPalindrome[i][j] = true;
                else if(i == j - 1) dpPalindrome[i][j] = s[i] == s[j];
                else dpPalindrome[i][j] = dpPalindrome[i+1][j-1] && s[i] == s[j];
            }
        }

        for(int i = 0; i < s.size(); i++){
            ret[i] = 20000;
            if(dpPalindrome[0][i]){
                ret[i] = 0;
                //cout << i << endl;
                continue;
            }
            for(int j = i; j > 0; j--) {
                if(dpPalindrome[j][i]){
                    ret[i] = min(ret[j-1] + 1, ret[i]);
                    //cout << j << " " << i << endl;
                }
            }
        }
        return ret[s.size()-1];

    }
};

