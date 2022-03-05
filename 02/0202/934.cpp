/*
 * @lc app=leetcode.cn id=934 lang=cpp
 *
 * [934] 最短的桥
 *
 * https://leetcode-cn.com/problems/shortest-bridge/description/
 *
 * algorithms
 * Medium (47.25%)
 * Likes:    224
 * Dislikes: 0
 * Total Accepted:    27.8K
 * Total Submissions: 58.8K
 * Testcase Example:  '[[0,1],[1,0]]'
 *
 * 在给定的二维二进制数组 A 中，存在两座岛。（岛是由四面相连的 1 形成的一个最大组。）
 * 
 * 现在，我们可以将 0 变为 1，以使两座岛连接起来，变成一座岛。
 * 
 * 返回必须翻转的 0 的最小数目。（可以保证答案至少是 1 。）
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：A = [[0,1],[1,0]]
 * 输出：1
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：A = [[0,1,0],[0,0,0],[0,0,1]]
 * 输出：2
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：A = [[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
 * 输出：1
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 2 
 * A[i][j] == 0 或 A[i][j] == 1
 * 
 * 
 */

/* 算法思想：
 * 首先使用 DFS 确定两片陆地，之后用 BFS 来确定两片陆地的距离。 
 */

class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        pair <int, int> LocationOfRootOfFirstLand;
        int n = grid.size();
        queue<pair<int, int>> FirstLand;
        //cout << "DFS" << endl;
        for(int i = 0; i < n; i++){
            int ok = 0;
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    LocationOfRootOfFirstLand.first = i;
                    LocationOfRootOfFirstLand.second = j;
                    grid[i][j] = 2;
                    FirstLand.push(LocationOfRootOfFirstLand);
                    //cout << LocationOfRootOfFirstLand.first << " " << LocationOfRootOfFirstLand.second << endl;
                    ok = 1;
                    break;
                }
            }
            if(ok == 1) break;
        }
        DFS(grid, FirstLand, LocationOfRootOfFirstLand);
        //cout << "BFS" << endl;
        int result = BFS(grid, FirstLand);
        return result;
    }
    
    void DFS(vector<vector<int>>& grid, queue<pair<int, int>>& FirstLand, pair <int, int> CurrentLocation) {
        if(CurrentLocation.first > 0 && grid[CurrentLocation.first - 1][CurrentLocation.second] == 1){
            FirstLand.push({CurrentLocation.first - 1, CurrentLocation.second});
            grid[CurrentLocation.first - 1][CurrentLocation.second] = 2;
            //cout << CurrentLocation.first - 1 << "a" << CurrentLocation.second << endl;
            DFS(grid, FirstLand, {CurrentLocation.first - 1, CurrentLocation.second});
        }
        if(CurrentLocation.first < grid.size() - 1 && grid[CurrentLocation.first + 1][CurrentLocation.second] == 1){
            FirstLand.push({CurrentLocation.first + 1, CurrentLocation.second});
            grid[CurrentLocation.first + 1][CurrentLocation.second] = 2;
            //cout << CurrentLocation.first + 1 << "b" << CurrentLocation.second << endl;
            DFS(grid, FirstLand, {CurrentLocation.first + 1, CurrentLocation.second});
        }
        if(CurrentLocation.second > 0 && grid[CurrentLocation.first][CurrentLocation.second - 1] == 1){
            FirstLand.push({CurrentLocation.first, CurrentLocation.second - 1});
            grid[CurrentLocation.first][CurrentLocation.second - 1] = 2;
            //cout << CurrentLocation.first << "c" << CurrentLocation.second - 1 << endl;
            DFS(grid, FirstLand, {CurrentLocation.first, CurrentLocation.second - 1});
        }
        if(CurrentLocation.second < grid.size() - 1 && grid[CurrentLocation.first][CurrentLocation.second + 1] == 1){
            FirstLand.push({CurrentLocation.first, CurrentLocation.second + 1});
            grid[CurrentLocation.first][CurrentLocation.second + 1] = 2;
            //cout << CurrentLocation.first << "d" << CurrentLocation.second + 1 << endl;
            DFS(grid, FirstLand, {CurrentLocation.first, CurrentLocation.second + 1});
        }
    }
    
    int BFS(vector<vector<int>>& grid, queue<pair<int, int>>& FirstLand){
        int step = 0;
        int result = 0;
        int length = FirstLand.size();
        while(!FirstLand.empty()){
            pair<int, int> temp = FirstLand.front();
            FirstLand.pop();
            ++step;
            
            //cout << step << " " << length << " " << result << endl;
            if(temp.first > 0 && grid[temp.first - 1][temp.second] == 0){
                grid[temp.first - 1][temp.second] = 2;
                FirstLand.push({temp.first - 1, temp.second});
                //cout << temp.first - 1 << " " << temp.second << endl;
            }
            else if(temp.first > 0 && grid[temp.first - 1][temp.second] == 1) 
                break;
            
            if(temp.first < grid.size() - 1 && grid[temp.first + 1][temp.second] == 0){
                grid[temp.first + 1][temp.second] = 2;
                FirstLand.push({temp.first + 1, temp.second});
                //cout << temp.first + 1 << " " << temp.second << endl;
            }
            else if(temp.first < grid.size() - 1 && grid[temp.first + 1][temp.second] == 1)
                break;
            
            if(temp.second > 0 && grid[temp.first][temp.second - 1] == 0){
                grid[temp.first][temp.second - 1] = 2;
                FirstLand.push({temp.first, temp.second - 1});
                //cout << temp.first << " " << temp.second - 1 << endl;
            }
            else if(temp.second > 0 && grid[temp.first][temp.second - 1] == 1) 
                break;
            
            if(temp.second < grid.size() - 1 && grid[temp.first][temp.second + 1] == 0){
                grid[temp.first][temp.second + 1] = 2;
                FirstLand.push({temp.first, temp.second + 1});
                //cout << temp.first << " " << temp.second + 1 << endl;
            }
            else if(temp.second < grid.size() - 1 && grid[temp.first][temp.second + 1] == 1)
                break;
            if(step == length) {
                step = 0;
                length = FirstLand.size();
                ++result;
            }
        }
        
        return result;
    }
};

