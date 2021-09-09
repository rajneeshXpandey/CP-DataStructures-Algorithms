/*
 * @lc app=leetcode id=834 lang=cpp
 *
 * [834] Sum of Distances in Tree
 */

// @lc code=start
class Solution {
public:
    pair<int, int> dfs(vector<vector<int>> &adj, vector<int> &visi, vector<int> &subtree, int root, int &sum)
    {
        int sz = 0;
        int subsum = sum;
        sum++;
        visi[root] = 1;
        for (auto child : adj[root])
        {
            if (!visi[child])
            {
                auto vals = dfs(adj, visi, subtree, child, sum);
                sz += vals.first;
                subsum += vals.second;
            }
        }
        sum--;
        subtree[root] = 1 + sz;
        return {subtree[root], subsum};
    }
    void SumDist(vector<vector<int>> &adj, vector<int> &visi, vector<int> &subtree, vector<int> &ans, int n, int root, int par)
    {
        /* By every change in reference of nodes shifting happens*/
        if (root != 0)
            ans[root] = ans[par] - subtree[root] + n - subtree[root];
        visi[root] = 1;
        for (auto child : adj[root])
        {
            if (!visi[child])
            {
                SumDist(adj, visi, subtree, ans, n, child, root);
            }
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>> &edges)
    {

        vector<int> ans(n, 0), subtree(n, 0), visi(n, 0);
        vector<vector<int>> adj(n);

        for (auto edg : edges)
        {
            adj[edg[0]].push_back(edg[1]);
            adj[edg[1]].push_back(edg[0]);
        }

        int root = 0, sum = 0;
        auto rootans = dfs(adj, visi, subtree, root, sum);
        ans[root] = rootans.second;

        visi.clear();
        visi.resize(n, 0);
        SumDist(adj, visi, subtree, ans, n, 0, -1);

        return ans;
    }
};
// @lc code=end

