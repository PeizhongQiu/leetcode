/*
 * @lc app=leetcode.cn id=2170 lang=cpp
 *
 * [2170] 使数组变成交替数组的最少操作数
 *
 * https://leetcode-cn.com/problems/minimum-operations-to-make-the-array-alternating/description/
 *
 * algorithms
 * Medium (30.69%)
 * Likes:    23
 * Dislikes: 0
 * Total Accepted:    5.6K
 * Total Submissions: 19.6K
 * Testcase Example:  '[3,1,3,2,4,3]'
 *
 * 给你一个下标从 0 开始的数组 nums ，该数组由 n 个正整数组成。
 * 
 * 如果满足下述条件，则数组 nums 是一个 交替数组 ：
 * 
 * 
 * nums[i - 2] == nums[i] ，其中 2 <= i <= n - 1 。
 * nums[i - 1] != nums[i] ，其中 1 <= i <= n - 1 。
 * 
 * 
 * 在一步 操作 中，你可以选择下标 i 并将 nums[i] 更改 为 任一 正整数。
 * 
 * 返回使数组变成交替数组的 最少操作数 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [3,1,3,2,4,3]
 * 输出：3
 * 解释：
 * 使数组变成交替数组的方法之一是将该数组转换为 [3,1,3,1,3,1] 。
 * 在这种情况下，操作数为 3 。
 * 可以证明，操作数少于 3 的情况下，无法使数组变成交替数组。
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1,2,2,2,2]
 * 输出：2
 * 解释：
 * 使数组变成交替数组的方法之一是将该数组转换为 [1,2,1,2,1].
 * 在这种情况下，操作数为 2 。
 * 注意，数组不能转换成 [2,2,2,2,2] 。因为在这种情况下，nums[0] == nums[1]，不满足交替数组的条件。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^5
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int odd[100010] = {0};
        int even[100010] = {0};
        
        for(int i = 0; i < nums.size(); i++) {
            if(i % 2) {
                ++odd[nums[i]];
            } else {
                ++even[nums[i]];
            }
        }
        int oddMax1 = 0;
        int oddPosition1 = 0;
        int oddMax2 = 0;
        int oddPosition2 = 0;
        int evenMax1 = 0;
        int evenPosition1 = 0;
        int evenMax2 = 0;
        int evenPosition2 = 0;
        for(int i = 0; i < 100010; i++) {
            if(odd[i] > oddMax1){
                oddMax1 = odd[i];
                oddPosition1 = i;
            }
            if(even[i] > evenMax1){
                evenMax1 = even[i];
                evenPosition1 = i;
            }
        }
        //cout << oddMax1 << " " << oddPosition1 << " "<< evenMax1 << " " << evenPosition1 << endl;
        for(int i = 0; i < 100010; i++) {
            if(odd[i] > oddMax2 && i != oddPosition1){
                oddMax2 = odd[i];
                oddPosition2 = i;
            }
            if(even[i] > evenMax2 && i != evenPosition1){
                evenMax2 = even[i];
                evenPosition2 = i;
            }
        }
        //cout << oddMax2 << " " << oddPosition2 << " "<< evenMax2 << " " << evenPosition2 << endl;
        //cout << nums.size() << endl;
        int count = 0;
        if(oddPosition1 != evenPosition1) {
            count = oddMax1 + evenMax1;
        } else {
            count = oddMax1 + evenMax2 > oddMax2 + evenMax1 ? oddMax1 + evenMax2 : oddMax2 + evenMax1;
        }
        return nums.size() - count;
    }
};
// @lc code=end

