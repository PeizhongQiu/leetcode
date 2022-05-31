class Solution {
public:
    bool valid(int startA, int startB, int length, int m, int n, vector<vector<int>>& row, vector<vector<int>>& line,vector<vector<int>>& grid) {
        if(startA + length > m || startB + length > n) {
            return false;
        }
        int cmp = row[startA+length][startB] - row[startA][startB];
        for(int i = 1; i < length; ++i) {
            if(row[startA+length][startB + i] - row[startA][startB + i] != cmp) {
                return false;
            } 
        }
        for(int i = 0; i < length; ++i) {
            if(line[startA + i][startB+length] - line[startA+i][startB] != cmp) {
                return false;
            } 
        }
        int sum = 0;
        for(int i = 0; i < length; ++i) {
            sum += grid[startA+i][startB+i];
        }
        if(sum != cmp) {
            return false;
        }
        sum = 0;
        for(int i = 0; i < length; ++i) {
            sum += grid[startA+i][startB+length - 1-i];
        }
        if(sum != cmp) {
            return false;
        }

        return true;
    }
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> row(m + 1, vector<int>(n,0));
        vector<vector<int>> line(m, vector<int>(n+1,0));
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                row[i+1][j] = row[i][j] + grid[i][j];
                line[i][j+1] = line[i][j] + grid[i][j];
            }
        }
        int ret = 1;
        int length = 2;
        while(length <= min(m,n)) {
            
            for(int i = 0; i < m; ++i) {
                for(int j = 0; j < n; ++j) {
                    if(valid(i,j,length,m,n,row,line,grid)) {
                        //cout << i << j << ret << endl;
                        ret = length;
                        break;
                    }
                }     
            }
            ++length;
        }
        return ret;
    }
};