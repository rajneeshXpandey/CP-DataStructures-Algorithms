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


vector<int> *adj;
int *visited;

bool dfs(int root,int par)
{
    visited[root] = 1;
    for (auto nb : adj[root])
    {
        if(!visited[nb])
         {
             if(dfs(nb,root))
              return true;
         }
         else
         {
             if(nb!=par)
               return true;
         }        
    }
    return false;
}

signed main()
{
    FIO;
    int t=1;
    //cin >> t;
    while (t--)
    {
        int v, e;
        cin >> v >> e;

        adj = new vector<int>[v + 1];
        visited = new int[v+1];
        for (int i = 0; i < e; i++)
        {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        cout<<dfs(1,0)<<endl;
    }
    return 0;
}