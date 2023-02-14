// Kosaraju's Algorithm for Strongly Connected Component

void dfs1(vector<vector<int>> &adj, vector<bool> &visited, vector<int> &order, int node)
{
    visited[node] = true;
    for (auto child : adj[node])
        if (!visited[child])
            dfs1(adj, visited, order, child);
    order.push_back(node);
}

void dfs2(vector<vector<int>> &adj_rev, vector<bool> &visited, vector<int> &component, int node)
{
    visited[node] = true;
    component.push_back(node);
    for (auto child : adj_rev[node])
        if (!visited[child])
            dfs2(adj_rev, visited, component, child);
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
            dfs1(adj, visited, order, i);
    visited.assign(n, false);
    reverse(order.begin(), order.end());
    for (auto v : order)
        if (!visited[v]){
            dfs2(adj_rev, visited, component, v);
            // ... processing component ...
            component.clear();
        }
}
