// Topological Sorting of Directed graph

/* valid iff no cycle is present -> DAG */

vector<int> topoSort(vector<vector<int>> &adj, vector<bool> &visited, vector<int> &inDegree, int N)
{
    vector<int> result;
    // min heap
    priority_queue<int, vector<int>, greater<int>> min_heap;

    for (int i = 0; i < N; i++){
        if (inDegree[i] == 0)
            min_heap.push(i);
    }

    while (!min_heap.empty())
    {
        int node = min_heap.top();
        min_heap.pop();
        // cout<<node<<" ";
        result.pb(node);
        for (auto child : adj[node]){
            inDegree[child]--;
            if (inDegree[child] == 0)
                min_heap.push(child);
        }
    }
    //if(result.size()==N) // valid topo sort
    return result;
}
