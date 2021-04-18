#include<bits/stdc++.h>
using namespace std;

//    cout << fixed << setprecision(10);
#define ff              first
#define ss              second
#define all(x)          (x).begin(), (x).end()
#define endl            "\n"
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define int             long long
#define pb              push_back
#define pii             pair<int,int>
#define setbits(x)      __builtin_popcountll(x)
#define zerbefone(x)    __builtin_ctzll(x)
#define pqmx            priority_queue<int> // maxheap
#define pqmn   priority_queue<int,vector<int>,greater<int>> //minheap
#define mod             1000000007
#define inf             100000000000000000 //1e17
#define Pi              acos(-1.0)
#define precise(x,y)    fixed<<setprecision(y)<<x
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());


int *visited;

void dfs(int root,vector<int> adj[])
{
    visited[root] = 1;

    for(auto nb : adj[root])
     {
         if(!visited[nb])
           dfs(nb,adj);
     }
}

int ConnectComp(vector<int> adj[],int n)
{
    int cc = 0;
    for (int i = 1; i <=n; i++)
    {
        if(!visited[i])
         {
             dfs(i,adj);
             cc++;
         }
    }

    return cc;
    
}


signed main()
{
    FIO;
    int tt = 1;
    //cin >> tt;
    while (tt--)
    {
       int n,e;
       cin>>n>>e;
       vector<int> adj[n+1];
       for (int i = 0; i < e; i++)
       {
           int u ,v;
           cin>>u>>v;
           adj[u].pb(v);
           adj[v].pb(u);
       }
      visited = new int[n+1];
      memset(visited,0,(n+1)*sizeof(int));

      cout<<ConnectComp(adj,n)<<endl;
    }
    return 0;
}