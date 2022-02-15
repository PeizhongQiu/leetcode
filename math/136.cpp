/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] 只出现一次的数字
 */

/* 算法思路：
 * a ^ a = 0，因此所有数亦或就可以得到只有一个的数 
 */

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for(int i = 0; i < nums.size(); i++) {
            result = result ^ nums[i];
        }
        return result;
    }
};

