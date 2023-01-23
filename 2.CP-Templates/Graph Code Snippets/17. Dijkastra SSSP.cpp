// Dijkastra SSSP for weighted Graph

void Dijkastra(vector<vector<pii>> &adj,vector<int> &distance,vector<bool> &flag,int source,int v,int e){

    distance[source] = 0;
    // min_heap = {dis,node}
    priority_queue<pii, vector<pii>, greater<pii>> min_heap;

    min_heap.push({0, source});

    while (!min_heap.empty())
    {
        int currNode = min_heap.top().second;
        int currDis_from_source = min_heap.top().first;

        min_heap.pop();

        flag[currNode] = 1; // work of this node will be completed

        if (currDis_from_source > distance[currNode])
            continue;
        for (auto edge : adj[currNode])
        {
            if (!flag[edge.first] && (currDis_from_source + edge.second < distance[edge.first]))
            {
                distance[edge.first] = currDis_from_source + edge.second;
                min_heap.push({distance[edge.first], edge.first});
                /*
                    // store path in dijkarstra.
                        path[edge.first] = currNode; 
                */
            }
        }
    }

    for (int i = 1; i <= v; i++)
    {
        if (distance[i] == 0)
            continue;
        if (distance[i] == inf)
            cout << -1 << " ";
        else
            cout << distance[i] << " ";
    }
    cout << endl;
}

// function calling
vector<int> distance(v,inf);
vector<bool> flag(v,0);
Dijkastra(adj,distance,flag,source,v,e);
//edge:u->{v,wt}

//Restore Path
vector<int> restore_path(int s, int t, vector<int> const &path)
{
    vector<int> p;

    for (int v = t; v != s; v = path[v])
        p.push_back(v);
    p.push_back(s);

    reverse(p.begin(), p.end());
    return p;
}
