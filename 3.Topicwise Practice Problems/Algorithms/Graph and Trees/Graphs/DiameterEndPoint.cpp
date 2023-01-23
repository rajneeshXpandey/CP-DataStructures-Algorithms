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

void endPoint(int ,int);

vector<int> *adj;

int *visited;

int maxDis, *maxNode, node;

int *endNode;

void endPoint(int root, int dis)
{
    visited[root] = 1;
    if (dis == maxDis)
    {
        endNode[root] = 1;
    }
    for (auto nb : adj[root])
    {
        if (!visited[nb])
        {
            endPoint(nb, dis + 1);
        }
    }
}

void Diameter(int root, int dis)
{
    visited[root] = 1;
    if (dis > maxDis)
    {
        maxDis = dis;
        node = root;
        maxNode[root] = 1;
    }
    for (auto nb : adj[root])
    {
        if (!visited[nb])
        {
            Diameter(nb, dis + 1);
        }
    }
}


signed main()
{
    FIO;
    int tt = 1;
    //cin >> tt;
    while (tt--)
    {
        int n;
        cin >> n;

        adj = new vector<int>[n + 1];
        for (int i = 0; i < n; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        maxDis = -1;
        visited = new int[n + 1];
        maxNode = new int[n + 1];
        Diameter(1, 0);
        //never forgot to clear visited arr before anothe dfs
        maxDis = -1;
        for (int i = 0; i < n + 1; i++)
            visited[i] = 0;

        Diameter(node, 0);

        endNode = new int[n+1];
        for (int i = 1; i <=n ; i++)
        {
            for (int i = 0; i < n + 1; i++)
                visited[i] = 0;
            if(maxNode[i])
                {
                  endPoint(i, 0);
                }
        }
          
        for (int i = 1; i <=n; i++)
        {
            /* code */
            cout<<endNode[i]<<" ";
        }
        cout<<endl;
        
    }
    return 0;
}