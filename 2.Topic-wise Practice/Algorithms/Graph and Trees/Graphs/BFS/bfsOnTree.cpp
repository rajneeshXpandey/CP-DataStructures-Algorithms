#include <bits/stdc++.h>
using namespace std;

void bfs(vector<int> adj[],int v)
{
    int visited[v];
    memset(visited,0,sizeof(visited));
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

void bfs_level(vector<int> adj[],int v)
  {
      int visited[v];
      memset(visited, 0, sizeof(visited));
      queue<int> q;
      q.push(0);
      while (!q.empty())
      { 
          int sz = q.size();
         while(sz--){
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

int main()
{

    int v, e;
    cin >> v >> e;

    vector<int> adj[v];
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cout << "-------BFS-------" << endl;
    bfs(adj,v);
    cout<<endl;
    cout<<"----Level BFS----"<<endl;
    bfs_level(adj, v);
    return 0;
}
