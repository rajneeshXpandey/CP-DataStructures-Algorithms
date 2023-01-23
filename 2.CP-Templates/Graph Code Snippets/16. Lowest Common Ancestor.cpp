// Lowest Common Ancestor using Binary Lifting

void dfs(vector<vector<int>> &adj,vector<int> &level,vector<int> &parent,int root,int par)
{
    dp[root][0] = parent;
    // cout<<root<<" ";
    level[root] = 1 + ((par==-1)?0:level[par]);
    parent[root] = par;
    for (auto child : adj[root])
    {
        if (child != par)
            dfs(adj,child,root);
    }
}

void initialize(vector<vector<int>> &adj, int n, int maxN)
{
    dfs(adj,level,parent,0,-1);
    for (int j = 1;j<maxN; j++)
    {
        for (int i = 0;i<n; i++)
        {
            // if prev 2^(j-1) parent exist
            if (dp[i][j - 1] != -1){
                int par = dp[i][j - 1];
                dp[i][j] = dp[par][j - 1];
            }
        }
    }
}

int LCA(int u, int v, vector<int> adj[], int n, int maxN)
{
    if (level[u] < level[v])
        swap(u, v);

    int diff_level = (level[u] - level[v]);

    while (diff_level)
    {
        int i = log2(diff_level);
        u = dp[u][i];
        diff_level -= (1 << i);
    }
    if (u == v)
        return u;
    // to make it search in logN time
    for (int i = maxN; i >= 0; i--)
    {
        if ((dp[u][i] != -1) and (dp[u][i] != dp[v][i])) // must exist and have diff par
        {
            u = dp[u][i];
            v = dp[v][i];
        }
    }
    return parent[u];
}

// function calling
int maxN = log2(n);
initialize();
LCA();


/* More Details */

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
// take 'n' and adj as input
int n;
int LN = log2(n);
vector<vector<int>> dp(n, vector<int>(LN));
vector<int> lvl(n, 0);

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