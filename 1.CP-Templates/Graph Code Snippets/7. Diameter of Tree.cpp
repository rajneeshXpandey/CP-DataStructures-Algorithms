// Diameter of a tree in Detail

void endPoint(vector<vector<int>> &adj, vector<bool> &visited, vector<int> &endNodes, int root, int distance)
{
    visited[root] = 1;
    if (dis == maxDis){
        endNodes[root] = 1;
    }
    for (auto child : adj[root]){
        if (!visited[child]){
            endPoint(adj, visited, child, distance + 1);
        }
    }
}

void Diameter(vector<vector<int>> &adj, vector<bool> &visited, vector<int> &maxDisNode,int &node,int root, int distance)
{
    visited[root] = 1;
    if (distance > maxDis)
    {
        maxDis = distance;
        node = root;
        maxDisNode[root] = 1;
    }
    for (auto child : adj[root])
    {
        if (!visited[child]){
            Diameter(child, distance + 1);
        }
    }
}

maxDis = -1;
Diameter(adj,visited,maxDisNode,node,1,0);
// never forgot to clear visited arr before another dfs
maxDis = -1;
for (int i = 0; i < n + 1; i++)
    visited[i] = 0;
Diameter(node, 0);
for (int i = 1; i <= n; i++)
{
    for (int i = 0; i < n + 1; i++)
        visited[i] = 0;
    if (maxDisNode[i])
    {
        endPoint(adj,visited,endNodes,i, 0);
    }
}
