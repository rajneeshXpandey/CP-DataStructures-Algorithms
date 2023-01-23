// Check whether Undirected Graph has cycle or not using DFS

bool containsCycle(vector<vector<int>> &adj, vector<bool> &visited, int root,int parent){
    visited[root] = 1;
    for (auto child : adj[root])
    {
        if (!visited[child]){
            if (checkCycle(adj, visited, child, root) == true)
                return true;
        }
        else if(parent != child){
            return true;
        }
    }
    return false;
}
// calling
containsCycle(adj,visited,0,-1);
