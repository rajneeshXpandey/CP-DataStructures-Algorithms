// Connected Components in Undirected Graph

int CountConnectedComponents(vector<vector<int>> &adj, vector<bool> &visited, int root,int n)
{
    int connected_components = 0;
    for(int root=0;root<n;root++){
        if(!visited[root]){
            ConnectedComponents(adj, visited, root, n); // simple dfs on graph
            connected_components++;
        }
    }
    return connected_components;
}