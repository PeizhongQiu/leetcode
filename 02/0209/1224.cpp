/*
 * @lc app=leetcode.cn id=1224 lang=cpp
 *
 * [1224] 最大相等频率
 *
 * https://leetcode-cn.com/problems/maximum-equal-frequency/description/
 *
 * algorithms
 * Hard (32.73%)
 * Likes:    53
 * Dislikes: 0
 * Total Accepted:    5.1K
 * Total Submissions: 15.5K
 * Testcase Example:  '[2,2,1,1,5,3,3,5]'
 *
 * 给你一个正整数数组 nums，请你帮忙从该数组中找出能满足下面要求的 最长 前缀，并返回该前缀的长度：
 * 
 * 
 * 从前缀中 恰好删除一个 元素后，剩下每个数字的出现次数都相同。
 * 
 * 
 * 如果删除这个元素后没有剩余元素存在，仍可认为每个数字都具有相同的出现次数（也就是 0 次）。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [2,2,1,1,5,3,3,5]
 * 输出：7
 * 解释：对于长度为 7 的子数组 [2,2,1,1,5,3,3]，如果我们从中删去 nums[4] = 5，就可以得到
 * [2,2,1,1,3,3]，里面每个数字都出现了两次。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1,1,1,2,2,2,3,3,3,4,4,4,5]
 * 输出：13
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 2 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^5
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        int result = 0;
        unordered_map<int, int> numToFreq;
        unordered_map<int, int> freqToNum;
        
        for(int i = 0; i < nums.size(); i++) {
            if(numToFreq.count(nums[i]) == 0) {
                numToFreq[nums[i]] = 1;
                if(freqToNum.count(1) == 0) {
                    freqToNum[1] = 1;
                } else {
                    ++freqToNum[1];
                }
            } else {
                --freqToNum[numToFreq[nums[i]]];
                if(freqToNum[numToFreq[nums[i]]] == 0) {
                    freqToNum.erase(numToFreq[nums[i]]);
                }
                ++numToFreq[nums[i]];
                if(freqToNum.count(numToFreq[nums[i]]) == 0) {
                    freqToNum[numToFreq[nums[i]]] = 1;
                } else {
                    ++freqToNum[numToFreq[nums[i]]];
                }
            }
            int freq = numToFreq[nums[0]];
            if(freqToNum.size() == 1) {
                if(freqToNum.count(1) != 0 || freqToNum[freq] == 1)
                    result = i;
            } else if (freqToNum.size() == 2) {
                
                if(freqToNum.count(1) != 0 && freqToNum[1] == 1)
                    result = i;
                else if(freqToNum[freq] == 1 && freqToNum.count(freq - 1) != 0)
                    result = i;
                else if(freqToNum.count(freq + 1) != 0 && freqToNum[freq + 1] == 1)
                    result = i;
            } 
            
        }
        return result + 1;
    }
};
// @lc code=end

