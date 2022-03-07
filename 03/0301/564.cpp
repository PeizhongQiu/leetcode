/*
 * @lc app=leetcode.cn id=564 lang=cpp
 *
 * [564] 寻找最近的回文数
 *
 * https://leetcode-cn.com/problems/find-the-closest-palindrome/description/
 *
 * algorithms
 * Hard (18.44%)
 * Likes:    247
 * Dislikes: 0
 * Total Accepted:    21.9K
 * Total Submissions: 72.8K
 * Testcase Example:  '"123"'
 *
 * 给定一个表示整数的字符串 n ，返回与它最近的回文整数（不包括自身）。如果不止一个，返回较小的那个。
 * 
 * “最近的”定义为两个整数差的绝对值最小。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: n = "123"
 * 输出: "121"
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: n = "1"
 * 输出: "0"
 * 解释: 0 和 2是最近的回文，但我们返回最小的，也就是 0。
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 <= n.length <= 18
 * n 只由数字组成
 * n 不含前导 0
 * n 代表在 [1, 10^18 - 1] 范围内的整数
 * 
 * 
 */

// @lc code=start

class Solution {
public:
    string nearestPalindromic(string n) {
        string ret = "";
        bool isPalindromic = true;
        for(int i = 0; i < n.size() / 2; i++) {
            if(n[i] != n[n.size() - i - 1]) {
                isPalindromic = false;
                break;
            }
        }
        long long num = atoll(n.c_str());
        string left = n.substr(0, (n.size()+1)/2);
        long long candidate[5];
        string temp = left;
        for(int i = 0; i < n.size()/2; i++) {
            temp += temp[n.size()/2-i-1];
        }
        candidate[0] = atoll(temp.c_str());
        string leftPlusOne = to_string(atoll(left.c_str()) + 1);
        temp = leftPlusOne;
        if(leftPlusOne.size() > left.size()) {
            temp.resize(n.size()+1,0);
            temp[n.size()] = '1';
        } else {
            for(int i = 0; i < n.size()/2; i++) {
                temp += temp[n.size()/2-i-1];
            }
        }
        candidate[1] = atoll(temp.c_str());
        string leftMinusOne = to_string(atoll(left.c_str()) - 1);
        temp = leftMinusOne;
        if(leftMinusOne.size() < left.size()) {
            for(int i = 0; i < n.size() - 1; ++i) {
                temp[i] = '9';
            }
            temp[n.size()-1] = '\0';
        } else {
            for(int i = 0; i < n.size()/2; i++) {
                temp += temp[n.size()/2-i-1];
            }
        }
        candidate[2] = atoll(temp.c_str());
        temp = "1";
        for(int i = 1; i < n.size(); i++) {
            temp += '0';
        }
        temp += '1';
        candidate[3] = atoll(temp.c_str());
        temp = "";
        for(int i = 0; i < n.size()-1; i++) {
            temp += '9';
        }
        
        candidate[4] = atoll(temp.c_str());
        
        long long closestVal = num;
        int index = 0;
        for(int i = 0; i < 5; ++i){
            //cout << num << " " << candidate[i] << " " << index << endl;
            if(num != candidate[i] && (closestVal > abs(num - candidate[i]) || (closestVal == abs(num - candidate[i]) && candidate[i] < candidate[index]))) {
                closestVal = abs(num - candidate[i]);
                index = i;
            }
        }
        
        
        return to_string(candidate[index]);
    }
};
// @lc code=end

