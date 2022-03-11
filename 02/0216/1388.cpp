/*
 * @lc app=leetcode.cn id=1388 lang=cpp
 *
 * [1388] 3n 块披萨
 *
 * https://leetcode-cn.com/problems/pizza-with-3n-slices/description/
 *
 * algorithms
 * Hard (54.84%)
 * Likes:    94
 * Dislikes: 0
 * Total Accepted:    4.8K
 * Total Submissions: 8.8K
 * Testcase Example:  '[1,2,3,4,5,6]'
 *
 * 给你一个披萨，它由 3n 块不同大小的部分组成，现在你和你的朋友们需要按照如下规则来分披萨：
 * 
 * 
 * 你挑选 任意 一块披萨。
 * Alice 将会挑选你所选择的披萨逆时针方向的下一块披萨。
 * Bob 将会挑选你所选择的披萨顺时针方向的下一块披萨。
 * 重复上述过程直到没有披萨剩下。
 * 
 * 
 * 每一块披萨的大小按顺时针方向由循环数组 slices 表示。
 * 
 * 请你返回你可以获得的披萨大小总和的最大值。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 输入：slices = [1,2,3,4,5,6]
 * 输出：10
 * 解释：选择大小为 4 的披萨，Alice 和 Bob 分别挑选大小为 3 和 5 的披萨。然后你选择大小为 6 的披萨，Alice 和 Bob
 * 分别挑选大小为 2 和 1 的披萨。你获得的披萨总大小为 4 + 6 = 10 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 输入：slices = [8,9,8,6,1,1]
 * 输出：16
 * 解释：两轮都选大小为 8 的披萨。如果你选择大小为 9 的披萨，你的朋友们就会选择大小为 8 的披萨，这种情况下你的总和不是最大的。
 * 
 * 
 * 示例 3：
 * 
 * 输入：slices = [4,1,2,5,8,3,1,9,7]
 * 输出：21
 * 
 * 
 * 示例 4：
 * 
 * 输入：slices = [3,1,2]
 * 输出：3
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= slices.length <= 500
 * slices.length % 3 == 0
 * 1 <= slices[i] <= 1000
 * 
 * 
 */

// @lc code=start
class Solution {
public:

    int rob_max(vector<int>& nums, int start, int end) {
        int size = end - start + 2;
        int need = size/3;
        int rob_max[200][600] = {0};
        
        for(int i = 1; i <= need; i++){
            for(int j = start + 2 * i; j <= end + 2; ++j) {
                rob_max[i][j] = rob_max[i][j-1] > (rob_max[i - 1][j - 2] + nums[j - 2]) ?  
                        rob_max[i][j-1] : (rob_max[i - 1][j - 2] + nums[j - 2]);
                //cout << i << " " << j << " " << rob_max[i][j] << endl;
            }
                
        }
        return rob_max[need][end + 2];
    }
    int maxSizeSlices(vector<int>& slices) {
        //cout << "this 1" << endl;
        int max_1 = rob_max(slices,0,slices.size()-2);
        //cout << "this 2" << endl;
        int max_2 = rob_max(slices,1,slices.size()-1);
        return max_1>max_2?max_1:max_2;
    }
};
// @lc code=end

