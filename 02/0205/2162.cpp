/*
 * @lc app=leetcode.cn id=2162 lang=cpp
 *
 * [2162] 设置时间的最少代价
 *
 * https://leetcode-cn.com/problems/minimum-cost-to-set-cooking-time/description/
 *
 * algorithms
 * Medium (31.00%)
 * Likes:    2
 * Dislikes: 0
 * Total Accepted:    2.5K
 * Total Submissions: 7.9K
 * Testcase Example:  '1\n2\n1\n600'
 *
 * 常见的微波炉可以设置加热时间，且加热时间满足以下条件：
 * 
 * 
 * 至少为 1 秒钟。
 * 至多为 99 分 99 秒。
 * 
 * 
 * 你可以 最多 输入 4 个数字 来设置加热时间。如果你输入的位数不足 4 位，微波炉会自动加 前缀 0 来补足 4 位。微波炉会将设置好的四位数中，前
 * 两位当作分钟数，后 两位当作秒数。它们所表示的总时间就是加热时间。比方说：
 * 
 * 
 * 你输入 9 5 4 （三个数字），被自动补足为 0954 ，并表示 9 分 54 秒。
 * 你输入 0 0 0 8 （四个数字），表示 0 分 8 秒。
 * 你输入 8 0 9 0 ，表示 80 分 90 秒。
 * 你输入 8 1 3 0 ，表示 81 分 30 秒。
 * 
 * 
 * 给你整数 startAt ，moveCost ，pushCost 和 targetSeconds 。一开始，你的手指在数字 startAt
 * 处。将手指移到 任何其他数字 ，需要花费 moveCost 的单位代价。每 输入你手指所在位置的数字一次，需要花费 pushCost 的单位代价。
 * 
 * 要设置 targetSeconds 秒的加热时间，可能会有多种设置方法。你想要知道这些方法中，总代价最小为多少。
 * 
 * 请你能返回设置 targetSeconds 秒钟加热时间需要花费的最少代价。
 * 
 * 请记住，虽然微波炉的秒数最多可以设置到 99 秒，但一分钟等于 60 秒。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 输入：startAt = 1, moveCost = 2, pushCost = 1, targetSeconds = 600
 * 输出：6
 * 解释：以下为设置加热时间的所有方法。
 * - 1 0 0 0 ，表示 10 分 0 秒。
 * 手指一开始就在数字 1 处，输入 1 （代价为 1），移到 0 处（代价为 2），输入 0（代价为 1），输入 0（代价为 1），输入 0（代价为
 * 1）。
 * 总代价为：1 + 2 + 1 + 1 + 1 = 6 。这是所有方案中的最小代价。
 * - 0 9 6 0，表示 9 分 60 秒。它也表示 600 秒。
 * 手指移到 0 处（代价为 2），输入 0 （代价为 1），移到 9 处（代价为 2），输入 9（代价为 1），移到 6 处（代价为 2），输入
 * 6（代价为 1），移到 0 处（代价为 2），输入 0（代价为 1）。
 * 总代价为：2 + 1 + 2 + 1 + 2 + 1 + 2 + 1 = 12 。
 * - 9 6 0，微波炉自动补全为 0960 ，表示 9 分 60 秒。
 * 手指移到 9 处（代价为 2），输入 9 （代价为 1），移到 6 处（代价为 2），输入 6（代价为 1），移到 0 处（代价为 2），输入
 * 0（代价为 1）。
 * 总代价为：2 + 1 + 2 + 1 + 2 + 1 = 9 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 输入：startAt = 0, moveCost = 1, pushCost = 2, targetSeconds = 76
 * 输出：6
 * 解释：最优方案为输入两个数字 7 6，表示 76 秒。
 * 手指移到 7 处（代价为 1），输入 7 （代价为 2），移到 6 处（代价为 1），输入 6（代价为 2）。总代价为：1 + 2 + 1 + 2 =
 * 6
 * 其他可行方案为 0076 ，076 ，0116 和 116 ，但是它们的代价都比 6 大。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= startAt <= 9
 * 1 <= moveCost, pushCost <= 10^5
 * 1 <= targetSeconds <= 6039
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int minNum(int a, int b) {
        return a < b ? a : b;
    }
    int minCostSetTime(int startAt, int moveCost, int pushCost, int targetSeconds) {
        int result = 0;
        int min1 = 10000000;
        int min2 = 10000000;
        int min3 = 10000000;
        int min4 = 10000000;
        if(targetSeconds < 10) {
            if (startAt == targetSeconds) 
                min1 = pushCost;
            else min1 = pushCost + moveCost;
            //cout << "min1" << min1 << endl;
        }
        if(targetSeconds < 100) {
            if (startAt == targetSeconds / 10 && targetSeconds / 10 == targetSeconds % 10) 
                min2 = pushCost * 2;
            else if ((startAt == targetSeconds / 10 && targetSeconds / 10 != targetSeconds % 10) || 
                     (startAt != targetSeconds / 10 && targetSeconds / 10 == targetSeconds % 10))
                min2 = pushCost * 2 + moveCost;
            else min2 = pushCost * 2 + moveCost * 2;
            //cout << "min2" << min2 << endl;
        }
        if(targetSeconds >= 60 && targetSeconds <= 9 * 60 + 99) {
            int minute1 = targetSeconds / 60;
            int second1 = targetSeconds % 60;
            int minute2 = targetSeconds / 60 - 1;
            int second2 = (targetSeconds % 60) + 60;
            if(minute2 == 0 || second2 > 100)
                min3 = caluteMin3(minute1, second1, startAt, moveCost, pushCost);
            else if(minute1 == 10)
                min3 = caluteMin3(minute2, second2, startAt, moveCost, pushCost);
            else min3 = minNum(caluteMin3(minute1, second1, startAt, moveCost, pushCost), caluteMin3(minute2, second2, startAt, moveCost, pushCost));
            //cout << "min3 " << min3 << endl;
        }
        if(targetSeconds >= 600) {
            int minute1 = targetSeconds / 60;
            int second1 = targetSeconds % 60;
            int minute2 = targetSeconds / 60 - 1;
            int second2 = (targetSeconds % 60) + 60;
            if(minute2 < 10 || second2 > 100)
                min4 = caluteMin4(minute1, second1, startAt, moveCost, pushCost);
            else if(minute1 > 99)
                min4 = caluteMin4(minute2, second2, startAt, moveCost, pushCost);
            else min4 = minNum(caluteMin4(minute1, second1, startAt, moveCost, pushCost), caluteMin4(minute2, second2, startAt, moveCost, pushCost));
            //cout << "min4 " << min4 << endl;
        }
        return minNum(min1,minNum(min2, minNum(min3, min4)));
    }
    
    int caluteMin3(int minute, int second, int startAt, int moveCost, int pushCost) {
        int min3 = 10000000;
        //cout << "cmin3 " << minute << " " << second << endl;
        if (startAt == minute && minute == second / 10 && second / 10 == second % 10) 
            min3 = pushCost * 3;
        else if ((startAt != minute && minute == second / 10 && second / 10 == second % 10) || 
                 (startAt == minute && minute == second / 10 && second / 10 != second % 10) || 
                 (startAt == minute && minute != second / 10 && second / 10 == second % 10)) 
            min3 = pushCost * 3 + moveCost;
        else if((startAt != minute && minute == second / 10 && second / 10 != second % 10) || 
                (startAt == minute && minute != second / 10 && second / 10 != second % 10) || 
                (startAt != minute && minute != second / 10 && second / 10 == second % 10))
            min3 = pushCost * 3 + moveCost * 2;
        else min3 = pushCost * 3 + moveCost * 3;
        //cout << "cmin3 " << min3 << endl;
        return min3;
    }
    int caluteMin4(int minute, int second, int startAt, int moveCost, int pushCost) {
        int min4 = 10000000;
        //cout << "cmin4 " << minute << " " << second << endl;
        if (startAt == minute / 10 && minute / 10 == minute % 10 && minute % 10 == second / 10 && second / 10 == second % 10) 
            min4 = pushCost * 4;
        else if ((startAt != minute / 10 && minute / 10 == minute % 10 && minute % 10 == second / 10 && second / 10 == second % 10) || 
                 (startAt == minute / 10 && minute / 10 != minute % 10 && minute % 10 == second / 10 && second / 10 == second % 10) || 
                 (startAt == minute / 10 && minute / 10 == minute % 10 && minute % 10 != second / 10 && second / 10 == second % 10) || 
                 (startAt == minute / 10 && minute / 10 == minute % 10 && minute % 10 == second / 10 && second / 10 != second % 10)) 
            min4 = pushCost * 4 + moveCost;
        else if((startAt != minute / 10 && minute / 10 != minute % 10 && minute % 10 == second / 10 && second / 10 == second % 10) || 
                (startAt != minute / 10 && minute / 10 == minute % 10 && minute % 10 != second / 10 && second / 10 == second % 10) || 
                (startAt != minute / 10 && minute / 10 == minute % 10 && minute % 10 == second / 10 && second / 10 != second % 10) || 
                (startAt == minute / 10 && minute / 10 != minute % 10 && minute % 10 != second / 10 && second / 10 == second % 10) || 
                (startAt == minute / 10 && minute / 10 != minute % 10 && minute % 10 == second / 10 && second / 10 != second % 10) || 
                (startAt == minute / 10 && minute / 10 == minute % 10 && minute % 10 != second / 10 && second / 10 != second % 10))
            min4 = pushCost * 4 + moveCost * 2;
        else if (startAt != minute / 10 && minute / 10 != minute % 10 && minute % 10 != second / 10 && second / 10 != second % 10)
            min4 = pushCost * 4 + moveCost * 4;
        else min4 = pushCost * 4 + moveCost * 3;
        //cout << "cmin4 " << min4 << endl;
        return min4;
    }
};
// @lc code=end

