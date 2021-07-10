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

vector<int> *adj;
int *visited;
int *colors;

bool dfs(int root,int color)
{
    visited[root] = 1;
    colors[root] = color;
    for (auto nb : adj[root])
    {
        if (!visited[nb])
            {
                if(dfs(nb,!(color)) == false) 
                 return false;
            }
        else 
        {
            if(colors[root] == colors[nb])
             return false;
        }    
    }

    return true;
}

signed main()
{
        FIO;
        int n, e;
        cin >> n >> e;
        adj = new vector<int>[n + 1];
        visited = new int[n + 1];
        colors = new int[n + 1];

        for (int i = 0; i < e; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].pb(v);
            adj[v].pb(u);
        }

        if(dfs(1,0)==1)
         cout<<"YES"<<endl;
         else
         {
             cout<<"NO"<<endl;
         }
    return 0;
}