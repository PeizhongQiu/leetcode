/*
 * @lc app=leetcode.cn id=1380 lang=cpp
 *
 * [1380] 矩阵中的幸运数
 */

#define MAX_DATA 100001
class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> ret;
        for(int i = 0; i < matrix.size(); i++) {
            int minLine = 100001;
            int minLineId = 0;
            for(int j = 0; j < matrix[i].size(); j++) {
                if(minLine >  matrix[i][j]) {
                    minLine = matrix[i][j];
                    minLineId = j;
                }
            }
            int ok = 1;
            for(int j = 0; j < matrix.size(); j++) {
                if(matrix[j][minLineId]  > matrix[i][minLineId]) {
                    ok = 0;
                    break;
                }
            }
            if(ok) ret.push_back(matrix[i][minLineId]);

        }

        return ret;
    }
};

/* TIPS:
 * 要善于利用algorithm里的函数
 * 由于每个元素互不相同，可以先计算每行最小值和每列的最大值，
 * 最后当两者相同的即为答案 
 */

class SolutionOTHERS {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n=matrix.size(), m=matrix[0].size();
        vector<int> res,mi(n,INT_MAX),mm(m,INT_MIN);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                mi[i]=min(mi[i],matrix[i][j]);
                mm[j]=max(mm[j],matrix[i][j]);
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mi[i]==mm[j])
                {
                    res.push_back(mi[i]);
                    break;
                }
            }
        }
        return res;
    }
};