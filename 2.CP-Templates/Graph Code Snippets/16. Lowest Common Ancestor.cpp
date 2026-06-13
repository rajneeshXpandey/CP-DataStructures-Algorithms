// Lowest Common Ancestor using Binary Lifting
// https://cp-algorithms.com/graph/lca_binary_lifting.html

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

void dfs(int v, int p, vector<vector<int>> &adj, vector<vector<int>> &up, vector<int> &lev)
{
    up[v][0] = p;
    if (p >= 0)
        lev[v] = lev[p] + 1;
    for (int i = 1; i <= 19; ++i)
        up[v][i] = (up[v][i - 1] >= 0) ? up[up[v][i - 1]][i - 1] : -1;
    for (int u : adj[v])
    {
        if (u != p)
            dfs(u, v, adj, up, lev);
    }
}
int lift_node(int node, int jump_required, vector<vector<int>> &up)
{
    for (int i = 19; i >= 0; i--)
    {
        if (node <= -1 || jump_required <= 0)
        {
            break;
        }
        if (jump_required >= (1 << i))
        {
            jump_required = jump_required - (1 << i);
            node = up[node][i];
        }
    }
    return node;
}
int lca(int u, int v, vector<vector<int>> &up, vector<int> &lev)
{
    if (lev[u] < lev[v])
        swap(u, v);

    u = lift_node(u, lev[u] - lev[v], up);
    if (u == v)
        return u;

    for (int i = 19; i >= 0; i--)
    {
        if (up[u][i] != up[v][i])
        {
            u = up[u][i];
            v = up[v][i];
        }
    }
    return lift_node(u, 1, up);
}

void solve()
{
    int n, q, v, u;
    cin >> n >> q;
    vector<vector<int>> adj(n), up(n, vector<int>(20, -1));
    vector<int> lev(n, 0);
    for (int i = 1; i < n; i++)
    {
        cin >> v;
        v--;
        adj[i].pb(v);
        adj[v].pb(i);
    }
    dfs(0, -1, adj, up, lev);
    forn(i, q)
    {
        cin >> u >> v;
        u--;
        v--;
        cout << lca(u, v, up, lev) + 1 << endl;
    }
}