// Single Source Shortest Path on Trees using DFS

/* 
    Shortest path to every other nodes from given node
    this DFS will work only on Trees : (no cycle + n-1 edges + 1 CC) 
*/

void SingleSourceShortestPath(vector<vector<int>> &adj, vector<bool> &visited, int source,int dist)
{
    distance[source] = dist;
    visited[source] = 1;
    for (auto child : adj[source])
    {
        if (!visited[child])
            SingleSourceShortestPath(adj, visited, child, dist + 1);
    }
}
SingleSourceShortestPath(adj,visited,source,0)
// now the distance array will contain min distances from source node