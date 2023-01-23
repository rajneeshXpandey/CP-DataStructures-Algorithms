// Articulation Point and Bridges using DFS Tree Representation.

/*
dp(i) = highest level from below (upper most) ancestor any node in the subtree of  'i'  can reach.

dp(i) = min(dp(i), dp(j)).  at return time when j is children of node i.

level[i] -> similar to discovery_time[i]
dp[i] -> similar to low time of i
*/

void dfs(vector<vector<int>> &adj, vector<bool> &visited, vector<int> &level,vector<int> &dp, int node, int parent){
    
    visited[node] = 1;
    bool is_articulation = 0; // used for articulation points
    if (parent != -1)
        level[node] = level[parent] + 1;
    for (auto neighbour : adj[node])
    {
        if (neighbour == parent)
            continue;
        if (vis[neighbour]) // taking min from already visited level of neighbour
            dp[node] = min(dp[node], level[neighbour]);
        else
        {
            dfs(adj,visited,level,dp,neighbour, node);
            // at return time take min of the low time i.e DP[node] with neighbour
            dp[node] = min(dp[node], dp[neighbour]);
            if (dp[neighbour] > level[node]) // condition for backedge and articulation point
            {
                // edge s -> u is a bridge
                cout << node << " -> " << neighbour << '\n';
                is_articulation = 1;
            }
        }
    }
    // if ok is false then s is a articulation point
     if (is_articulation) cout << node << '\n';
}

// function calling 
level[0] = 0;
dp[0] = 0;
dfs(adj,visited,level,dp,0, -1);
