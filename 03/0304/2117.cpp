/*
 * @lc app=leetcode.cn id=2117 lang=cpp
 *
 * [2117] 一个区间内所有数乘积的缩写
 *
 * https://leetcode-cn.com/problems/abbreviating-the-product-of-a-range/description/
 *
 * algorithms
 * Hard (34.42%)
 * Likes:    4
 * Dislikes: 0
 * Total Accepted:    1.1K
 * Total Submissions: 3.2K
 * Testcase Example:  '1\n4'
 *
 * 给你两个正整数 left 和 right ，满足 left <= right 。请你计算 闭区间 [left, right] 中所有整数的 乘积 。
 * 
 * 由于乘积可能非常大，你需要将它按照以下步骤 缩写 ：
 * 
 * 
 * 统计乘积中 后缀 0 的数目，并 移除 这些 0 ，将这个数目记为 C 。
 * 
 * 
 * 比方说，1000 中有 3 个后缀 0 ，546 中没有后缀 0 。
 * 
 * 
 * 将乘积中剩余数字的位数记为 d 。如果 d > 10 ，那么将乘积表示为 <pre>...<suf> 的形式，其中 <pre> 表示乘积最 开始 的 5
 * 个数位，<suf> 表示删除后缀 0 之后 结尾的 5 个数位。如果 d <= 10 ，我们不对它做修改。
 * 
 * 比方说，我们将 1234567654321 表示为 12345...54321 ，但是 1234567 仍然表示为 1234567
 * 。
 * 
 * 
 * 最后，将乘积表示为 字符串 "<pre>...<suf>eC" 。
 * 
 * 比方说，12345678987600000 被表示为 "12345...89876e5" 。
 * 
 * 
 * 
 * 
 * 请你返回一个字符串，表示 闭区间 [left, right] 中所有整数 乘积 的 缩写 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：left = 1, right = 4
 * 输出："24e0"
 * 解释：
 * 乘积为 1 × 2 × 3 × 4 = 24 。
 * 由于没有后缀 0 ，所以 24 保持不变，缩写的结尾为 "e0" 。
 * 因为乘积的结果是 2 位数，小于 10 ，所欲我们不进一步将它缩写。
 * 所以，最终将乘积表示为 "24e0" 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：left = 2, right = 11
 * 输出："399168e2"
 * 解释：乘积为 39916800 。
 * 有 2 个后缀 0 ，删除后得到 399168 。缩写的结尾为 "e2" 。 
 * 删除后缀 0 后是 6 位数，不需要进一步缩写。 
 * 所以，最终将乘积表示为 "399168e2" 。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：left = 371, right = 375
 * 输出："7219856259e3"
 * 解释：乘积为 7219856259000 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= left <= right <= 10^4
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string abbreviateProduct(int left, int right) {
        int zeroTwo = 0;
        int zeroFive = 0;
        int two[10001] = {0};
        int five[10001] = {0};
        
        for(int i = left; i <= right; ++i) {
            int num = i;
            while(num % 5 == 0) {
                zeroFive++;
                num = num / 5;
            }
            five[i] = zeroFive;
            num = i;
            while(num % 2 == 0) {
                zeroTwo++;
                num = num / 2;
            }
            two[i] = zeroTwo;
        }
        int trail = min(zeroTwo, zeroFive);
        
        long long last10 = 1;
        bool bigger = false;
        for(int i = left; i <= right; ++i) {
            last10 = last10 * i;
            long long div2 = pow(2, max(min(two[i], trail)-two[i-1], 0));
            long long div5 = pow(5, max(min(five[i], trail)-five[i-1], 0));
            last10 = last10 / div2 /div5;
            if(last10 > 10e9) {
                bigger = true;
                last10 = last10 % 10000000000;
            }
        }
        string ret = "";
        if(bigger == false) {
            ret = to_string(last10) + "e" + to_string(trail);
            return ret;
        } else {
            last10 = last10 % 100000;
        }
        
        long double bit = 0;
        for(int i = left; i <= right; ++i) {
            bit += log((long double) i) / log((long double) 10.0);;
        }
        long long prefix5 = pow(10, bit - (long long)(bit) + 4);
        string zero(5-to_string(last10).size(),'0');
        ret = to_string(prefix5) + "..." + zero + to_string(last10) + "e" + to_string(trail);
        
        return ret;
    }
};
// @lc code=end

