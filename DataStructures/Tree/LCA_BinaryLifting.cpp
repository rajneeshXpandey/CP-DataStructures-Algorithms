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


int dp[1025][11];

int *level;
int *parent;

void dfs(int root, int par, vector<int> adj[])
{
    dp[root][0] = par;
    //cout<<root<<" ";
    level[root] = 1 + level[par];
    parent[root] = par;
    for (auto nb : adj[root])
    {
        if (nb == par)
            continue;
        dfs(nb, root, adj);
    }
}

void init(vector<int> adj[],int n,int maxN)
{
    dfs(1,0,adj);

    for (int j = 1; j <= maxN; j++)
    {
        for (int i = 1; i <= n; i++)
            {
                // if prev 2^(j-1) parent exist
                if (dp[i][j - 1] != -1)
                {
                    int par = dp[i][j - 1];
                    dp[i][j] = dp[par][j - 1];
                }
            }
       
    }
    
}

int LCA(int u,int v,vector<int> adj[], int n, int maxN)
{
      if(level[u] < level[v]) 
         swap(u,v);

      int diff_level = (level[u] - level[v]);

      while(diff_level)
      {
          int i = log2(diff_level);
          u = dp[u][i];
          diff_level -= (1<<i); 
      }
      if(u==v) return u;
      // to make it search in logN time
      for (int i = maxN; i >=0; i--)
      {
          if((dp[u][i]!=-1) and (dp[u][i]!=dp[v][i]))
            {
                u = dp[u][i];
                v = dp[v][i];
            }
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
    int  maxN = log2(n);
    memset(dp,-1,sizeof(dp));
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    init(adj, n, maxN);

    // for (int i = 0; i <= n; i++)
    // {
    //         for (int j = 0; j <= maxN; j++)
    //         {
    //             cout << dp[i][j] << "\t";
    //     }
    //   cout<<endl;
    // }

    cout << "LCA of u and v : " << endl;
    cout << LCA(8, 7, adj, n, maxN) << endl;
    cout << LCA(5, 6, adj, n, maxN) << endl;
    cout << LCA(8, 3, adj, n, maxN) << endl;

    return 0;
}