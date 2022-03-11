/*
 * @lc app=leetcode.cn id=2049 lang=cpp
 *
 * [2049] 统计最高分的节点数目
 *
 * https://leetcode-cn.com/problems/count-nodes-with-the-highest-score/description/
 *
 * algorithms
 * Medium (40.07%)
 * Likes:    39
 * Dislikes: 0
 * Total Accepted:    6.8K
 * Total Submissions: 13.8K
 * Testcase Example:  '[-1,2,0,2,0]'
 *
 * 给你一棵根节点为 0 的 二叉树 ，它总共有 n 个节点，节点编号为 0 到 n - 1 。同时给你一个下标从 0 开始的整数数组 parents
 * 表示这棵树，其中 parents[i] 是节点 i 的父节点。由于节点 0 是根，所以 parents[0] == -1 。
 * 
 * 一个子树的 大小 为这个子树内节点的数目。每个节点都有一个与之关联的 分数 。求出某个节点分数的方法是，将这个节点和与它相连的边全部 删除
 * ，剩余部分是若干个 非空 子树，这个节点的 分数 为所有这些子树 大小的乘积 。
 * 
 * 请你返回有 最高得分 节点的 数目 。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 
 * 输入：parents = [-1,2,0,2,0]
 * 输出：3
 * 解释：
 * - 节点 0 的分数为：3 * 1 = 3
 * - 节点 1 的分数为：4 = 4
 * - 节点 2 的分数为：1 * 1 * 2 = 2
 * - 节点 3 的分数为：4 = 4
 * - 节点 4 的分数为：4 = 4
 * 最高得分为 4 ，有三个节点得分为 4 （分别是节点 1，3 和 4 ）。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 输入：parents = [-1,2,0]
 * 输出：2
 * 解释：
 * - 节点 0 的分数为：2 = 2
 * - 节点 1 的分数为：2 = 2
 * - 节点 2 的分数为：1 * 1 = 1
 * 最高分数为 2 ，有两个节点分数为 2 （分别为节点 0 和 1 ）。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == parents.length
 * 2 <= n <= 10^5
 * parents[0] == -1
 * 对于 i != 0 ，有 0 <= parents[i] <= n - 1
 * parents 表示一棵二叉树。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int getNodeNum(int node, int tree[][2], int num[])
    {
        if(num[node] != 0) return num[node];
        int sum = 0;
        if(tree[node][0] != 0) sum += getNodeNum(tree[node][0],tree,num);
        if(tree[node][1] != 0) sum += getNodeNum(tree[node][1],tree,num);
        return sum + 1;
    }
    int countHighestScoreNodes(vector<int>& parents) {
        int tree[parents.size()][2];
        memset(tree,0,sizeof(tree));
        for(int i = 0;i < parents.size(); i++)
        {
            if(parents[i]==-1)
                continue;
            else
            {
                if(tree[parents[i]][0] == 0)
                    tree[parents[i]][0] = i;
                else 
                    tree[parents[i]][1] = i;
            }
        }
        int num[parents.size()];
        memset(num,0,sizeof(num));
        for(int i = 0;i < parents.size(); i++)
        {
            num[i] = getNodeNum(i,tree,num);
        }
        long long max = 0;
        int count = 0;
        for(int i = 0;i < parents.size(); i++)
        {
            long long mul = 1;
            int all_sub_node = 1;
            if(tree[i][0] != 0) 
            {
                mul = mul * num[tree[i][0]];
                all_sub_node += num[tree[i][0]];
            }
            if(tree[i][1] != 0) 
            {
                mul = mul * num[tree[i][1]];
                all_sub_node += num[tree[i][1]];
            }
            if(all_sub_node != parents.size()) 
                mul = mul * (parents.size() - all_sub_node );
            
            if(max < mul)
            {
                max = mul; 
                count = 1;
            }
            else if(max == mul) count++;
        }
        return count;
    }
};
// @lc code=end

