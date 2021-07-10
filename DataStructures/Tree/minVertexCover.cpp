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

// at t=0 : root set to fire at every unit of time fire expands to its on neighbour
// find min time to burn all the nodes

int dp[10001][2];

void dfs(int root, int par, vector<int> adj[])
{
    dp[root][1] = 1; 
    dp[root][0] = 0; 

    for (auto nb : adj[root])
    {
        if (nb == par)
            continue;
        dfs(nb, root, adj);

     dp[root][1] += dp[nb][0];
     dp[root][0] += dp[nb][1]; 
     
   }
     
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

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0, adj);
    cout << min(dp[1][1],dp[1][0]);

    return 0;
}