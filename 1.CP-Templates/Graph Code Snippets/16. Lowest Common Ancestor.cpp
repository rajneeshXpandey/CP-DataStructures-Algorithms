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