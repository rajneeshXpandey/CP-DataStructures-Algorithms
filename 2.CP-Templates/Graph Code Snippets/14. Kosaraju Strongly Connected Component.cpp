// Kosaraju's Algorithm for Strongly Connected Component

void dfs1(vector<vector<int>> &adj, vector<bool> &visited, vector<int> &order, int node)
{
    visited[node] = true;
    for (auto child : adj[node])
        if (!visited[child])
            dfs1(child);
    order.push_back(v);
}

void dfs2(vector<vector<int>> &adj_rev, vector<bool> &visited, vector<int> &order, int node)
{
    visited[node] = true;
    component.push_back(node);
    for (auto child : adj_rev[node])
        if (!visited[child])
            dfs2(u);
}

int main()
{
    int n;
    // ... read n ...
    vector<vector<int>> adj(n), adj_rev(n);
    vector<bool> visited;
    vector<int> order, component;
    for (;;){
        int a, b;
        // ... read next directed edge (a,b) ...
        adj[a].push_back(b);
        adj_rev[b].push_back(a);
    }
    visited.assign(n, false);
    for (int i = 0; i < n; i++)
        if (!visited[i])
            dfs1(i);
    visited.assign(n, false);
    reverse(order.begin(), order.end());
    for (auto v : order)
        if (!visited[v]){
            dfs2(v);
            // ... processing component ...
            component.clear();
        }
}
