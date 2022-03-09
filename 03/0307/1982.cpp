/*
 * @lc app=leetcode.cn id=1982 lang=cpp
 *
 * [1982] 从子集的和还原数组
 *
 * https://leetcode-cn.com/problems/find-array-given-subset-sums/description/
 *
 * algorithms
 * Hard (46.63%)
 * Likes:    27
 * Dislikes: 0
 * Total Accepted:    1K
 * Total Submissions: 2.1K
 * Testcase Example:  '3\n[-3,-2,-1,0,0,1,2,3]'
 *
 * 存在一个未知数组需要你进行还原，给你一个整数 n 表示该数组的长度。另给你一个数组 sums ，由未知数组中全部 2^n 个 子集的和
 * 组成（子集中的元素没有特定的顺序）。
 * 
 * 返回一个长度为 n 的数组 ans 表示还原得到的未知数组。如果存在 多种 答案，只需返回其中 任意一个 。
 * 
 * 如果可以由数组 arr 删除部分元素（也可能不删除或全删除）得到数组 sub ，那么数组 sub 就是数组 arr 的一个 子集 。sub
 * 的元素之和就是 arr 的一个 子集的和 。一个空数组的元素之和为 0 。
 * 
 * 注意：生成的测试用例将保证至少存在一个正确答案。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 3, sums = [-3,-2,-1,0,0,1,2,3]
 * 输出：[1,2,-3]
 * 解释：[1,2,-3] 能够满足给出的子集的和：
 * - []：和是 0
 * - [1]：和是 1
 * - [2]：和是 2
 * - [1,2]：和是 3
 * - [-3]：和是 -3
 * - [1,-3]：和是 -2
 * - [2,-3]：和是 -1
 * - [1,2,-3]：和是 0
 * 注意，[1,2,-3] 的任何排列和 [-1,-2,3] 的任何排列都会被视作正确答案。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 2, sums = [0,0,0,0]
 * 输出：[0,0]
 * 解释：唯一的正确答案是 [0,0] 。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：n = 4, sums = [0,0,5,5,4,-1,4,9,9,-1,4,3,4,8,3,8]
 * 输出：[0,-1,4,5]
 * 解释：[0,-1,4,5] 能够满足给出的子集的和。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= n <= 15
 * sums.length == 2^n
 * -10^4 <= sums[i] <= 10^4
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    void print(vector<int> x) {
        for(int i = 0; i < x.size(); ++i) {
            cout << x[i] << " ";
        }
        cout << endl;
    }
    vector<int> recoverArray(int n, vector<int>& sums) {
        vector<int> ret;
        sort(sums.begin(), sums.end());
        int negSum = sums[0] * -1;
        for(int i = 0; i < sums.size(); ++i) {
            sums[i] += negSum;
        }
        //print(sums);
        vector<int> visit(sums.size(), 0);
        for(int i = 0; i < n; ++i) {
            int left = 0, right = 1;
            for(int j = 1; j < sums.size(); ++j) {
                if(visit[j] == false) {
                    ret.push_back(sums[j]);
                    right = j;
                    break;
                }
            }
            
            
            while(right < sums.size()) {
                if(visit[right] == true) {
                    ++right;
                } else if (visit[left] == true){
                    ++left;
                } else if (left == right) {
                    ++right;
                } else if(sums[right] - sums[left] == ret[ret.size() - 1]) {
                    visit[right] = true;
                    ++left;
                } else if(sums[right] - sums[left] > ret[ret.size() - 1]) {
                    ++left;
                } else if(sums[right] - sums[left] < ret[ret.size() - 1]) {
                    ++right;
                }
                //cout << left << " " << right << endl;
                //print(visit);
            }
            
            //print(ret);
        }
        for(int i = 0; i < (1 << n); ++i) {
            int sum = 0;
            for(int j = 0; j < n; j++) {
                if(i & (1 << j)) {
                    sum += ret[j];
                }
            }
            if(sum == negSum) {
                for(int j = 0; j < n; j++) {
                    if(i & (1 << j)) {
                        ret[j] = ret[j] * -1;
                        
                    }
                }
                return ret;
            }
        }
        return ret;
    }
};
// @lc code=end

