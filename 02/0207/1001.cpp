/*
 * @lc app=leetcode.cn id=1001 lang=cpp
 *
 * [1001] 网格照明
 *
 * https://leetcode-cn.com/problems/grid-illumination/description/
 *
 * algorithms
 * Hard (45.08%)
 * Likes:    137
 * Dislikes: 0
 * Total Accepted:    18.2K
 * Total Submissions: 40.4K
 * Testcase Example:  '5\n[[0,0],[4,4]]\n[[1,1],[1,0]]'
 *
 * 在大小为 n x n 的网格 grid 上，每个单元格都有一盏灯，最初灯都处于 关闭 状态。
 * 
 * 给你一个由灯的位置组成的二维数组 lamps ，其中 lamps[i] = [rowi, coli] 表示 打开 位于 grid[rowi][coli]
 * 的灯。即便同一盏灯可能在 lamps 中多次列出，不会影响这盏灯处于 打开 状态。
 * 
 * 当一盏灯处于打开状态，它将会照亮 自身所在单元格 以及同一 行 、同一 列 和两条 对角线 上的 所有其他单元格 。
 * 
 * 另给你一个二维数组 queries ，其中 queries[j] = [rowj, colj] 。对于第 j 个查询，如果单元格 [rowj,
 * colj] 是被照亮的，则查询结果为 1 ，否则为 0 。在第 j 次查询之后 [按照查询的顺序] ，关闭 位于单元格 grid[rowj][colj]
 * 上及相邻 8 个方向上（与单元格 grid[rowi][coli] 共享角或边）的任何灯。
 * 
 * 返回一个整数数组 ans 作为答案， ans[j] 应等于第 j 次查询 queries[j] 的结果，1 表示照亮，0 表示未照亮。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 5, lamps = [[0,0],[4,4]], queries = [[1,1],[1,0]]
 * 输出：[1,0]
 * 解释：最初所有灯都是关闭的。在执行查询之前，打开位于 [0, 0] 和 [4, 4] 的灯。第 0 次查询检查 grid[1][1]
 * 是否被照亮（蓝色方框）。该单元格被照亮，所以 ans[0] = 1 。然后，关闭红色方框中的所有灯。
 * 
 * 第 1 次查询检查 grid[1][0] 是否被照亮（蓝色方框）。该单元格没有被照亮，所以 ans[1] = 0 。然后，关闭红色矩形中的所有灯。
 * 
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 5, lamps = [[0,0],[4,4]], queries = [[1,1],[1,1]]
 * 输出：[1,1]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：n = 5, lamps = [[0,0],[0,4]], queries = [[0,4],[0,1],[1,4]]
 * 输出：[1,1,0]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= n <= 10^9
 * 0 <= lamps.length <= 20000
 * 0 <= queries.length <= 20000
 * lamps[i].length == 2
 * 0 <= rowi, coli < n
 * queries[j].length == 2
 * 0 <= rowj, colj < n
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    static bool cmp(vector<int> a, vector<int> b) {
        if(a[0] != b[0]) return a[0] < b[0];
        else return a[1] < b[1];
    }
    struct pair_hash {
        template <class T1, class T2>
        std::size_t operator () (std::pair<T1, T2> const &pair) const {
            std::size_t h1 = std::hash<T1>()(pair.first);
            std::size_t h2 = std::hash<T2>()(pair.second);
            return h1 ^ h2;
        }
    };
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        unordered_map<int,int> row;
        unordered_map<int,int> line;
        unordered_map<int,int> diagonalPos;
        unordered_map<int,int> diagonalNeg;
        unordered_set<pair<int, int>, pair_hash> light;

        vector<int> result;

        for(int i = 0; i < lamps.size(); i++) {
            pair<int, int> temp = make_pair (lamps[i][0], lamps[i][1]);
            if(light.count(temp) == 0) {
                insert(row, lamps[i][0]);
                insert(line, lamps[i][1]);
                insert(diagonalPos, lamps[i][1] + lamps[i][0]);
                insert(diagonalNeg, lamps[i][1] - lamps[i][0]);
                light.insert(temp);
            }
            
        }

        for(int i = 0; i < queries.size(); i++){
            
            if(row.count(queries[i][0]) > 0 ||
            line.count(queries[i][1]) > 0 || 
            diagonalPos.count(queries[i][0] + queries[i][1]) > 0 || 
            diagonalNeg.count(queries[i][1] - queries[i][0]) > 0) {
                result.push_back(1);
                for(int j = 0; j < 9; j++) {
                    vector<int> temp = {queries[i][0] + j % 3 - 1, queries[i][1] + j / 3 - 1};
                    pair<int, int> tempLight = make_pair (queries[i][0] + j % 3 - 1, queries[i][1] + j / 3 - 1);

                    if(light.count(tempLight) > 0) {
                        --row[queries[i][0] + j % 3 - 1]; 
                        if(row[queries[i][0] + j % 3 - 1] == 0) {
                            row.erase(queries[i][0] + j % 3 - 1);
                        }
                        --line[queries[i][1] + j / 3 - 1]; 
                        if(line[queries[i][1] + j / 3 - 1] == 0) {
                            line.erase(queries[i][1] + j / 3 - 1);
                        }
                        --diagonalPos[queries[i][1] + j / 3 - 1 + queries[i][0] + j % 3 - 1];
                        if(diagonalPos[queries[i][1] + j / 3 - 1 + queries[i][0] + j % 3 - 1] == 0) {
                            diagonalPos.erase(queries[i][1] + j / 3 - 1 + queries[i][0] + j % 3 - 1);
                        } 
                        --diagonalNeg[queries[i][1] + j / 3 - queries[i][0] - j % 3]; 
                        if(diagonalNeg[queries[i][1] + j / 3 - queries[i][0] - j % 3] == 0) {
                            diagonalNeg.erase(queries[i][1] + j / 3 - queries[i][0] - j % 3);
                        }
                        light.erase(tempLight);
                    }
                }
            }
            else {
                result.push_back(0);
            }
            

        }
        return result;
    }
    void insert (unordered_map<int,int>& row, int key) {
        if(row.count(key) == 0) {
            row[key] = 1;
        } else {
            ++row[key];
        }
    }
};
// @lc code=end

