                    /// ***** BFS (Breadth First Search) **** \\\

void bfs(vector<vector<int>> &adj, int root,int n)
{
    vector<bool> visited(n,0);
    queue<int> q;
    q.push(root);
    visited[root] = 1;
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        for (auto nb : adj[curr]){
            if (!visited[nb]){
                // Do some work
                q.push(nb);
                visited[nb] = 1;
            }
        }
    }
}

// Level wise BFS
void bfs_level(vector<vector<int>> &adj, int root, int n)
{
    vector<bool> visited(n, 0);
    queue<int> q;
    q.push(root);
    visited[root] = 1;
    while (!q.empty())
    {
        int sz = q.size();
        while (sz--)
        {
            int curr = q.front();
            q.pop();
            for (auto nb : adj[curr])
            {
                if (!visited[nb])
                {
                    // Do some work
                    q.push(nb);
                    visited[nb] = 1;
                }
            }
        }
    }
}


// multi sources BFS
void multisource_bfs(vector<vector<int>> &adj, vector<vector<int>> &mindis)
{
    queue<pii> q;
    int n = adj.size(), m = adj[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    // Push all the sources in the Queue
    for(int i=0,i<n;i++)
    {
        for(int j=0,j<m;j++)
        {
            if (adj[i][j] == 1)
            {
                mindis[i][j] = 0;
                q.push({i, j});
                visited[i][j] = true;
            }
        }
    }

    while (!q.empty())
    {
        auto u = q.front();
        q.pop();
        for(int i=0,i<4;i++)
        {
            int x = u.ff + dx[i], y = u.ss + dy[i];
            // performing operation w.r.t the sources
            if(isValid(x, y, n, m) and !visited[x][y] and adj[x][y] == 0)
            {
                mindis[x][y] = mindis[u.ff][u.ss] + 1;
                visited[x][y] = true;
                q.push({x, y});
            }
        }
    }
}

// 0-1 bfs

/*
Find shortest distance of each node from source node,
if the weights of edges can be either 0 or 1.

if some weights are not 0,1, then we can not use BFS.
then we will use dijkstra's algorithm.

a->b  weight 0 or 1
In queue
queue<int>q;
q.push(1); // back me push
q.pop(); // front se pop

dequeue<int>q; // important**
push_back(), push_front()
pop_back(), pop_front()

If weight of edge is 0
        -> push that in front becz process the nearest node first.
If weight of edge is 1-> push than in back
And the rest of the BFS remains the same.
Using this technique, we can find shortest distance.
This is called 0-1 BFS.

*/

void _0_1_bfs(vector<vector<pii>> &adj, vector<int> &mindis)
{

    deque<int> q;

    q.push_back(0);
    mindis[0] = 0;

    while (!q.empty())
    {
        auto u = q.front();
        q.pop_front();
        for (auto nb : adj[u]){
            if (mindis[nb.ff] > mindis[u] + nb.ss){
                if (nb.ss == 0){
                    q.push_front(nb.ff);
                }
                else{
                    q.push_back(nb.ff);
                }
                mindis[nb.ff] = mindis[u] + nb.ss;
            }
        }
    }
}