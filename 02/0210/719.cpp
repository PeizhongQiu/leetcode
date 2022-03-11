/*
 * @lc app=leetcode.cn id=719 lang=cpp
 *
 * [719] 找出第 k 小的距离对
 *
 * https://leetcode-cn.com/problems/find-k-th-smallest-pair-distance/description/
 *
 * algorithms
 * Hard (38.02%)
 * Likes:    233
 * Dislikes: 0
 * Total Accepted:    10.8K
 * Total Submissions: 28.3K
 * Testcase Example:  '[1,3,1]\n1'
 *
 * 给定一个整数数组，返回所有数对之间的第 k 个最小距离。一对 (A, B) 的距离被定义为 A 和 B 之间的绝对差值。
 * 
 * 示例 1:
 * 
 * 
 * 输入：
 * nums = [1,3,1]
 * k = 1
 * 输出：0 
 * 解释：
 * 所有数对如下：
 * (1,3) -> 2
 * (1,1) -> 0
 * (3,1) -> 2
 * 因此第 1 个最小距离的数对是 (1,1)，它们之间的距离为 0。
 * 
 * 
 * 提示:
 * 
 * 
 * 2 <= len(nums) <= 10000.
 * 0 <= nums[i] < 1000000.
 * 1 <= k <= len(nums) * (len(nums) - 1) / 2.
 * 
 * 
 */

// @lc code=start
#define MAX_NUM 1000000
class Solution {
public:
    
    //const int MAX_NUM = 10; //1000000
    int smallestDistancePair(vector<int>& nums, int k) {
        int freq[MAX_NUM] = {0};
        int bigger[MAX_NUM];
        int all = nums.size() * (nums.size() - 1) / 2;
        for(int i = 0; i < nums.size(); i++) {
            ++freq[nums[i]];
        }
        bigger[MAX_NUM - 1] = freq[MAX_NUM - 1];
        for(int i = MAX_NUM - 2; i >= 0; i--) {
            bigger[i] = bigger[i+1] + freq[i];
        }
        
        int startAbs = 0;
        int endAbs = MAX_NUM - 1;
        int count = 0;
        while(startAbs < endAbs) {
            int start = 0, end = (startAbs + endAbs) / 2;
            count = 0;
            while(end < MAX_NUM) {
                count += freq[start] * bigger[end];
                ++start;
                ++end;
            }
            count = all - count;
            //cout << startAbs << " " << endAbs << " " << count << endl;
            if(count < k) {
                startAbs = (startAbs + endAbs) / 2 + 1;
            } else {
                endAbs = (startAbs + endAbs) / 2;
            }
        }
        return startAbs - 1;
    }
};
// @lc code=end

