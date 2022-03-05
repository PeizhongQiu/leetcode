/*
 * @lc app=leetcode.cn id=2044 lang=cpp
 *
 * [2044] 统计按位或能得到最大值的子集数目
 *
 * https://leetcode-cn.com/problems/count-number-of-maximum-bitwise-or-subsets/description/
 *
 * algorithms
 * Medium (74.40%)
 * Likes:    17
 * Dislikes: 0
 * Total Accepted:    5.4K
 * Total Submissions: 7.3K
 * Testcase Example:  '[3,1]'
 *
 * 给你一个整数数组 nums ，请你找出 nums 子集 按位或 可能得到的 最大值 ，并返回按位或能得到最大值的 不同非空子集的数目 。
 * 
 * 如果数组 a 可以由数组 b 删除一些元素（或不删除）得到，则认为数组 a 是数组 b 的一个 子集 。如果选中的元素下标位置不一样，则认为两个子集
 * 不同 。
 * 
 * 对数组 a 执行 按位或 ，结果等于 a[0] OR a[1] OR ... OR a[a.length - 1]（下标从 0 开始）。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [3,1]
 * 输出：2
 * 解释：子集按位或能得到的最大值是 3 。有 2 个子集按位或可以得到 3 ：
 * - [3]
 * - [3,1]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [2,2,2]
 * 输出：7
 * 解释：[2,2,2] 的所有非空子集的按位或都可以得到 2 。总共有 2^3 - 1 = 7 个子集。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [3,2,1,5]
 * 输出：6
 * 解释：子集按位或可能的最大值是 7 。有 6 个子集按位或可以得到 7 ：
 * - [3,5]
 * - [3,1,5]
 * - [3,2,5]
 * - [3,2,1,5]
 * - [2,5]
 * - [2,1,5]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 16
 * 1 <= nums[i] <= 10^5
 * 
 * 
 */

/* 算法描述
 * 首先我们必须明白一点，按位或最大值肯定等于数组中所有的数按位或；
 * 之后观察数据范围，数组长度最大 16，1 << 16 也只有65536，因此可以采用
 * 状态压缩。16位二进制数每一位代表数组中的一个数；
 * 任一15位二进制数可以代表一个子集，即为一的位对应的数在子集中；
 * 这样计算每个子集的值，如果等于最大值，则该子集符合要求。
 */


class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int length = nums.size();
        int max = 0;
        int result = 0;
        for(int i = 0; i < length; i++) {
            max = max | nums[i];
        }
        for(int i = 1; i < (1 << length); i++){
            int temp = 0;
            for(int j = 0; j < length; j++) {
                if(i & (1 << j)) {
                    temp = temp | nums[j];
                }
            }
            if(temp == max)  ++result;
        }
        return result;
    }
};

