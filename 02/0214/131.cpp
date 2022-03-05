/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

/* 算法思想
 * 状态编码
 * 一个长度为 n 的字符串，可以在 n - 1 处划分，而且 n 最长为 16，因此，我们可以使用状态编码
 * 列举各种分割，并判断这种分割是否可行。
 */
class Solution {
public:
    bool isPalindrome(string s, int start, int end) {
        while(start < end) {
            if(s[start] != s[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ret;
        int n = s.size();
        for(int i = 0; i < (1 << (n - 1)); i++) {
            int last = 0;
            vector<string> temp;
            int ok = 1;
            for(int j = 0; j < n - 1; j++) {
                if (i & (1 << j)) {
                    if(isPalindrome(s, last, j)) {
                        temp.push_back(s.substr(last, j - last + 1));
                        last = j + 1;
                        
                    } else {
                        ok = 0;
                        break;
                    }
                }
            }
            if(ok && isPalindrome(s, last, s.size() - 1)) {
                temp.push_back(s.substr(last));
                ret.push_back(temp);
            }

        }
        return ret;
    }
};


/* 算法思想
 * 假设我们当前搜索到字符串的第 i 个字符，且 s[0..i-1] 位置的所有字符已经被分割成若干个回文串，
 * 并且分割结果被放入了答案数组 ans 中，那么我们就需要枚举下一个回文串的右边界 j，使得 s[i..j]是一个回文串。
 * 因此，我们可以从 i 开始，从小到大依次枚举 j。
 *  对于当前枚举的 j 值，我们使用双指针的方法判断 s[i..j] 是否为回文串：
 *      如果 s[i..j]s[i..j] 是回文串，那么就将其加入答案数组 ans 中，并以 j+1 作为新的 i 进行下一层搜索，
 *  并在未来的回溯时将 s[i..j] 从 ans 中移除。
 *      如果我们已经搜索完了字符串的最后一个字符，那么就找到了一种满足要求的分割方法。 
 */

/* TIPS：
 * 当我们在判断 s[i..j] 是否为回文串时，常规的方法是使用双指针分别指向 i 和 j，
 * 每次判断两个指针指向的字符是否相同，直到两个指针相遇。然而这种方法会产生重复计算，
 * 因此，我们可以将字符串 s 的每个子串 s[i..j] 是否为回文串预处理出来，使用动态规划即可。
 */

class SolutionOTHERS {
private:
    vector<vector<int>> f;
    vector<vector<string>> ret;
    vector<string> ans;
    int n;

public:
    void dfs(const string& s, int i) {
        if (i == n) {
            ret.push_back(ans);
            return;
        }
        for (int j = i; j < n; ++j) {
            if (f[i][j]) {
                ans.push_back(s.substr(i, j - i + 1));
                dfs(s, j + 1);
                ans.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        n = s.size();
        f.assign(n, vector<int>(n, true));

        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                f[i][j] = (s[i] == s[j]) && f[i + 1][j - 1];
            }
        }

        dfs(s, 0);
        return ret;
    }
};
