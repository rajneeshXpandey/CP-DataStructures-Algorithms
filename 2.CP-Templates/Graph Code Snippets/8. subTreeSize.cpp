// Sub Tree Size on Trees using DFS

int subTreeSize(vector<vector<int>> &adj, vector<bool> &visited, vector<int> &subtreeSize, int root)
{
    visited[root] = 1;
    subtreeSize[root]=1;
    for (auto child : adj[root])
    {
        if (!visited[child])
            subtreeSize[root] += subTreeSize(adj, visited, subtreeSize, child);
    }
    return subtreeSize[root];
}

vector<int> subtreeSize(n,0);
subTreeSize(adj, visited, subtreeSize, 0);