#include <bits/stdc++.h>
using namespace std;

//    cout << fixed << setprecision(10);
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define endl "\n"
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define int long long
#define pb push_back
#define pii pair<int, int>
#define setbits(x) __builtin_popcountll(x)
#define zerbefone(x) __builtin_ctzll(x)
#define pqmx priority_queue<int>                            // maxheap
#define pqmn priority_queue<int, vector<int>, greater<int>> //minheap
#define mod 1000000007
#define inf 100000000000000000 //1e17
#define Pi acos(-1.0)
#define precise(x, y) fixed << setprecision(y) << x
#define FIO                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int *level;
int *parent;

// time: O(N) and space: O(N)
// not useful in case of queries


void dfs(int root, int par, vector<int> adj[])
{

    level[root] = 1 + level[par];
    parent[root] = par;
    //cout<<root<<" ";
    for (auto nb : adj[root])
    {
        if (nb == par)
            continue;
        dfs(nb, root, adj);
    }
}

int LCA(int u,int v,vector<int> adj[])
{
    if(level[u]<level[v])
     swap(u,v);
    
    int diff_level = level[u]-level[v];

    while(diff_level--)
      u = parent[u];

    if(u==v) return u;

    while(parent[u]!=parent[v])
    {
        u = parent[u];
        v = parent[v];
    } 

    return parent[u]; 

}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n; //number of nodes = n (1, 2 .....)
    // n-1 : number of edges
    vector<int> adj[n + 1];

    level = new int[n + 1];
    level[0] = 0;
    parent = new int[n + 1];

    // Declaring 2D matrix dynamically

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0, adj);
    cout << "Levels of nodes: " << endl;
    for (int i = 1; i < n + 1; i++)
    {
        cout << level[i] << " ";
    }
    cout << endl;
    cout << "Parents of nodes: " << endl;
    for (int i = 1; i < n + 1; i++)
    {
        cout << parent[i] << " ";
    }
    cout << endl;
    cout << "LCA of u and v : " << endl;
    cout<<LCA(8,7,adj)<<endl;
    cout << LCA(5, 6, adj) << endl;
    cout << LCA(8, 3, adj) << endl;
    return 0;
}