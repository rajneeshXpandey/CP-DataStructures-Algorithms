
void bfs_level(vector<int> adj[], int v)
{
    int visited[v];
    memset(visited, 0, sizeof(visited));
    queue<int> q;
    q.push(0);
    while (!q.empty())
    {
        int sz = q.size();
        while (sz--)
        {
            int curr = q.front();
            if (!visited[curr])
                cout << curr << " ";
            visited[curr] = 1;
            for (auto nb : adj[curr])
            {
                if (!visited[nb])
                    q.push(nb);
            }
            q.pop();
        }
        cout << endl;
    }
}
void bfs(vector<int> adj[], int v)
{
    int visited[v];
    memset(visited, 0, sizeof(visited));
    queue<int> q;
    q.push(0);
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        if (!visited[curr])
            cout << curr << " ";
        visited[curr] = 1;
        for (auto nb : adj[curr])
        {
            if (!visited[nb])
                q.push(nb);
        }
    }
}