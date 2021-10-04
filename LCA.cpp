
/*
                                 LCA : (using binary lifting)      

        * dp[u][i] => ancestor of 'u' at distance '2^i' from 'u'

        * to find lca of 'x' number of node 
            find lca of x1 and x2
             lets   lca(x1,x2) = y
            then find lca of (x3,y) , (x4,y),.....(xx,y) 

        * Steps :                      
                                        /
                         v            lca    
                        /            /   \
                       x            .     .
                      /            /       \
                     u            .         v
                                 /
                                u 
               1) pre-compute dp[][] using :
                  dp[u][i] = dp[x][i-1] (assume 'v' to 'u' distance = 2^i)
                           = dp[dp[u][i-1]][i-1] (assume 'x' to 'u' distance = 2^(i-1))       
                2)level up the deeper node.
                3) from the max  ith jump start going nearer to the immediate children of lca
*/

int n;
int LN = log2(n);
vector<vector<int>> dp(n,vector<int>(LN)); 
vector<int> lvl(n,0);

void dfs(int u, int p)
{
    lvl[u] = lvl[p] + 1;
    dp[u][0] = p;
    for (int i = 1; i < LN; ++i)
        dp[u][i] = dp[dp[u][i - 1]][i - 1];
    for (int i = 0; i < adj[u].size(); ++i)
    {
        int v = adj[u][i];
        if (v == p)
            continue;
        dfs(v, u);
    }
}

int lca(int u, int v)
{
    if (lvl[u] < lvl[v])
        swap(u, v);
    int diff = lvl[u] - lvl[v];
    for (int i = 0; i < LN; ++i)
    {
        if ((1 << i) & diff)
            u = dp[u][i];
    }
    if (u == v)
        return u;
    for (int i = LN - 1; i >= 0; --i)
    {
        if (dp[u][i] != dp[v][i])
        {
            u = dp[u][i];
            v = dp[v][i];
        }
    }
    return dp[u][0];
}