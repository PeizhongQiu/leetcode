/*
 * @lc app=leetcode.cn id=1850 lang=cpp
 *
 * [1850] 邻位交换的最小次数
 *
 * https://leetcode-cn.com/problems/minimum-adjacent-swaps-to-reach-the-kth-smallest-number/description/
 *
 * algorithms
 * Medium (61.32%)
 * Likes:    36
 * Dislikes: 0
 * Total Accepted:    2.6K
 * Total Submissions: 4.3K
 * Testcase Example:  '"5489355142"\n4'
 *
 * 给你一个表示大整数的字符串 num ，和一个整数 k 。
 * 
 * 如果某个整数是 num 中各位数字的一个 排列 且它的 值大于 num ，则称这个整数为 妙数 。可能存在很多妙数，但是只需要关注 值最小
 * 的那些。
 * 
 * 
 * 例如，num = "5489355142" ：
 * 
 * 
 * 第 1 个最小妙数是 "5489355214"
 * 第 2 个最小妙数是 "5489355241"
 * 第 3 个最小妙数是 "5489355412"
 * 第 4 个最小妙数是 "5489355421"
 * 
 * 
 * 
 * 
 * 返回要得到第 k 个 最小妙数 需要对 num 执行的 相邻位数字交换的最小次数 。
 * 
 * 测试用例是按存在第 k 个最小妙数而生成的。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：num = "5489355142", k = 4
 * 输出：2
 * 解释：第 4 个最小妙数是 "5489355421" ，要想得到这个数字：
 * - 交换下标 7 和下标 8 对应的位："5489355142" -> "5489355412"
 * - 交换下标 8 和下标 9 对应的位："5489355412" -> "5489355421"
 * 
 * 
 * 示例 2：
 * 
 * 输入：num = "11112", k = 4
 * 输出：4
 * 解释：第 4 个最小妙数是 "21111" ，要想得到这个数字：
 * - 交换下标 3 和下标 4 对应的位："11112" -> "11121"
 * - 交换下标 2 和下标 3 对应的位："11121" -> "11211"
 * - 交换下标 1 和下标 2 对应的位："11211" -> "12111"
 * - 交换下标 0 和下标 1 对应的位："12111" -> "21111"
 * 
 * 
 * 示例 3：
 * 
 * 输入：num = "00123", k = 1
 * 输出：1
 * 解释：第 1 个最小妙数是 "00132" ，要想得到这个数字：
 * - 交换下标 3 和下标 4 对应的位："00123" -> "00132"
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 2 <= num.length <= 1000
 * 1 <= k <= 1000
 * num 仅由数字组成
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int getMinSwaps(string num, int k) {
        string temp = num;
        for(int i = 0; i < k; i++) {
            temp = nextMin(temp);
            //cout << temp << endl;
        }
        int count = 0;
        for(int i = 0; i < num.size(); i++) {
            if(num[i] != temp[i]) {
                for (int j = i + 1; j < num.size(); ++j) {
                    if (num[j] == temp[i]) {
                        for (int k = j - 1; k >= i; --k) {
                            ++count;
                            swap(num[k], num[k + 1]);
                        }
                        break;
                    }
                }
            }
        }
        return count;
    }

    string nextMin(string num) {
        //cout << "num" << num << endl;
        for(int i = num.size() - 1; i > 0; i--) {
            if(num[i-1] < num[i]) {
                //cout << i << endl;
                for(int j = num.size() - 1; j >= i; j--) {
                    if(num[i-1] < num[j]) {
                        char temp = num[j];
                        num[j] = num[i-1];
                        num[i-1] = temp;
                        sort(num.begin() + i, num.end());
                        break;
                    }
                }
                break;
            }
        }
        return num;
    }
};
// @lc code=end

