/*
 * @lc app=leetcode.cn id=1025 lang=cpp
 *
 * [1025] 除数博弈
 *
 * https://leetcode-cn.com/problems/divisor-game/description/
 *
 * algorithms
 * Easy (70.87%)
 * Likes:    341
 * Dislikes: 0
 * Total Accepted:    79.6K
 * Total Submissions: 112.3K
 * Testcase Example:  '2'
 *
 * 爱丽丝和鲍勃一起玩游戏，他们轮流行动。爱丽丝先手开局。
 * 
 * 最初，黑板上有一个数字 n 。在每个玩家的回合，玩家需要执行以下操作：
 * 
 * 
 * 选出任一 x，满足 0 < x < n 且 n % x == 0 。
 * 用 n - x 替换黑板上的数字 n 。
 * 
 * 
 * 如果玩家无法执行这些操作，就会输掉游戏。
 * 
 * 只有在爱丽丝在游戏中取得胜利时才返回 true 。假设两个玩家都以最佳状态参与游戏。
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 2
 * 输出：true
 * 解释：爱丽丝选择 1，鲍勃无法进行操作。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 3
 * 输出：false
 * 解释：爱丽丝选择 1，鲍勃也选择 1，然后爱丽丝无法进行操作。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= n <= 1000
 * 
 * 
 */


/* 算法思想 
 * 这道题可以当作一道动态规划题，用 dp[i] 来表示当 n = i 时的结果。
 * 首先我们要明白我们拿了一个数 i 后，局面相当于 Bob 先手，数字变为 n - i；
 * 此时如果 Bob 有必胜策略，则我们必输；否则，我们必赢。
 * 当 n = 1 时，Alice 没有可以拿取的数字，所以直接返回 false；
 * 当 n > 1 时：
 *      我们可以遍历所有的余数 j，如果 dp[n - j] 为 false，则我们可以胜利，
 *          这是因为我们拿了 j 之后，相当与 Bob 是先手开始游戏，
 *          而数字 n 变为 n - j，dp[n - j] 为 false，则代表先手必输，
 *          因此，dp[n] 为 true；
 *      如果没有这样的余数 j，则 dp[n] 为 false。
 */

class Solution {
public:
    bool divisorGame(int n) {
        bool result[1001] = {false};
        for(int i = 2; i <= n; i++){
            for(int j = 1; j < i; j++){
                if(i%j == 0 && result[i-j] == false){
                    result[i] = true;
                    break;
                }
            }
        }
        return result[n];
    }
};

/* 其他算法 
 * 当 n 为奇数时，返回 false，否则返回 true。
 * 证明：
 * 首先当 n = 1 或 2 时，显然成立。
 * 假设当 n <= K 时，都成立，则当 n = K + 1 时：
 *      如果 n 为奇数，则 n 的所有除数都为奇数，奇数减去奇数为偶数，而当 n <= K 
 *      时，偶数都有必胜策略，因此奇数全部返回 false。
 *      如果 n 为偶数，则我们取 1，则剩余的数为奇数，而当 n <= K 
 *      时，奇数都必输，因此偶数全部返回 true。
 */

class Solution {
public:
    bool divisorGame(int n) {
        return n % 2 ? false : true;
    }
};